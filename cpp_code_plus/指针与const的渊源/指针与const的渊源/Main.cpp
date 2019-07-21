#include<iostream>

using namespace std;

int  main(){
	int d = 10;
	 const int * p = &d;
	 int const *t = &d;
	 //当const放类型的左侧或者右侧时const修饰的是指针指向地址内的内容
	 //即指针所指的地址可变，地址内的内容不可更改
	//*p = 20;//报错表达式必须是可修改的左值
	 //指针p和t指向同一片空间，两者的效果是一样的
	 int i = 10;
	 int *const q = &i;
	 //当const放在"*"右侧的时时候const修饰的是指针所指向的地址
	 //即指针所指向的地址不可变，但是地址内的内容可变
	 *q = 20;
	return 0;
}