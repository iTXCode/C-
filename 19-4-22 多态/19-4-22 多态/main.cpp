#include<iostream>
#include<windows.h>
using namespace std;
////����������ö���Ϊ�麯����������
//
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//// ֻ��������Student������������д��Person������������
////�����delete��������������������ܹ��ɶ�
////̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
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
//������Կ�ָ�������

//���庯��ָ�룬��ʾһ�෵��ֵΪvoid ����������Ϊ0�ĺ���
typedef void(*VFPTR)();


int main(){
	Base b;
	Derive d;
	system("pause");
	return 0;
}