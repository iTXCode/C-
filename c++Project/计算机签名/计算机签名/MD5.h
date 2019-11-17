#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#define N 64

class MD5{
public:
	// ���캯��
	MD5();
	// �����ļ�
	std::string getFiledMDd5(const char* filename);
	// �����ַ���
	std::string getStringMD5(const std::string& str);
private:
	void init();

	void calculateMD5Final();
	//����64�β�����ÿһ�ִ����ĸ��ֽ�(һ�����ݿ�)
	std::string changeHex(size_t num);


	size_t F(size_t x, size_t y, size_t z) {
		return (x & y) | ((~x) & z);
	}
	size_t G(size_t x, size_t y, size_t z) {
		return (x & z) | (y & (~z));
	}
	size_t H(size_t x, size_t y, size_t z) {
		return x ^ y ^ z;
	}
	size_t I(size_t x, size_t y, size_t z) {
		return y ^ (x | (~z));
	}

	size_t shiftLeftRotate(size_t num, size_t n) {
		return (num << n) | (num >> (32 - n));
		//ѭ������nλ
	}

	// ���� 64�ֲ���
	//ÿ�β������� 4 ���ֽ�
	void calculateMD5(size_t* chunk);

private:
	size_t _a;
	size_t _b;
	size_t _c;
	size_t _d;

	size_t _k[N];//���64��ֵ
	size_t _sft[N];//ѭ����λ(����ÿ���ƶ���λ��)
	size_t _lastByte;//���һ�ζ�ȡ�����ݿ��С

	const size_t _chunkByte; //ÿһ������
	unsigned char _chunk[N];
	unsigned long long _totalByte ;
};
