#if 0
#include <iostream>

using namespace std;
class Person{
public:
	virtual void Ticket()
	{
		cout << "成人-》全价" << endl;
	}
private:
	int _b;
};

class Student :public Person
{
public:
	virtual void Ticket(){
		cout << "学生-》半价" << endl;
	}
private:
	int _s;
};

void PrintTicket(Person & p){
	p.Ticket();
}

int main(){
	Person p;
	PrintTicket(p);
	Student s;
	PrintTicket(s);
	return 0;
}

#endif 


#if 0
#include<iostream>

using namespace std;

class Person{

public:
	Person(int p)
		:_p(p)
	{
		cout << "Person(int)" << endl;
	}
	virtual ~Person(){
		cout << "~Person()" << endl;
	}
private:
	int _p;
};

class Student :public Person{
public:
	Student(int s)
		:Person(s)
		,_s(s)
		
	{
		cout << "Student(int)" << endl;
	}
	virtual ~Student(){
		cout << "~Student" << endl;
	}
private:
	int _s;
};

int main(){
	Person p(1);
	Student s(2);
	return 0;
}
#endif

#if 0
#include<iostream>

using namespace std;
class Person {
public:
	virtual ~Person() { cout << "~Person()" << endl; }
};
class Student : public Person {
public:
	virtual ~Student() { cout << "~Student()" << endl; }
};
// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	return 0;
}

#endif


#if 0
#include<iostream>

using namespace std;

class Car{
public:
	virtual void Print()=0
	{
		cout << "Print()" << endl;
	}
private:
	int _c;
};

class Benz :public Car
{
public:
	virtual void Print(){
		cout << "Benz::Print()" << endl;
	}
private:
	int _b;
};
int main(){
	Benz b;
	b.Print();
	return 0;
}

#endif


#if 0
#include<iostream>

using namespace std;

class Base{
public:
	virtual void fun1(){
		cout << "Base::fun1()" << endl;
	}
	virtual void fun2(){
		cout << "Base::fun2" << endl;
	}
};
class Derive: public  Base 
{
public:
	virtual void fun1(){
		cout << "Derive::fun1()" << endl;
	}
	virtual void fun3(){
		cout << "Derive::fun3()" << endl;
	}
	virtual void fun4(){
		cout << "Derive::fun4()" << endl;
	}
};

int main(){
	Base b;
	Derive d;
	return 0;
}

#endif

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//
//int main(){
//	char firstname[10];
//	char lastname[10];
//	printf("请输入你的名字:");
//	scanf("%s",firstname);
//	printf("请输入你的姓氏:");
//	scanf("%s",lastname);
//
//	printf(" firstname:%s\t lastname:%s\n",firstname,lastname);
//	printf("\t%10d \t%14d\n",strlen(firstname),strlen(lastname));
//	return 0;
//}


#if 0
#include<iostream>

using namespace std;

class Base{
public:
	virtual void fun1(){
		cout << "Base::fun1()" << endl;
	}

	virtual void fun2(){
		cout << "Bse::fun2()" << endl;
	}
};

int main(){

	return 0;
}

#endif