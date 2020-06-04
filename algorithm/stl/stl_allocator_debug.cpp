#include <stdio.h>
#include <stdlib.h>
#include <iostream>


namespace sgi_stl_debug
{

	template <bool threads, int inst>
	class __default_alloc_template
	{

	private:

		enum { _ALIGN = 8 };  // 小型区块的上调边界
		enum { _MAX_BYTES = 128 }; // 小区区块的上限
		enum { _NFREELISTS = 16 }; // _MAX_BYTES/_ALIGN  free-list 的个数

		static size_t _S_round_up(size_t __bytes)
		{
			return (((__bytes)+(size_t)_ALIGN - 1) & ~((size_t)_ALIGN - 1));
		}

	private:
		union _Obj
		{
			union _Obj* _M_free_list_link;  // 利用联合体特点
			char _M_client_data[1];    /* The client sees this.        */
		};
	private:

		static _Obj* _S_free_list[_NFREELISTS];  // 维护 16 个空闲链表(free list)，初始化为0，即每个链表中都没有空闲数据块  

		//根据申请数据块大小找到相应空闲链表的下标，n 从 0 起算
		static  size_t _S_freelist_index(size_t __bytes)
		{
			return (((__bytes)+(size_t)_ALIGN - 1) / (size_t)_ALIGN - 1);
		}


		static void* _S_refill(size_t __n);
		static char* _S_chunk_alloc(size_t __size, int& __nobjs);

		static char* _S_start_free;  // 内存池起始位置。只在 _S_chunk_alloc() 中变化
		static char* _S_end_free;    // 内存池结束位置。只在 _S_chunk_alloc() 中变化
		static size_t _S_heap_size;



	public:

		static void* allocate(size_t __n)
		{
			void* __ret = 0;

			// 如果需求区块大于 128 bytes，就转调用第一级配置
			if (__n > (size_t)_MAX_BYTES)
			{
				__ret = malloc(__n);
			}
			else
			{

				_Obj** __my_free_list = _S_free_list + _S_freelist_index(__n);

				_Obj* __result = *__my_free_list;

				if (__result == 0)
				{
					__ret = _S_refill(_S_round_up(__n));
				}
				else
				{
					*__my_free_list = __result->_M_free_list_link;
					__ret = __result;
				}
			}

			return __ret;
		};


		static void deallocate(void* __p, size_t __n)
		{
			if (__n > (size_t)_MAX_BYTES)
			{
				delete[] __p; // 大于 128 bytes，就调用第一级配置器的释放
			}
			else
			{
				_Obj** __my_free_list = _S_free_list + _S_freelist_index(__n);   // 否则将空间回收到相应空闲链表（由释放块的大小决定）中  
				_Obj* __q = (_Obj*)__p;


				__q->_M_free_list_link = *__my_free_list;   // 调整空闲链表，回收数据块
				*__my_free_list = __q;
			}
		}

		static void* reallocate(void* __p, size_t __old_sz, size_t __new_sz);

	};


	/* We allocate memory in large chunks in order to avoid fragmenting     */
	/* the malloc heap too much.                                            */
	/* We assume that size is properly aligned.                             */
	/* We hold the allocation lock.                                         */
	// 从内存池中取空间
	template <bool __threads, int __inst>
	char* __default_alloc_template<__threads, __inst>::_S_chunk_alloc(size_t __size,
		int& __nobjs)
	{
		char* __result;
		size_t __total_bytes = __size * __nobjs;  // 需要申请空间的大小 
		size_t __bytes_left = _S_end_free - _S_start_free;  // 计算内存池剩余空间

		if (__bytes_left >= __total_bytes) {  // 内存池剩余空间完全满足申请
			__result = _S_start_free;
			_S_start_free += __total_bytes;
			return(__result);
		}
		else if (__bytes_left >= __size) {  // 内存池剩余空间不能满足申请，提供一个以上的区块
			__nobjs = (int)(__bytes_left / __size);
			__total_bytes = __size * __nobjs;
			__result = _S_start_free;
			_S_start_free += __total_bytes;
			return(__result);
		}
		else {                             // 内存池剩余空间连一个区块的大小都无法提供                      
			size_t __bytes_to_get =
				2 * __total_bytes + _S_round_up(_S_heap_size >> 4);
			// Try to make use of the left-over piece.
		// 内存池的剩余空间分给合适的空闲链表
			if (__bytes_left > 0) {
				_Obj** __my_free_list =
					_S_free_list + _S_freelist_index(__bytes_left);

				((_Obj*)_S_start_free)->_M_free_list_link = *__my_free_list;
				*__my_free_list = (_Obj*)_S_start_free;
			}
			_S_start_free = (char*)malloc(__bytes_to_get);  // 配置 heap 空间，用来补充内存池
			if (0 == _S_start_free) {  // heap 空间不足，malloc() 失败
				size_t __i;
				_Obj** __my_free_list;
				_Obj* __p;
				// Try to make do with what we have.  That can't
				// hurt.  We do not try smaller requests, since that tends
				// to result in disaster on multi-process machines.
				for (__i = __size;
					__i <= (size_t)_MAX_BYTES;
					__i += (size_t)_ALIGN) {
					__my_free_list = _S_free_list + _S_freelist_index(__i);
					__p = *__my_free_list;
					if (0 != __p) {
						*__my_free_list = __p->_M_free_list_link;
						_S_start_free = (char*)__p;
						_S_end_free = _S_start_free + __i;
						return(_S_chunk_alloc(__size, __nobjs));
						// Any leftover piece will eventually make it to the
						// right free list.
					}
				}
				_S_end_free = 0;	// In case of exception.
				_S_start_free = (char*)malloc(__bytes_to_get);  // 调用第一级配置器
				// This should either throw an
				// exception or remedy the situation.  Thus we assume it
				// succeeded.
			}
			_S_heap_size += __bytes_to_get;
			_S_end_free = _S_start_free + __bytes_to_get;
			return(_S_chunk_alloc(__size, __nobjs));  // 递归调用自己
		}
	}


