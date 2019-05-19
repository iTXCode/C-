#include<iostream>
#include<stdlib.h>

using namespace std;

//c++中全局变量的检测性增强
int a;
int a = 10;

//函数检测增强,参数类型增强，返回值类型增强，函数调用的参数检测增强

int Add(int num_1,int num_2){
	return num_1 + num_2;
}
void test(){
	Add(10,20,30);
}

//3.类型转换增强

void test1(){
	char *piont =(char*) malloc(sizeof(int));
}

//4.struct 增强
struct Student{
	int p_age;
	void avgGrade(){  
    //C语言中struct 中不可以声明函数
	}
};


void test2(){
	Student S;  //c++中可以直接用结构体的名字来定义变量，
	            //C语言中需要加上关键字static来修饰结构体名
}

//5.bool类型的增强(C语言中没有bool类型)
bool Flag=true;  //只有真或者假 非0为真(true) 0为假(false)

//bool类型 非0的转换成1，0就转换成0

// 6.三目运算符增强
void test4(){
	int a = 10;
	int b = 20;
	cout<<"结果:"<<(a>b?a:b)<<endl;
	a > b ? a : b = 100; //c++中返回的为变量，c语言返回的是值
	//C语言中想模范c++写
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