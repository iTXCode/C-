
#include<iostream>

using namespace std;
class A{
public:
	A(int a)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}
	A(const A& a){
		cout << "A(const A&)" << endl;
	}
	~A(){
		cout << "~A()" <<++_b<< endl;
	}

	int Add(int a,int b){
		return a + b;
	}
	static int sum(int a, int b){
		//this->_a = a;
		//��ʾ����thisֻ�����ڷǾ�̬���������ڲ�
		//�����е�static���εĺ���û��thisָ��
		return a - b;
	}
private:
	int _a;
	static int _b;
};

int A::_b = 0;
//��ľ�̬������Ҫ��������г�ʼ��

int main(){
	A a(10);
	A b = a;
	cout<<a.Add(10, 20)<<endl;
	cout << a.sum(30, 10) << endl;
	return 0;
}

//��ע�⡿
//ʵ���������˳����������˳�����෴��
//��ʵ�����Ķ�����������

