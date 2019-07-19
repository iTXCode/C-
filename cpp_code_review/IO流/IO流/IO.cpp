#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<fstream>
#include<string>


using namespace std;
struct Info{
	char ip[20];
	int port;
};

class Config{
public:
	Config(string filename)
		:_filename(filename)
	{}
	//按字节流读写(按内存形式读写(二进制) )
	void WriteBin(Info& info){
		ofstream fout(_filename.c_str());
		//输出流获取文件大小的方式
		
		
		
		fout.write((char *)&info, sizeof(info));
		//参数1：在&info开始的位置开始拿取内容
		//参数2：读取的大小，单位字节
		fout.seekp(0, ofstream::end);
		size_t ByteNum = fout.tellp();
		cout << "ByteNum:" << ByteNum << endl;
		fout.close();
	}
	
	void readBin(Info& info){
		ifstream fin(_filename.c_str());

		//输入流获取文件大小的方式
		//seekg:设置文件指针的位置
		fin.seekg(0,ifstream::end);
		//tellg：文件指针相对于文件起始位置(0)的偏移量,简介获取文件的大小
		size_t byteNum=fin.tellg();
		cout << "byteNum:" << byteNum << endl;


		fin.read((char *)&info, sizeof(info));
		//参数1：将读取的内容存放在&info开始的位置
		//参数2：读取的大小，单位字节
		fin.close();
		cout << info.ip << endl;
		cout << info.port << endl;
	}
	//按字符流读写(按文本读取)
	void readTxt(Info& info){
		ifstream fin(_filename.c_str());
		fin >> info.ip;//fin遇到endl才会结束写入
		//相当于调用了:fin.operator >>(info.ip);
		fin >> info.port;
		//相当于调用了:fin.operator >>(info.port);
	}
	void WriteTxt(Info& info){
		ofstream fout(_filename.c_str());
		fout << info.ip<<endl;
		fout << info.port<<endl;
	}

	//获取 文件大小
private:
	string _filename;
};

int main(){
	Info info;
	strcpy(info.ip,"james");
	info.port = 20;
	Config file("config.txt");
	file.WriteBin(info);
	file.readBin(info);
	//file.WriteTxt(info);
	//file.readTxt(info);
	//写入的是文本文件
	return 0;
}