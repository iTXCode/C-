//#include <iostream >
//#include<windows.h>
//using namespace std;
//
//class Sum{
//public:
//	Sum(){
//		sum+=i;
//		i++;
//	}
//
//	static int sum;
//	static int i;
//};
//
//int  Sum ::sum = 0;
//int Sum::i = 1;
//int main(){
//	Sum a[10];
//	cout << Sum::sum << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//
//class Date{
//
//public:
//	 Date(int  year=2018, int month=8, int day=8)
//		:_year( year)    //��ʼ���б�
//		,_month(month)
//		,_day(day)
//	
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	 void operator<<(ostream& outs){
//		 outs << _year << "-" << _month << "-" << _day << endl;
//	 }
//private:
//
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main(){
//
//	Date d1(2018, 12, 2);
//	//cout << d1 << endl;
//	d1.operator<<(cout);
//	d1 << cout;
//	system("pause");
//	return 0;
//
//}


//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{}
//	/*explicit Date(int year)
//		:_year(year)
//	{}*/
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestDate()
//{
//	Date d1(2018);
//
//	// ��һ�����α������������Ͷ���ֵ
//	// ʵ�ʱ������������2019����һ������������������������d1������и�ֵ
//	d1 = 2019;//ʹ��explicitʱ���ָ�ֵҲ����ʹ��,��ֹ������ʽ����ʽת��
//}
//int main(){
//	TestDate();
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include <windows.h>
//using  namespace std;
//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	int _b;
//};
//class A
//{
//public:
//	void Print()
//	{
//		cout << a << endl;
//		cout << b._b << endl;
//		cout << p << endl;
//	}
//private:
//	// �Ǿ�̬��Ա�����������ڳ�Ա����ʱ��ֱ�ӳ�ʼ����
//	int a = 10;
//	B b = 20;
//	int* p = (int*)malloc(4);
//	static int n;
//};
//int A::n = 10;
//int main()
//{
//	A a;
//	a.Print();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//class A{
//	//B��A���ڲ��࣬�൱��B��A����Ԫ��
//	public: //����д�����޶��������ַ��ʲ���B������
//	class B{
//	public :
//		void Print(A& a){
//			cout << a._a << endl;
//			//�ⲿ�����ͨ��Ա����ͨ�������� . ���ķ�ʽȥ����
//			cout << _s << endl; 
//			//�ⲿ��ľ�̬��Ա����ͨ�������� .���ķ�ʽȥ����
//			// Ҳ����ֱ��ȥ����
//			cout << a._s << endl;
//		}
//	private:
//		int b;
//	};
//	void Print(B& b){
//        //�ⲿ������ڲ���û���κ���Խ�ķ���Ȩ�ޣ����ܷ���
//		//�ڲ����˽�г�Ա
//		//cout << b._b << endl;
//	}
//private:
//	int _a=0;
//	static int _s;
//};
//int A::_s = 1;
//int main(){
//	A::B a;
//	a.Print(A());
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//
//using namespace  std;
//
//int main(){
//	printf("helloworld!");
//	system("pause");
//	return 0;
//}
//
//#include<iostream>
//#include<stdlib.h>
//#include<windows.h>
//using namespace std;
//
//class Test
//{
//public:
//	Test()
//		: _data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//
//private:
//	int _data;
//};
//int main(){
//	Test* pa = (Test *)malloc(sizeof(Test));//ֻ�ǿ��ٿռ�
//	free(pa);
//	Test *pb = new Test;
//	//new �����Զ���������˵��1.���ٿռ�2.���ù��캯��(��ʼ��)
//	delete pb;   //3.������4.���ͷſռ�
//	Test *pc = new Test[10];
//	delete[]pc;
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

class A{
public:
	A(){
		cout << "A" << endl;
	}

	~A(){
		//�ͷſռ�
		//if(_pi){
		//free(_pi);
		//_pi=nullptr;
		cout << "~A" << endl;
	}
private:
	int _a;
	int _b;
	int *_pi;
	//���������˿ռ�
};
int main(){
	//A* pa = (A *)malloc(sizeof(A));
	//free(pa);
	A *pb = new A;
	//new �����Զ������͵Ĺ��캯����malloc����
	delete pb;
	//delete �����Զ������͵�����������free���� 
	/*A *pc = new A[10];
	delete[] pc;*/
	system("pause");
	return 0;
}