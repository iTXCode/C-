#include<iostream>
#include<stdlib.h>

using namespace std;

#if 0
class Date{
	friend void operator<<(ostream &out, Date d);
	//友元函数
	//友元关系不能传递
public:
	
	Date(){

	}
	Date(int year, int month, int  day)
		:_year(year)
		, _month(month)
		, _day(day)
	{

	}
private:
	int _year;
	int _month;
	int _day;
};


void operator<<(ostream &out,Date d){
	out << d._year << "-" << d._month << "-" << d._day << endl;
}
int  main(){
	Date d(2019,6,2);
	operator<<(cout, d);
	return 0;
}
#endif 

////友元类
//class Date{
//	friend class Time;
//public:
//	Date(){
//		
//	}
//	//void disPlay(Time &a){
//	//	cout << a._t << endl;
//	//	//友元关系是单项的不具有传递性
//	////不可以访问到
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////Time是Date的友元类，则在Time类中可以访问Date类中的成员
//
//class Time{
//public:
//	Time(){
//	}
//	void disPlay(Date &d){
//		d._day = 10;
//	}
//private:
//	int _t=10;
//};
//
//int main(){
//	Date d;
//	Time t;
//	return 0;
//}