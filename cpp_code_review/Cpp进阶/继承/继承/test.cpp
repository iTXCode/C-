#include<iostream>
#include<string>
#include<windows.h>
//函数的隐藏
using namespace std;

class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();//指明调用
		cout << "func(int i)->" << i << endl;
	}
};
void Test()
{
	B b;
	b.fun(10);
	//b.fun();//调不到fun()函数，因为已经被b中的fun(int)函数隐藏了
	//需要加上作用域限定符,如下语句
	b.A::fun();
}

int main(){
	Test();
	system("pause");
	return 0;
}