#include "MD5.h"
#include<iostream>

int main(int argc,char* argv[]){
	if (argc != 3){
		std::cout <<"eg:"<< std::endl;
		std::cout << argv[0] << "\t0\tfilename" << std::endl;
		std::cout << argv[0] << "\t1\tstring" << std::endl;
		return 0;
	}
	MD5 md5;
	char option = *argv[1];
	switch (option){
	case '0':
		std::cout << md5.getFileMD5(argv[2]) << std::endl;
		break;
	case '1':
		std::cout << md5.getStringMD5(argv[2]) << std::endl;
		break;
	}
	return 0;
}