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
//		:_year( year)    //初始化列表
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
//	// 用一个整形变量给日期类型对象赋值
//	// 实际编译器背后会用2019构造一个无名对象，最后用无名对象给d1对象进行赋值
//	d1 = 2019;//使用explicit时这种赋值也可以使用,阻止单三形式的隐式转换
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
//	// 非静态成员变量，可以在成员声明时，直接初始化。
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
//	//B是A的内部类，相当于B是A的友元类
//	public: //若不写作用限定符则会出现访问不了B的现象
//	class B{
//	public :
//		void Print(A& a){
//			cout << a._a << endl;
//			//外部类的普通成员必须通过“对象 . ”的方式去访问
//			cout << _s << endl; 
//			//外部类的静态成员可以通过“对象 .”的方式去访问
//			// 也可以直接去访问
//			cout << a._s << endl;
//		}
//	private:
//		int b;
//	};
//	void Print(B& b){
//        //外部类对于内部类没有任何优越的访问权限，不能访问
//		//内部类的私有成员
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
//	Test* pa = (Test *)malloc(sizeof(Test));//只是开辟空间
//	free(pa);
//	Test *pb = new Test;
//	//new 对于自定义类型来说，1.开辟空间2.调用构造函数(初始化)
//	delete pb;   //3.先析构4.再释放空间
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
		//释放空间
		//if(_pi){
		//free(_pi);
		//_pi=nullptr;
		cout << "~A" << endl;
	}
private:
	int _a;
	int _b;
	int *_pi;
	//加入申请了空间
};
int main(){
	//A* pa = (A *)malloc(sizeof(A));
	//free(pa);
	A *pb = new A;
	//new 调用自定义类型的构造函数，malloc不会
	delete pb;
	//delete 调用自定义类型的析构函数，free不会 
	/*A *pc = new A[10];
	delete[] pc;*/
	system("pause");
	return 0;
}