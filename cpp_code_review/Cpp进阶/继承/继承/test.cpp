#include<iostream>
#include<string>
#include<windows.h>
//����������
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
		A::fun();//ָ������
		cout << "func(int i)->" << i << endl;
	}
};
void Test()
{
	B b;
	b.fun(10);
	//b.fun();//������fun()��������Ϊ�Ѿ���b�е�fun(int)����������
	//��Ҫ�����������޶���,�������
	b.A::fun();
}

int main(){
	Test();
	system("pause");
	return 0;
}