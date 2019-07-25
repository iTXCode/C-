//#include<iostream>
//#include<string>
//#include<windows.h>
////函数的隐藏
//using namespace std;
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();//指明调用
//		cout << "func(int i)->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10);
//	//b.fun();//调不到fun()函数，因为已经被b中的fun(int)函数隐藏了
//	//需要加上作用域限定符,如下语句
//	b.A::fun();
//}
//
//int main(){
//	Test();
//	system("pause");
//	return 0;
//}


#if 0
#include<iostream>

using namespace std;

class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		std::cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};
class Student : public Person
{
public:
	//完成父类对象的初始化，子类的构造函数先调用基类的构造函数，
	//再执行子类的构造函数
	//必须先调用父类的构造函数和拷贝构造进行初始化
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}
	//如果子类不显示的调用父类的拷贝构造，则调用父类的默认构造函数
	//如果子类显示的调用父类类的拷贝构造，就不会再去调用父类的默认构造
	Student(const Student& s)
		//(Student *this,const Student &s)还发生了指针的欺骗。
		: Person(s)//此处是一个切片的操作，调用父类的拷贝构造
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}
	//父类的成员变量可以直接在子类的赋值运算符重载函数长中直接赋值
	//如果是编译器默认生成的子类赋值运算符重载函数，会调用父类的
	//赋值运算符重载函数进行赋值
	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			//operator =(s);不可以这样写
			Person::operator =(s);//此处调用的this指针为子类对象的this指针
			_num = s._num;
		}
		return *this; //若if中没有显示的写出父类的赋值运算符重载的话，
		//子类中不会调用父类的赋值运算符重载
	}
	//析构函数:不允许显示调用父类的析构函数
	~Student()
	{
		//~Person();坑:同名隐藏，编译器底层对析构函数的名字做了修改为了使用多条调不动
		//编辑器将~Student()与~Person()都修改成了~destructor
		//Person::~Person(); //可以调动
		cout << "~Student()" << endl;
	}
protected:
	int _num; //学号
};
void Test()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
}
int main(){
	Test();
	return 0;
}
//构造顺序：先是基类构造————》派生类构造 
//析构顺序：派生类析构--》基类析构
//原因为函数栈帧的排列顺序 

#endif


#include<iostream>

using namespace std;
class A{
public:
	A(char* name = "james")
		:_name(name)
	{
		cout << _name << endl;
		cout << "A()" << endl;
	}
	A& operator=(const A& a){
		cout << "A& operator=(const A&a)" << endl;
		if (this != &a){
			_name = a._name;
		}
		return *this;
	}
	~A(){
		cout << "~A()" << endl;
	}
	A(const A& a){
		cout << "A(const A&a)" << endl;
	}
private:
	char* _name;
};

//class B:public A{

//};

//派生类类不显示的写出调用基类的构造与析构函数时
//派生类会自动调用基类的构造和析构函数


class B : public A{
public:
	//基类的成员不能直接在派生类的构造和拷贝构造中直接初始化，必须调用父类
	//的构造和拷贝构造进行初始化

	//派生类构造函数先调用基类构造函数，再执行派生类构造函数
	/*B(const char* name="jack")
	:_name(name)
	{

	}*/
	//错误的定义方式
	B(char *name = "jack")
		: A(name)
		,_name(name)
		
	{
		std::cout << "B()" << endl;
	}
	~B(){
		cout << "~B" << endl;
	}

	B(const B&b)
		//:A(b)//显示的写出来会先调用基类的拷贝构造
	{
		cout << "B(const B&b)" << endl;
	}
	//如果子类不显示调用父类的拷贝构造，则调用父类的默认拷贝构造
	//如果子类显示的调用父类的拷贝构造，就不会再去调用父类的默认拷贝构造

	B& operator=(const B&b)
	{
		cout << "B&operator= (const B&b)" << endl;
		if (this != &b){
			//_name = b._name;
			A::operator=(b);
			//调用了基类的赋值运算符重载函数
		}
		return *this;
	}
	//基类的成员变量可以直接在子类的 赋值运算符重载函数中直接赋值
	//如果是编译器默认生成的派生类赋值运算符重载函数,
	//会调用基类的赋值运算符重载函数进行赋值
private:
	char* _name;
};
void test(){
	B b;
	B c(b);
	B d = c; //拷贝构造
	//派生类中没有写拷贝构造的时候调用了基类的拷贝构造
	//派生类中显示的写出拷贝构造的时候调用的是派生类的拷贝构造
	d = c; //调用赋值运算符重载
	//派生类中没有写赋值运算符重载的时候调用了基类的赋值运算符重载
	//派生类中显示的写出赋值运算符重载的时候调用的是派生类的赋值运算符重载
}

int main(){
	test();
	return 0;
}