

#include<iostream>
#include<stdlib.h>
using namespace std;

#if 0
class Date{
public :
	Date(int year){
		_count++;
		_year = year;
		cout << "Date(int)" << endl;
	}
	Date(const Date& d1){
		_count++;
		cout << "Date(const Date&)" << endl;
	}

	/*int getcount(){
		return _count;
		}*/

	static int getcount(){
		return _count;
		//静态成员函数，不能调用非静态函数
		//静态成员函数没有this指针
	}

	void add(){
		getcount();
		//非静态成员函数可以调用静态成员函数
	}
	void operator<<(ostream& outs){
		outs<<_year<<endl;
	}
	
private:

	int _year;
	static int _count;
};
//用static修饰的变量要在类外面进行初始化
//所有对象共享静态变量
//静态成员不属于某个类，是所有对象共有的

int Date::_count = 0;

Date fun(Date d1){
	return d1;
}

int main(){
	Date d(2019);
	fun(d);
	cout << d.getcount()<< endl;
	//可以通过类型加作用限定符去调用(Date::getcount)
	//也可以通过对象.的方式去调用(d.getcount)
	return 0;
}

//输出三次函数调用，其中两次拷贝构造
//(fun函数传参时发生临时拷贝，返回另一个新的对象 )

#endif

//class Date{
//public:
//	Date(){
//		cout << "Date(int)" << endl;
//	}
//	Date(const Date&d){
//		cout << "Date (const Date&)" << endl;
//	}
//
//	static int count;
//};
//int Date::count = 0;
//
//int main(){
//	Date d;
//	cout << Date::count << endl;
//	cout << d.count << endl;
//	return 0;
//}
