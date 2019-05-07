/*
* usage: ʵ��aes-128-cbc-pc���ܻ���ԭ��
* �ο���https://github.com/kokke/tiny-AES-c (����)
*       https://www.sohu.com/a/200488301_478315 (ԭ��)
*		https://blog.csdn.net/qq_28205153/article/details/55798628 (ԭ��)
*/

/*
	* aesʵ�����Ƿֿ���ܣ�ÿһ�����Կ����һЩ���������ܵ�ʱ����������
	* �����ķֿ飬ÿ��ĳ��Ⱥ���Կ�ĳ���һ��
	* ������ĵĳ��Ȳ�����Կ�ĳ���������������Ҫ���
	* ģʽ�����˲�ͬ�ֿ�֮��Ĺ�����ϵ

	* AES����һ�ν����ļ���Ϊ���ĵģ��Ǿ������ּ��ܵģ���ͬ��Կ����ʹ�õ�������һ��

	* ��ʼ��:(1�Σ�1��)
		*������Կ��AddRoundKey��
	* ��ͨ��:(N�Σ�4��)
		*�ֽڴ��棨SubBytes��
		*����λ��ShiftRows��
		*�л�����MixColumns��
		*������Կ��AddRoundKey��
	* ������:(1��)
		*�ֽڴ��棨SubBytes��
		*����λ��ShiftRows��
		*������Կ��AddRoundKey��
*/


#ifndef __aes_128_cbc_pcskpadding__
#define __aes_128_cbc_pcskpadding__

#include <cstdint>
#include <string>
using std::string;

namespace relax
{
	class aes_128_cbc_pcsk
	{
		static int encrypt(const string& strIn,const string& strIv,const string& strKey);
		static int decrypt(const string& strIn,const string& strIv,const string& strKey);
	};
}

#endif