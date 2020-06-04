#include "xor.h"

using relax::CXor;

uint32_t CXor::U32_DEFAULT_KEY = 0x123;		//任意key
uint64_t CXor::U64_DEFAULT_KEY = 0x123456;	//任意key

// 假设value = AB，其中A是value的高32位，B是value的低32位
// 标记opaque64为f

// 那么展开函数
// convert64(value) = ( B ^ f( A ^ f(B) ) ) << 32 + A ^ f(B)
// 假设newValue = convert64(value)，其中newValue = CD，同上C为高32位置，D为低32位
// convert64(newValue) = ( D ^ f( C ^ f(D) ) ) << 32 + C ^ f(D)；同上

// 因为 C = ( B ^ f( A ^ f(B) ) ) , D = (A ^ f(B))
// convert64(newValue) = ((A^f(B))^f((B^f(A^f(B)))^f((A^f(B)))))<<32+(B^f(A^f(B)))^f((A^f(B)))
// 假设E = ((A^f(B))^f((B^f(A^f(B)))^f((A^f(B))))), F=(B^f(A^f(B)))^f((A^f(B)))
// E = ((A^f(B))^f((B^f(A^f(B)))^f((A^f(B)))))
//   = A^ f(B)^ f(B^f(A^f(B))^f(A^f(B)))		//结合律
//   = A^ f(B)^ f(B)							//自反性
//   = A										//自反性

// F=(B^f(A^f(B)))^f((A^f(B))) = B //异或具有自反性

//convert(convert(value)) = convert(convert(AB)) = convert64(newValue) = EF = AB

uint64_t CXor::convert64(const uint64_t value,uint64_t key64)
{
	uint64_t low   = (value & UINT32_MAX);						
	uint64_t high  = ((value >> 32) ^ opaque64(low,key64));		
	
	return (( low ^ opaque64(high,key64)) << 32)  |  high;	
}


uint64_t CXor::opaque64( uint64_t value,uint64_t key64)
{
	value = (( value ^ key64)+0x7669) * 0xEAAB121; //任意的两个数，乘积不要溢出就好
	return (value >> (value & 0xF)) & UINT32_MAX;
}

uint32_t CXor::convert32(uint32_t value, uint32_t key32 )
{
	uint32_t low	= (value & UINT16_MAX);
	uint32_t high	= ((value >> 16) ^ opaque32(low,key32));

	return (( low ^ opaque32(high,key32)) << 16)  |  high;	
}

uint32_t CXor::opaque32(uint32_t value, uint32_t key32)
{
	value = (( value ^ key32)+0x79) * 0xE121; //任意的两个数，乘积不要溢出就好
	return (value >> (value & 0x7)) & UINT16_MAX;
}