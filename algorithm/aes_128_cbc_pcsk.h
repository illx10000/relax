/*
* usage: 实现aes-128-cbc-pc加密基本原理
* 参考：https://github.com/kokke/tiny-AES-c (代码)
*       https://www.sohu.com/a/200488301_478315 (原理)
*		https://blog.csdn.net/qq_28205153/article/details/55798628 (原理)
*/

/*
	* aes实际上是分块加密，每一块和秘钥进行一些操作，解密的时候进行逆操作
	* 将明文分块，每块的长度和秘钥的长度一致
	* 如果明文的长度不是秘钥的长度整数倍，则需要填充
	* 模式描述了不同分块之间的关联关系

	* AES不是一次将明文加密为密文的，是经过多轮加密的，不同秘钥长度使用的轮数不一行

	* 初始轮:(1次，1步)
		*加轮密钥（AddRoundKey）
	* 普通轮:(N次，4步)
		*字节代替（SubBytes）
		*行移位（ShiftRows）
		*列混淆（MixColumns）
		*加轮密钥（AddRoundKey）
	* 最终轮:(1次)
		*字节代替（SubBytes）
		*行移位（ShiftRows）
		*加轮密钥（AddRoundKey）
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