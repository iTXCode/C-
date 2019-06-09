#include<iostream>

using namespace std;

int main(){
	int *p = new int;
	//只是申请了一个int类型的空间大小
	delete p;
	int *p1 = new int(1);
	//申请了一个int类型的空间大小并且将初始值设置为1
	//int a = new int(2);
	//如果直接给变量申请内存会提示
    //int*类型的值不能用于初始化int 类型的实体
	delete p1;
	int *a = new int(3);
	delete a;
	cout << a << endl;

	//因为a为指针变量所以输出的是一个地址
	return 0;
}