	/* Returns an object of size __n, and optionally adds to size __n free list.*/
	/* We assume that __n is properly aligned.                                */
	/* We hold the allocation lock.                                         */
	template <bool __threads, int __inst>
	void*
		__default_alloc_template<__threads, __inst>::_S_refill(size_t __n)
	{
		int __nobjs = 20;
		// 调用 _S_chunk_alloc()，缺省取 20 个区块作为 free list 的新节点
		char* __chunk = _S_chunk_alloc(__n, __nobjs);
		_Obj** __my_free_list;
		_Obj* __result;
		_Obj* __current_obj;
		_Obj* __next_obj;
		int __i;

		// 如果只获得一个数据块，那么这个数据块就直接分给调用者，空闲链表中不会增加新节点
		if (1 == __nobjs) return(__chunk);
		__my_free_list = _S_free_list + _S_freelist_index(__n);  // 否则根据申请数据块的大小找到相应空闲链表  

		/* Build free list in chunk */
		__result = (_Obj*)__chunk;
		*__my_free_list = __next_obj = (_Obj*)(__chunk + __n);  // 第0个数据块给调用者，地址访问即chunk~chunk + n - 1  
		for (__i = 1; ; __i++) {
			__current_obj = __next_obj;
			__next_obj = (_Obj*)((char*)__next_obj + __n);
			if (__nobjs - 1 == __i) {
				__current_obj->_M_free_list_link = 0;
				break;
			}
			else {
				__current_obj->_M_free_list_link = __next_obj;
			}
		}
		return(__result);
	}

	template <bool threads, int inst>
	void* __default_alloc_template<threads, inst>::reallocate(void* __p,
		size_t __old_sz,
		size_t __new_sz)
	{
		void* __result;
		size_t __copy_sz;

		if (__old_sz > (size_t)_MAX_BYTES && __new_sz > (size_t)_MAX_BYTES) {
			return(realloc(__p, __new_sz));
		}
		if (_S_round_up(__old_sz) == _S_round_up(__new_sz)) return(__p);
		__result = allocate(__new_sz);
		__copy_sz = __new_sz > __old_sz ? __old_sz : __new_sz;
		memcpy(__result, __p, __copy_sz);
		deallocate(__p, __old_sz);
		return(__result);
	}



	// 静态成员变量的定义与初值设定
	template <bool __threads, int __inst>
	char* __default_alloc_template<__threads, __inst>::_S_start_free = 0;

	template <bool __threads, int __inst>
	char* __default_alloc_template<__threads, __inst>::_S_end_free = 0;

	template <bool __threads, int __inst>
	size_t __default_alloc_template<__threads, __inst>::_S_heap_size = 0;

	template <bool __threads, int __inst>
	typename __default_alloc_template<__threads, __inst>::_Obj*
		__default_alloc_template<__threads, __inst> ::_S_free_list[__default_alloc_template<__threads, __inst>::_NFREELISTS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
}


int main(int argc, char** argv)
{
	sgi_stl_debug::__default_alloc_template<false, 10> _alloc;

	char* addrs[5] = {};

	int len[5] = { 1,20,60, 80,150 };

	for (size_t i = 0; i < 5; i++)
	{
		addrs[i] = (char*)_alloc.allocate(len[i]);
	}

	for (size_t i = 0; i < 5; i++)
	{
		_alloc.deallocate( addrs[i], len[i]);
	}
	
}