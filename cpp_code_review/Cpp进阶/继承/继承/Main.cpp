#include<iostream>

using namespace std;

#if 0
class BaseInfor{
public:
	char* _name;
protected:
	int _age;
private:
	char* _sex;
};
class Student : public BaseInfor{
private:
	void fun(){
		_name = "jack"; //基类中的公有成员，在派生类中可以访问
		_age = 13;  //基类中的保护成员，在派生类中可以访问
		//_sex = "男"; //基类中的私有成员，在派生类中不可访问
	}
protected:
	int _id;
	char* _class_num;
};
//protected:在类外无法访问，但是在子类内部可以访问
//private:在类外和子类都无法访问
//public继承:不改变基类成员在子类中的访问权限
//protectes继承：基类成员在子类中的最低访问权限为protected
//private继承:基类成员在子类中的最低访问权限为private

int main(){
	
	BaseInfor p;
	Student s;
	p = s;
	//子类对象可以赋给父类对象
	//s = p;
	//子类对象不可以赋给父类对象

	
	Student *P2;
	BaseInfor* p1 = &s;
	//父类引用可以赋值给子类指针
	p1 = (BaseInfor*)&P2; //强制类型转换
	return 0;
}

#endif



#if 0
//同名隐藏
class Person{
public:
	int _num = 101;
};
class Student:public Person
{
public:
	int _num = 200;
};
int main(){
	Person p;
	Student s;
	cout << p._num << endl;
	cout << s._num << endl;
	cout << s.Person::_num << endl;
	cout << s.Student::_num << endl;
	//当子类和父类的成员变量/成员函数同名时，
	//子类会将父类中的同名变量/函数隐藏掉
	//若需访问需要加上作用域限定符
	return 0;
}

#endif 



class A{
public:
	A( char* name="james")
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
	B( char *name = "jack")
		:_name(name)
		,A(name)
	{
		cout <<"B()" << endl;
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
