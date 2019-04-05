/*
 * usage: 将一个ID进行混淆，例如1 ==>12217417566535467712 降低遍历抓取风险
 * 参考：https://gist.github.com/megayu/50a6741875148613e38dd58a0a6a0972
*/

#ifndef __RELAX_XOR_H__
#define __RELAX_XOR_H__

#include <cstdint>

namespace relax
{
	class CXor 
	{
	public:
		static uint32_t U32_DEFAULT_KEY ;
		static uint64_t	U64_DEFAULT_KEY ;

		static uint32_t convert32( uint32_t value, uint32_t key32 = CXor::U32_DEFAULT_KEY);
		static uint64_t convert64( uint64_t value, uint64_t key64 = CXor::U64_DEFAULT_KEY); 

	private:
		static uint32_t opaque32( uint32_t value,uint32_t key32 = CXor::U32_DEFAULT_KEY);
		static uint64_t opaque64( uint64_t value,uint64_t key64 = CXor::U64_DEFAULT_KEY);
	};

};


#endif