#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


/*
 
 c++ ��׼�������
 #include<sstream>
 
 ���� boost �ķ����ǱȽϿ�ѧ�ķ���
 boost algotithm/string.hpp
 boost::split
 
 */

//input ��ʾ���з�����
//output ��ʾ�зֽ��(�ַ�������)
//����ֵ��ʾ output �а����˼�����ЧԪ��
int Split(char  input[], char *output[]){
	//���� strtok ��ʵ��
	char *p = strtok(input, " ");
	//����ֵָ���һ�� l ��ָ��
	int i = 0;
	while (p != NULL){
		//printf("%s\n",p);
		output[i] = p;
		++i;
		p = strtok(NULL," ");
		//�ڶ��η���ֵָ�� - ��ָ��
		//�����η���ֵָ��/��ָ��
		//���Ĵη���ֵΪNULL
	}
	return i;
}

int main(){
	while (1){
		//1.��ӡ��ʾ��
		printf("[myshell@localhot ~]$");
		fflush(stdout);
		//2.���û�����ָ��
		char command[1024] = { 0 };
		//scanf("%s",command);
		//scanf�������ո��ӡһ�������ʱ��ͻ����
		//��gets��һ��������һ�ζ���һ������
		gets(command);
		//TODO������ scanf �ܷ����һ������
		//printf("%s\n", command);
		//3.����ָ��,������Ҫִ���Ǹ�����ʶ�����,
		//��Щ�������в���ʶ�����(�ַ����з�)
		//�зֽ��Ӧ����һ���ַ�������
		char *argv[1024] = { 0 };
		int n = Split(command, argv);

		//4.�����ӽ��̲��ҽ��г����滻
		CreateProcess(argv);
	}
	return 0;
}

#endif


