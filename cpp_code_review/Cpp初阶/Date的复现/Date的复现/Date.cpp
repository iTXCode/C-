#include"Date.h"


void Date::disPlay(){
	cout << _year << "-" << _month << "-" << _day << endl;
}
int Date::getMonthDay(int year,int month){
	int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int day = days[month];
	if (month == 2){
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
			 day = days[month]+1;
		}
	}
	return day;
}

Date::Date(int year , int month, int day){
	if (year < 0 ||month<0||month>12||day<0){
		cout << "��������ڷǷ�,�Ѿ����ó���Ĭ��ֵ" << endl;
		_year = 1900;
		_month = 1;
		_day = 0;
	}
	_year = year;
	_month = month;
	_day = day;
}
Date::Date(const Date& d){
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date Date::operator+(int days){
	Date ret(*this);
	ret += days;
	return ret;
	//��Ҫ�󷵻�һ�����õĻ����Ͳ��ܷ�����ʱ����
	//��ʱ���������������ٺ�Ͳ������ˡ�
}
Date Date::operator-(int days){
	Date ret(*this);
	//������ԭ����ֵ��û�иı䣬����һЩ���
	ret -= days;
	return ret;
}
Date& Date::operator=(const Date& d){
	if (*this!=d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
Date& Date::operator+=(int days){
	//��Ҫ�ж�Ҫ�ӵ����Ƿ�Ϊ����
	if (days < 0){
		return *this -= (-days);
	}
		_day += days;
		int day = getMonthDay(_year, _month);
		while (_day > day){
			_day -= day;
			++_month;
			if (_month == 13){
				_month = 1;
				++_year;
			}
		}
		return *this;
	
}
Date& Date::operator-=(int days){
	if (days < 0){
		return *this += (-days);
	}
		_day -= days;
		int day = getMonthDay(_year,_month);
		while (_day <=0){
			--_month;
			if (_month == 0){
				_month = 12;
				--_year;
			}
			_day += day;

		}
		return *this;
}
int Date::operator-(const Date& d){
	//��������������������ߵĲ�ֵ
	Date ret(*this);
	int flag = 1;
	if (ret < d){
		flag = -1;
	}
	int day = 0;
	if (ret < d){
		while (ret < d){
			++ret;
			++day;
		}
	}
	else {
		while (ret>d){
			--ret;
			++day;
		}
	}
	return day*flag;

}
Date& Date::operator++(){
	//++Date,�ı���Date��ֵ
	return (*this+=1);
}
Date Date::operator++(int){
	//Date++,�Ȳ��ı�Dateֵ
	Date ret = *this;
	ret += 1;
	return ret;
}
Date& Date::operator--(){
	//--Date,�ı���Date��ֵ
	
	return (*this-=1);
}
Date Date::operator--(int){
	//Date--,�Ȳ��ı�Dateֵ
	Date ret = *this;
	ret-=1;
	return ret;
}
bool Date::operator>(const Date& d)const{
	return _year > d._year
		|| _month > d._month
		|| _day > d._day;
}

bool Date::operator<(const Date& d)const{
	return _year < d._year
		|| _month < d._month
		|| _day < d._day;
}
bool Date::operator>=(const Date& d)const{
	return !(*this<d);
}

bool Date::operator<=(const Date& d)const{
	return !(*this>d);
}
bool Date::operator==(const Date& d)const{
	return this->_year == d._year
		&&this->_month == d._month
		&&this->_day == d._day;
}
bool Date::operator!=(const Date& d)const{
	return !(*this == d);
}