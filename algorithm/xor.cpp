#include "xor.h"

using relax::CXor;

uint32_t CXor::U32_DEFAULT_KEY = 0x123;		//����key
uint64_t CXor::U64_DEFAULT_KEY = 0x123456;	//����key

// ����value = AB������A��value�ĸ�32λ��B��value�ĵ�32λ
// ���opaque64Ϊf

// ��ôչ������
// convert64(value) = ( B ^ f( A ^ f(B) ) ) << 32 + A ^ f(B)
// ����newValue = convert64(value)������newValue = CD��ͬ��CΪ��32λ�ã�DΪ��32λ
// convert64(newValue) = ( D ^ f( C ^ f(D) ) ) << 32 + C ^ f(D)��ͬ��

// ��Ϊ C = ( B ^ f( A ^ f(B) ) ) , D = (A ^ f(B))
// convert64(newValue) = ((A^f(B))^f((B^f(A^f(B)))^f((A^f(B)))))<<32+(B^f(A^f(B)))^f((A^f(B)))
// ����E = ((A^f(B))^f((B^f(A^f(B)))^f((A^f(B))))), F=(B^f(A^f(B)))^f((A^f(B)))
// E = ((A^f(B))^f((B^f(A^f(B)))^f((A^f(B)))))
//   = A^ f(B)^ f(B^f(A^f(B))^f(A^f(B)))		//�����
//   = A^ f(B)^ f(B)							//�Է���
//   = A										//�Է���

// F=(B^f(A^f(B)))^f((A^f(B))) = B //�������Է���

//convert(convert(value)) = convert(convert(AB)) = convert64(newValue) = EF = AB

uint64_t CXor::convert64(const uint64_t value,uint64_t key64)
{
	uint64_t low   = (value & UINT32_MAX);						
	uint64_t high  = ((value >> 32) ^ opaque64(low,key64));		
	
	return (( low ^ opaque64(high,key64)) << 32)  |  high;	
}


uint64_t CXor::opaque64( uint64_t value,uint64_t key64)
{
	value = (( value ^ key64)+0x7669) * 0xEAAB121; //��������������˻���Ҫ����ͺ�
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
	value = (( value ^ key32)+0x79) * 0xE121; //��������������˻���Ҫ����ͺ�
	return (value >> (value & 0x7)) & UINT16_MAX;
}