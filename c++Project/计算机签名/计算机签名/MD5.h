#pragma  once
#define  N  64
#include <string>

class MD5
{
public:
	MD5();
	std::string getFileMd5(const char* filename);
	std::string getStringMd5(const std::string& str);

private:
	void init();

	void calculateMD5(size_t* chunk);
	//��4���ֽ�(32λ)Ϊ��λ���д���
	//һ��4���֣�ÿ��16�β���������64�˲���
	void calculateMD5Final();
	//���һ�����ݵ����
	std::string changeHex(size_t num);
	/*
	F(x, y, z) = (x & y) | ((~x) & z)
	G(x, y, z) = (x & z) | (y & (~z))
	H(x, y, z) = x ^ y ^ z
	I(x, y, z) = y ^ (x | (~z))
	*/


	size_t F(size_t x, size_t y, size_t z)
	{
		return (x & y) | ((~x) & z);
	}

	size_t G(size_t x, size_t y, size_t z)
	{
		return (x & z) | (y & (~z));
	}
	size_t H(size_t x, size_t y, size_t z)
	{
		return x ^ y ^ z;
	}
	size_t I(size_t x, size_t y, size_t z)
	{
		return y ^ (x | (~z));
	}

	size_t shiftLeftRotate(size_t num, size_t n)
	{
		return (num << n) | (num >> (32 - n));
		//������nλ��Ȼ��������32-n λ�������ٽ��л�����
	}

private:
	size_t _A;
	size_t _B;
	size_t _C;
	size_t _D;

	size_t _k[N];
	//
	size_t _sft[N];
	//ѭ���ƶ���λ��

	const size_t _chunkByte;
	//ÿ���������õĿ�Ĵ���
	unsigned char _chunk[N];
	//��ſ�

	size_t _lastByte;
	unsigned long long _totalByte;
};