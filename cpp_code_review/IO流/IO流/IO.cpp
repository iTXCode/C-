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
	//���ֽ�����д(���ڴ���ʽ��д(������) )
	void WriteBin(Info& info){
		ofstream fout(_filename.c_str());
		//�������ȡ�ļ���С�ķ�ʽ
		
		
		
		fout.write((char *)&info, sizeof(info));
		//����1����&info��ʼ��λ�ÿ�ʼ��ȡ����
		//����2����ȡ�Ĵ�С����λ�ֽ�
		fout.seekp(0, ofstream::end);
		size_t ByteNum = fout.tellp();
		cout << "ByteNum:" << ByteNum << endl;
		fout.close();
	}
	
	void readBin(Info& info){
		ifstream fin(_filename.c_str());

		//��������ȡ�ļ���С�ķ�ʽ
		//seekg:�����ļ�ָ���λ��
		fin.seekg(0,ifstream::end);
		//tellg���ļ�ָ��������ļ���ʼλ��(0)��ƫ����,����ȡ�ļ��Ĵ�С
		size_t byteNum=fin.tellg();
		cout << "byteNum:" << byteNum << endl;


		fin.read((char *)&info, sizeof(info));
		//����1������ȡ�����ݴ����&info��ʼ��λ��
		//����2����ȡ�Ĵ�С����λ�ֽ�
		fin.close();
		cout << info.ip << endl;
		cout << info.port << endl;
	}
	//���ַ�����д(���ı���ȡ)
	void readTxt(Info& info){
		ifstream fin(_filename.c_str());
		fin >> info.ip;//fin����endl�Ż����д��
		//�൱�ڵ�����:fin.operator >>(info.ip);
		fin >> info.port;
		//�൱�ڵ�����:fin.operator >>(info.port);
	}
	void WriteTxt(Info& info){
		ofstream fout(_filename.c_str());
		fout << info.ip<<endl;
		fout << info.port<<endl;
	}

	//��ȡ �ļ���С
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
	//д������ı��ļ�
	return 0;
}