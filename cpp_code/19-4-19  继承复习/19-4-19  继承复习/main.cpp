//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
// 
//class Student : public Person  //继承了Person 的内容
//{
//public:
//	
//protected:
//	int _stuid= 4170903; // 学号
//};
//
//class Teacher : public Person
//{
//public:
//	
//protected:
//	int _jobid=147632; // 工号
//};
//int main(){
//	Person p;
//	Student s;
//	s.Print();
//	Teacher t;
//	t.Print();
//	system("pause");
//	return 0;
//}
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name; // 姓名
//private:
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//protected:
//	int _stunum; // 学号
//};
//
//int main(){
//	Person p;
//	Student s;
//	p = s;//切片:子类对象可以赋值给父类对象，
//	s.Print();
//	system("pause");
//	return 0;
//}


// Student的_num和Person的_num构成隐藏关系，
//可以看出这样代码虽然能跑，但是非常容易混淆

//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
  

//int main(){
//	Test();
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
//class Person
//{
//public:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//public:
//	int _num = 999; // 学号
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
//int main(){
//	Person p;
//	Student s;
//	cout << s._num << endl;
//	cout << s.Person::_num << endl;
//	cout << p._num << endl;
//	cout << s.Student::_num << endl;
//	system("pause");
//	return 0;
//}



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
//}
//
//int main(){
//	Test();
//	system("pause");
//	return 0;
//}

//重载：函数在同以作用域，函数名相同，参数不同
//重定义：重定义/隐藏：子类函数和父类函数名相同就会构成隐藏

//
//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	//完成父类对象的初始化，子类的构造函数先调用基类的构造函数，
//	//再执行子类的构造函数
//	//必须先调用父类的构造函数和拷贝构造进行初始化
//	Student(const char* name, int num)
//		: Person(name)
//		
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//	//如果子类不显示的调用父类的拷贝构造，则调用父类的默认构造函数
//	//如果子类显示的调用父类类的拷贝构造，就不会再去调用父类的默认构造
//	Student(const Student& s) 
//		//(Student *this,const Student &s)还发生了指针的欺骗。
//		: Person(s)//此处是一个切片的操作，调用父类的拷贝构造
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	//父类的成员变量可以直接在子类的赋值运算符重载函数长中直接赋值
//	//如果是编译器默认生成的子类赋值运算符重载函数，会调用父类的
//	//赋值运算符重载函数进行赋值
//	Student& operator = (const Student& s)
//	{
//		cout << "Student& operator= (const Student& s)" << endl;
//		if (this != &s)
//		{
//			//建议直接显示调用父类的赋值运算符重载函数，代码复用
//			//operator =(s);不可以这样写
//			Person::operator =(s);//此处调用的this指针为子类对象的this指针
//			_num = s._num;
//		}
//		return *this; //若if中没有显示的写出父类的赋值运算符重载的话，
//		//子类中不会调用父类的赋值运算符重载
//	}
//	//析构函数:不允许显示调用父类的析构函数
//	~Student()
//	{
//		//~Person();坑:同名隐藏，编译器底层对析构函数的名字做了
//		//修改为了使用多条调不动
//		//Person::~Person(); //可以调动
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //学号
//};
//void Test()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//	Student s3("rose", 17);
//	s1 = s3;
//}
//int main(){
//	Test();
//	system("pause");
//	return 0;
//}