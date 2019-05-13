/*
* usage: ʵ��aes-128-cbc-pc���ܻ���ԭ�����������������ڣ�����������ʹ��openssl������
* �ο���https://github.com/kokke/tiny-AES-c (����)
*       https://www.sohu.com/a/200488301_478315 
*		https://blog.csdn.net/qq_28205153/article/details/55798628 
*		https://github.com/matt-wu/AES
*       https://zhuanlan.zhihu.com/p/41716899
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

#define AES128_KEYLENBIT		128 //��Կ����bit
#define AES128_ROUND			10  //10����ͨ�ּ���
#define AES128_BLOCKLEN			16	//ÿ16byteҲ����128bit��Ϊһ��Block
#define AES128_KEYEXPANSIONS	176 //һ����176λ����չ�ֽ�;


namespace relax
{
	struct aes_128_ctx
	{
		uint8_t iv[AES128_BLOCKLEN];					//��ʼ������
		uint8_t keyExpansions[AES128_KEYEXPANSIONS];	//aes��չ��Կ
	};


	class aes_128_cbc_pcsk
	{
		static int initctx (aes_128_ctx& ctx,const uint8_t* iv,const uint8_t* key);
		static int encrypt (const aes_128_ctx& ctx,uint8_t* buff,uint32_t bufflen);
		static int decrypt (const aes_128_ctx& ctx,uint8_t* buff,uint32_t bufflen);
	};
}

#endif