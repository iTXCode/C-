
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
//�иò��Գ����֪
//����Ҳռһ���ֽڵ��ڴ��С
//���еĺ�����С,�����뵽��Ĵ�С��ȥ
//���еı������뵽��Ĵ�С��
//�ڲ��಻���뵽�ⲿ���С��ȥ(�ڲ������ⲿ��û�д�����ϵ)
