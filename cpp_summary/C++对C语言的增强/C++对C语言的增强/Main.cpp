#include<iostream>
#include<stdlib.h>

using namespace std;

//c++��ȫ�ֱ����ļ������ǿ
int a;
int a = 10;

//���������ǿ,����������ǿ������ֵ������ǿ���������õĲ��������ǿ

int Add(int num_1,int num_2){
	return num_1 + num_2;
}
void test(){
	Add(10,20,30);
}

//3.����ת����ǿ

void test1(){
	char *piont =(char*) malloc(sizeof(int));
}

//4.struct ��ǿ
struct Student{
	int p_age;
	void avgGrade(){  
    //C������struct �в�������������
	}
};


void test2(){
	Student S;  //c++�п���ֱ���ýṹ������������������
	            //C��������Ҫ���Ϲؼ���static�����νṹ����
}

//5.bool���͵���ǿ(C������û��bool����)
bool Flag=true;  //ֻ������߼� ��0Ϊ��(true) 0Ϊ��(false)

//bool���� ��0��ת����1��0��ת����0

// 6.��Ŀ�������ǿ
void test4(){
	int a = 10;
	int b = 20;
	cout<<"���:"<<(a>b?a:b)<<endl;
	a > b ? a : b = 100; //c++�з��ص�Ϊ������c���Է��ص���ֵ
	//C��������ģ��c++д
	//*(a>b?&a:&b)=100;
}

void test3(){
	Flag = 520;
	cout << Flag << endl;
}

int main(){
	test3();
	system("pause");
	return 0;
}