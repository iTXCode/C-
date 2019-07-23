
# if 0
#include<iostream>

using namespace std;

class Person {
public:
	virtual void BuyTicket() 
	{ cout << "买票-全价" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() 
	{ cout << "买票-半价" << endl; }
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person ps;
	Student st;
	Func(ps);
	Func(st);
	return 0;
}
#endif


# if 0
#include<iostream>

using namespace std;

class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-舒适" << endl;
	}
};

/*
class Benz :public Car {
public:
virtual void Drive() override {cout << "Benz-舒适" << endl;}
};*/
class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-操控" << endl;
	}
};
void Test()
{
	//Car c;//提示不允许使用抽象类类型Car的对象
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;
	pBMW->Drive();
}

int main(){
	Test();
	return 0;
}

#endif 

#include<iostream>

using namespace std;



//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};


//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main(){
//	Base b;
//	cout<<sizeof(b)<<endl;
//	return 0;
//}

// 针对上面的代码我们做出以下改造
// 1.我们增加一个派生类Derive去继承Base
// 2.Derive中重写Func1
// 3.Base再增加一个虚函数Func2和一个普通函数Func3
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};

int main()
{
	Base b;
	Derive d;
	return 0;
}
