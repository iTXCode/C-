#include"MD5.h"
#include<math.h>
#include<fstream>
MD5::MD5()
:_chunkByte(N)
{
	init();
	memset(_chunk,0,_chunkByte);
	 _totalByte =_lastByte = 0;
}
void MD5::init(){
	
	/*
	word A: 01 23 45 67
	word B: 89 ab cd ef
	word C: fe dc ba 98
	word D: 76 54 32 10
	*/
	// 初始化A,B,C,D
	_A = 0x67452301;
	_B = 0xefcdab89;
	_C = 0x98badcfe;
	_D = 0x10325476;
	size_t s[] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
		12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
		4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
		15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };
	memcpy(_sft,s,sizeof(s));

	//_k[i]  2^32*abs(sin(i))
	for (int i = 0; i < 64;++i){
		_k[i] = pow(2, 32)*abs(sin(i + 1));
		//_k[i] = pow(2.0, 32)*abs(sin(i + 1.0));
	}
}

void MD5::calculateMD5(size_t *chunk){
	size_t a = _A;
	size_t b = _B;
	size_t c = _C;
	size_t d = _D;
	//f表示哈希函数的返回值，g表示当前挪用那一块数据

	size_t g ,f;
	
	//64次变换，4轮操作，每一轮操作：16个子操作
	for (size_t i = 0; i < 64; ++i){
		if (i >= 0 && i < 16){
			f = F(b,c,d);
			g = i;
		}
			
		else if (i >= 16 && i < 32){
			f = G(b,c,d);
			g = (5 * i + 1) % 16;
		}
		else if (i >= 32 && i < 48){
			f = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		else {
			f = I(b, c, d);
			g = (7 * i) % 16;
		}
		/*
		I = I(b, c, d);
		d = c;
		c =b;
		b = b + shift((a + f + k[i] + chunk[g]), sft[i]);
		//a+ 哈希函数的返回值+k[i]+ 当前操作的数据块,循环移动的位数
		a = d;
		*/
		size_t dtmp = d;
		d = c;
		c = b;
		b = b + shiftLeftRotate(a + f + _k[i] + chunk[g], _sft[i]);
		a = dtmp;
	}
	//更新完之后将结果加到后面
	_A += a;
	_B += b;
	_C += c;
	_D += d;
}


void MD5::calculateMD5Final(){
	//_lastByte:< 64byte ,最后一块数据的大小
	unsigned char*p=_chunk + _lastByte;
	//填充位的前8bit位：1000 0000  0X80
	*p++ = 0x80;
	size_t  remainFillByte = _chunkByte - _lastByte - 1;
	if (remainFillByte < 8){
		memset(p,0,remainFillByte);
		calculateMD5((size_t *)_chunk);
		memset(_chunk,0,_chunkByte);
	}
	else{
		memset(p, 0, remainFillByte);
	}
	//最后的64bit存放原始文档的bit长度
	((unsigned long long*)_chunk)[7]=_totalByte * 8;
	calculateMD5((size_t*)_chunk);
}

/*
num=012345678 ---> 78 56 34 23 01
*/
std::string MD5::changeHex(size_t num){
	static std::string map="0123456789abcdef";
	std::string ret;
	std::string byteStr;
	for (int i = 0; i < 4; i++){
		byteStr = "";
		//刚开始每一个字节所对应的字符串是空的
		size_t b = (num >> (i * 8)) & 0xff;

		/*
		num=012345678 ---> 78 56 34 23 01
		*/
		for (int j = 0; j < 2; ++j){
			byteStr.insert(0, 1, map[b % 16]);
			b /= 16;
		}
		ret += byteStr;
	}
	return ret;
}
std::string MD5::getStringMD5(const std::string& str){

	if (str.empty())
		return "";
	else{
		unsigned char* pstr = (unsigned char *)str.c_str();
		size_t numChunk = str.size() / _chunkByte;
		for (size_t i = 0; i < numChunk; ++i){
			_totalByte += _chunkByte;
			calculateMD5((size_t *)(pstr + i*_chunkByte));
		}
		_lastByte = str.size() % _chunkByte;
		memcpy(_chunk, pstr + _totalByte, _lastByte);
		calculateMD5Final();
	}
	return changeHex(_A) + changeHex(_B) + changeHex(_C) + changeHex(_D);
}
std::string MD5::getFileMD5(const char* filename){
	std::ifstream fin(filename,std::ifstream::binary);
	if (fin.is_open()){
		while (fin.eof()){
			fin.read((char*) _chunk,_chunkByte);
			if (_chunkByte != fin.gcount())
				break;
			_totalByte += _chunkByte;
			calculateMD5((size_t*)_chunk);
		}
		_lastByte = fin.gcount();
		_totalByte += _lastByte;
		calculateMD5Final();
	}
	return changeHex(_A) + changeHex(_B) + changeHex(_C) + changeHex(_D);
}

