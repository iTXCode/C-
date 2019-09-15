//#include<iostream>
//
//using namespace std;
//
//class Parent{
//public:
//	virtual void Fun1(){
//		cout << "Parent::Fun1()" << endl;
//	}
//	virtual void Fun2(){
//		cout << "Parent::Fun2()" << endl;
//	}
//
//	virtual void Fun3(){
//		cout << "Parent::Fun3()" << endl;
//	}
//private:
//	int _p = 2;
//};
//
//class Child :public Parent
//{
//public:
//	virtual void Fun1(){
//		cout << "Child::Fun1()" << endl;
//	}
//private:
//	int _c=1;
//};
//int global = 3;
//int main(){
//	Child c;
//	int tmp = 2;
//	int  *p = new int;
//	cout <<"栈上:"<< &tmp << endl;
//	cout << "堆上:"<<p << endl;
//	cout <<"数据段:"<< &global << endl;
//	printf("代码段:%p\n", &Parent::Fun3);
//
//	printf("虚表:%p\n",*((int *)&c));
//	return 0;
//}


#if 0
#include<iostream>

using namespace std;

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

int main()
{
	Base b;
	Derive d;
	return 0;
}
#endif



#include<iostream>

using namespace std;

typedef void(*VFPTR)();

void PrintVF(VFPTR vfpt[])
{
	printf("虚表： %p\n", vfpt);
	//虚表以nullptr
	while (*vfpt != nullptr)
	{
		VFPTR vf = *vfpt;
		printf("0x%p-->", vf);
		vf();
		//cout << endl;
		++vfpt;
	}
}



class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
//子类的虚表和父类的个数相同，子类自己定义的虚函数放在第一个直接父类的虚表中
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

int main()
{
	Base1 b1;
	Base2 b2;
	Derive d;
	Base2* pb2 = &d;
	PrintVF((VFPTR*)*(int*)&b1);
	PrintVF((VFPTR*)*(int*)&b2);
	cout << "Derived: " << endl;
	PrintVF((VFPTR*)*(int*)&d);
	PrintVF((VFPTR*)*(int*)pb2);
	PrintVF((VFPTR*)*(int*)((char*)&d + sizeof(Base1)));
	cout << sizeof(Derive) << endl;

	return 0;
}
