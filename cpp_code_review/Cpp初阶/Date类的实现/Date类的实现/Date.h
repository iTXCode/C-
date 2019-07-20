#include<iostream>

using namespace std;
class Date
{
public:
	//获取每个月的天数
	int getMonthDay(int year,int month);
	//构造函数
	Date(int year , int month , int day);
	//拷贝构造
	Date(const Date& d);
	//赋值操作符
	Date& operator=(const Date& d);
	//日期加天数
	Date operator+(int days);
	//日期减天数
	Date operator-(int days);
	//两个日期相减返回相差的天数
	int operator-(const Date& d);
	//++Date(先改变日期再返回)
	Date& operator++();
	//
	Date operator++(int);
	Date& operator--();
	Date& operator+=(int day);
	Date& operator-=(int day);
	Date operator--(int);
	bool operator>(const Date& d)const;
	//1.非const与const都可以调用const成员函数
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
	void disPlay();
private:
	int _year;
	int _month;
	int _day;
};