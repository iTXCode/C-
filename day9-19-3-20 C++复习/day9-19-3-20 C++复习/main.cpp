//#include <iostream>
//#include<windows.h>
//using namespace std;
//class A1{
//	char _ch;
//	double _d;
//};
//class A2{
//	double _d;
//	char _ch;
//};
//int main(){
//	cout << "A1的大小="<<sizeof(A1) << endl;
//	cout << "A2的大小=" << sizeof(A2) << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//class Date{
//public:
//	void Print(){
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	void SetDate(int year, int month, int day){
//		//构造的函数类似于买门票才能看到兵马用内部的东西
//		//公有函数提供了访问内部成员的机会
//		_year = year;   // 加上"_"可以避免冲突
//		_month = month;
//		_day = day;
//	}
//
//private:
//	//类似与兵马俑里面的展品。
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main(){
//	Date d1;
//	Date d2;
//
//	d1.SetDate(2019, 3, 9);
//	d2.SetDate(2018, 3, 9);
//
//	d1.Print();
//	d2.Print();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//class  Date{
//public:
//	Date(){ //构造函数，初始化了被它定义的对象
//		_year = 2019;
//		_month = 3;
//		_day = 10;
//	}
//	Date(int year, int month, int day){
//		//函数重载,函数名相同,参数不同
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print(){
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main(){
//	Date d1;//期望d1一出来就被初始化
//	d1.Print();
//
//	Date d2(2019,3,20);
//	d2.Print();
//
//	system("pause");
//	return 0;
//}


#include<iostream>
#include<windows.h>
using namespace std;
class  Date{
public:
	Date();//类里面声明，在类外面定义
	Date(int year, int month, int day){
		//函数重载,函数名相同,参数不同
		_year = year;
		_month = month;
		_day = day;
	}
	void Print(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
Date::Date(){  //构造函数可以在类外面定义
	_year = 2019;
	_month = 3;
	_day = 10;
}

int main(){

	Date d2(2019, 3, 20);
	d2.Print();

	Date d3; //构造函数可以在类中定义，也可以在类外定义
	d3.Print();
	system("pause");
	return 0;
}