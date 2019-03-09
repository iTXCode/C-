//#include<iostream>
//#include<windows.h>
//using namespace std;
//
//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//	struct ListNode* prev;
//};
////类型：struct ListNode
////c++兼容c语言
//
//int main(){
//	struct ListNode node;
//	system("pause");
//	return 0;
//}


//c++中亦可以编过。
//#include<iostream>
//#include<windows.h>
//using namespace std;
//
//struct ListNode
//{
//	int data;
//	 ListNode* next;
//	 ListNode* prev;
//};
////类型：struct ListNode
////c++兼容c语言
//
//int main(){
//	struct ListNode node;
//	system("pause");
//	return 0;
//}




//class A{
//
//	//成员函数
//	void fun(){
//
//	}
//	//成员变量
//	int a;
//	int b;
//	int  c;
//};

//class B{
//	void fun();
//};
//
//void B::fun(){
////::作用域限定符
//}
//
////在类里面声明，在外定义

//class A{
//public:
//	//成员函数
//	void fun(){
//
//	}
//private:
//	//成员变量
//	int a;
//	int b;
//	int  c;
//};
//
//int main(){
//	A x;
//	x.fun();
//	x.b;
//	return 0;
//}


//class Person
//{
//public:
//	void PrintPersonInfo();
//private:
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//// 这里需要指定PrintPersonInfo是属于Person这个类域
//void Person::PrintPersonInfo()
//{
//	cout << _name << " "_gender << " " << _age << endl;
//}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//class A{
//public:
//	int a;
//	int b;
//	int c;
//	int fun(int x, int y){
//		return x + y;
//	}
//};
//
//int main(){
//	A ra;
//	ra.a = 10;
//	ra.b = 20;
//	cout<<ra.fun(ra.a,ra.b)<<endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//class A{
//
//};
//class B{
//public:
//	void fun1(){
//		int a = 10;
//	}
//};
//
//class C{
//public:
//	void fun1(){
//		int a = 10;
//	}
//	char c;
//	int a;
//	double d;
//};
//
//class D{
//public:
//	void fun1(){
//		int a = 10;
//	}
//	char c;
//	double d;
//	int a;
//};
//
//
//class E{
//public:
//	void fun1(){
//		int a = 10;
//	}
//	char c;
//	double d;
//	int a;
//	class EE{
//	public:
//		char c;
//		double d;
//	};
//};  
//
//class F{
//public:
//	void fun1(){
//		int a = 10;
//	}
//	char c;
//	double d;
//	int a;
//
//	class EE{
//	public:
//		char c;
//		double d;
//	};
//	EE ee;
//};  //大小为40
//
//
//int main(){
//	cout << "A大小为" << sizeof(A) << endl;
//	cout << "B大小为" << sizeof(B) << endl;
//	cout << "C大小为" << sizeof(C) << endl;
//	cout << "D大小为" << sizeof(D) << endl;
//	cout << "E大小为" << sizeof(E) << endl;
//	cout << "EE大小为" << sizeof(E::EE) << endl;
//	cout << "F大小为" << sizeof(F) << endl;
//	system("pause");
//	return 0;
//}




#include<iostream>
#include<windows.h>
using namespace std;

class Date{
public:
	void Print(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void SetDate(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main(){
	Date d1;
	d1.SetDate(2019, 3, 9);
	d1.Print();
	system("pause");
	return 0;
}