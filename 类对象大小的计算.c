

#include<iostream>
#include<windows.h>
using namespace std;
class A{

};//大小为  1
class B{
public:
	void fun1(){
		int a = 10;
	}
};//大小为   1
大小为1的原因：void fun1()不占空间，1个字节不存储东西，用于占位，表示对象存在过。 

class C{
public:
	void fun1(){
		int a = 10;
	}
	char c;
	int a;
	double d;
};//大小为   16


class D{
public:
	void fun1(){
		int a = 10;
	}
	char c;
	double d;
	int a;
};  //大小为   24

class E{
public:
	void fun1(){
		int a = 10;
	}
	char c;
	double d;
	int a;
    
    class EE{
     public:
     char c;
     double d;
    };
};  //大小为   24
原因为嵌套的类EE大小为16，而原来的类大小为24，所以去最大的来表示整体的大小。
class F{
public:
	void fun1(){
		int a = 10;
	}
	char c;
	double d;
	int a;

	class EE{
	public:
		char c;
		double d;
	};
	EE ee;
};  //大小为40
大小为40的原因为：外部的大小包括了内部的类所定义对象的ee的大小。其大小为(16)



原因：如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。

int main(){
	cout << "A大小为" << sizeof(A) << endl;// 1
	cout << "B大小为" << sizeof(B) << endl;// 1
	cout << "C大小为" << sizeof(C) << endl;// 16
	cout << "D大小为" << sizeof(D) << endl;// 24
	cout << "E大小为" << sizeof(E) << endl;// 24
	cout << "EE大小为" << sizeof(E::EE) << endl; // 16
	cout << "F大小为" << sizeof(F) << endl;
	system("pause");
	return 0;
}