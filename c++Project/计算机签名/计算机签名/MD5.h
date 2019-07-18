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
	//以4个字节(32位)为单位进行处理，
	//一共4论轮，每轮16次操作。经过64此操作
	void calculateMD5Final();
	//最后一块数据的填充
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
		//先左移n位，然后再右移32-n 位，两者再进行或运算
	}

private:
	size_t _A;
	size_t _B;
	size_t _C;
	size_t _D;

	size_t _k[N];
	//
	size_t _sft[N];
	//循环移动的位数

	const size_t _chunkByte;
	//每个运算所用的块的大下
	unsigned char _chunk[N];
	//存放块

	size_t _lastByte;
	unsigned long long _totalByte;
};