#include<iostream>
#include<windows.h>
using namespace std;
////析构函数最好定义为虚函数，让子类
//
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，
////下面的delete对象调用析构函数，才能构成多
////态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	system("pause");
//	return 0;
//}



class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};
class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};
//虚表是以空指针结束的

//定义函数指针，表示一类返回值为void ，参数个数为0的函数
typedef void(*VFPTR)();


int main(){
	Base b;
	Derive d;
	system("pause");
	return 0;
}