
#include<iostream>

using namespace std;

class A{

};

class E{
public:
	int a;
};

class B{
public:
	void fun(){

	}
	void fun1(int a){
		int b;
		b = 2*a;
	}
};
class C{
public:

	int func(){
		int a;
		int b;
		double c;
		float d;
	}
	class D{
	public:
		int _a;
		int _b;
		int _c;
	};
};

int main(){

	cout << "sizeof(A)="<<sizeof(A) << endl; //1
	cout<<"sizeof(B)=" << sizeof(B) << endl;  //1
	cout << "sizeof(C)="<< sizeof(C) << endl;  //1
	cout << "sizeof(E)="<< sizeof(E) << endl;   //4
	cout <<"sizeof(C::D)="<< sizeof(C::D) << endl; //12
	return 0;
}
//有该测试程序可知
//空类也占一个字节的内存大小
//类中的函数大小,不计入到类的大小中去
//类中的变量计入到类的大小中
//内部类不计入到外部类大小中去(内部类与外部类没有存数关系)
