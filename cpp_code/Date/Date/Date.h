#pragma once

#include<iostream>
#include<windows.h>
using namespace std;

class Date{
public:
	Date(int year = 1900; int month = 1; int day = 1){
		//Date(const Date& d);
		//Date& operator=(const Date& d);
		//~Date();
		bool operator>(const Date& d);
		bool operator<(const Date& d);
		bool operator<=(const Date& d);
		bool operator>=(const Date& d);
		bool operator==(const Date& d);
		bool operator!=(const Date& d);
		Date& Date::operator-=(int day){
			Date cur = (this);
			if ()
		}
	}
private:
	int _year;
	int _month;
	int _day;
};