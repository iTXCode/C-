#include<iostream>

using namespace std;

class Date{
public:
	Date(int year){
		_year = year;
	}
private:
	int _year;
};

int main(){
	Date d1(2019);
    //自动调用Date(int year ) 函数
	Date d2 = 2018;
    //也可以自动调用Date(int year ) 函数
	return 0;
}


#include<iostream>

using namespace std;

class Date{
public:
	explicit Date(int year){
		_year = year;
	}
private:
	int _year;
};

int main(){
	Date d1(2019);
	//Date d2 = 2018;
	//当加了explicit 后这种引用方法出错
	return 0;
}


                           2.关键字  static
2.1 概念
声明为static的类成员称为类的静态成员，用static修饰的成员变量，称之为静态成员变量；
用static修饰的成员函数，称之为静态成员函数。静态的成员变量一定要在类外进行初始化

//#include<iostream>
//#include<Windows.h>
//
////此情况为static定义的函数为公有的
//using namespace std;
//class Date{
//public:
//	Date(int year){
//		_count++;
//		_year = year;
//		
//		cout << "Date(int)" << endl;
//	}
//	Date(const Date& d1){
//		_count++;
//		_year = d1._year;
//		cout << "Dtae(const Date& d1)" << endl;
//	}
////private:
//	int _year;
//	static int _count; 
//	//static定义的变量在类外面进行初始化
//};
//
//int Date::_count = 0;
//
////static定义的变量在类外初始化
//Date fun1(Date d1){
//	return d1;
//}
//
//int main(){
//	Date d1(2019);
//	Date d2(2015);
//	Date d3(2015);
//	fun1(d1);
//	cout << d1._count<< endl;
//	cout << &d1._count << endl;
//	cout << &d2._count << endl;
//	cout << &d3._count << endl;
//	system("pause");
//	return 0;
//}
//

//#include<iostream>
//#include<Windows.h>
//
////此情况为static定义的函数为私有的
//using namespace std;
//class Date{
//public:
//	Date(int year){
//		_count++;
//		_year = year;
//
//		cout << "Date(int)" << endl;
//	}
//	Date(const Date& d1){
//		_count++;
//		_year = d1._year;
//		cout << "Dtae(const Date& d1)" << endl;
//	}
//	int getCount(){
//		//作用是将_count 的值传到需要调用_count的地方
//		return _count;
//	}

//改为静态函数后       static int getCount(){
//		                //出现错误，静态函数不能调用非静态函数
//		                   return _count;
//	                      }
//private:
//	int _year;
//	static int _count;
//	//static定义的变量在类外面进行初始化
//};
//
//int Date::_count = 0;
//
////static定义的变量在类外初始化
//Date fun1(Date d1){             //fun(Date *this)
//                      //非静态函数可以调用非静态函数
//	return d1;
//}
//
//int main(){
//	Date d1(2019);
//	Date d2(2015);
//	Date d3(2015);
//	fun1(d1);
//	cout << d1.getCount() << endl;
//	system("pause");
//	return 0;
//}
//
//


          2.2       特性
1. 静态成员为所有类对象所共享，不属于某个具体的实例
2. 静态成员变量必须在类外定义，定义时不添加static关键字
3. 类静态成员即可用类名::静态成员或者对象.静态成员来访问
4. 静态成员函数没有隐藏的this指针，不能访问任何非静态成员
5. 静态成员和类的普通成员一样，也有public、protected、private3种访问级别，
也可以具有返回值，const修饰符等参数



4. 友元
4.1 友元分为：友元函数和友元类
友元提供了一种突破封装的方式，有时提供了便利。但是友元会增加耦合度，破坏了封装，所以友元不宜多
用。


4.2 友元类
友元类的所有成员函数都可以是另一个类的友元函数，都可以访问另一个类中的非公有成员。
友元关系是单向的，不具有交换性。
比如上述Time类和Date类，在Time类中声明Date类为其友元类，那么可以在Date类中直接访问Time
类的私有成员变量，但想在Time类中访问Date类中私有的成员变量则不行。
友元关系不能传递
如果B是A的友元，C是B的友元，则不能说明C时A的友元

class Date{
    friend class Time             //Time 可以访问 Date 对象的所有成员
};

class Time{
    friend class Date            //Date 可以访问 Time 对象的所以成员
};

友元关系不能传递



                      5. 内部类
class A{
    //B是A的内部类,相当于B是A的内部类
    class B{
        public:
        void display(A& a){
            cout<<a._a<<endl;
            //外部类的普通的私有成员只能通过 对象. 的方式访问
            cout<<_s<<endl;          //直接访问
            cout<<a._s<<endl;        //对象. 的方式访问
            //外部类的静态的私有成员可以通过 对象. 的方式访问 也可以直接访问
            private:
            int _b;
        }
        void Display(B& b){
            //外部类对于内部类没有任何优越的访问权限，不能访问内部的私有成员(_b)
            cout<< b._b<<endl;
        }
    };
    private:
    int _a;
    static int _s;
};


                                   题目


 2.求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及
 条件判断语句（A?B:C).
#include<iostream>
#include<windows.h>

using namespace std;

class A{
public:
	class Sum{
	public:
		Sum(){
			_sum += _i;
			++_i;
		}
	};
	int Sum_solution(int n){
		Sum arr[5];
		return _sum;
	}
private:
	static int _sum;
	static int _i;
};

int A::_sum = 0;
int A::_i = 1;
int main(){
	A a;
	cout << a.Sum_solution(0) << endl;
	system("pause");
	return 0;
}


    输入年月日,判断改天是今年的多少天

#include<iostream>
#include<windows.h>

using namespace std;
int main(){
	int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year, month, day;
	cin >> year>> month>> day;
	int total = days[month - 1] + day;
	if (month>2){
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)){
			total += 1;
		}
	}
	cout << total << endl;
	system("pause");
	return 0;
}
