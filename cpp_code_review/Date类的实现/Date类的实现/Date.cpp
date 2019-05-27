#include"Date.h"

//��ȡÿ���µ�����
int Date::getMonthDay(int year,int month){
	static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = days[month];
	if (month == 2){
		//�ж�����
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
			day+= 1;
		}
	}
	return day;
}
Date::Date(int year , int month , int day ){
	//�ж����������յĺ�����(�Լ�������)
	if (year <= 0 || month > 12 || month < 1 || day <= 0
		|| day>getMonthDay(year, month)){
		cout << "����������ǷǷ���,�����Ѿ���ΪĬ��ֵ:" << endl;
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	//�Ϸ��Ļ�ֱ�ӳ�ʼ��
	_year = year;
	_month = month;
	_day = day;
}
Date::Date(const Date& d){
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
}

Date& Date::operator=(const Date& d){
	if (*this != d){
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}
	return *this;
}
Date Date::operator+(int day){
	Date ret(*this);
	ret += day;
	return ret;
	//��������������ֵ��ʱ��Ͳ��ܷ�����ʱ����
}
Date Date::operator-(int day){
	Date ret(*this);//��������
	ret -= day;
	return ret;
}
Date& Date::operator+=(int day){
	//�ж������ĺϷ���
	if (day<0){
		return *this -= (-day);
	}
	_day += day;
	//�����Ƿ��λ
	while (_day > getMonthDay(_year, _month)){
		_day -= getMonthDay(_year, _month);
		++_month;
		//�жϵ�ǰ�·ݵĺϷ���
		if (_month == 13){
			_month = 1;
			++_year;
		}
	}
	return *this;
}


Date& Date::operator-=(int day){
	////�ж������ĺϷ���
	//_day -= day;
	//while (day > getMonthDay(_year, _month)){
	//	day -= _day;
	//	_month--;
	//	//�ж��·ݵĺϷ���
	//	if (_month == 1){
	//		_month = 12;
	//		_year--;
	//	}
	//}

	if (day < 0){
		return *this += (-day);
	}
	_day -= day;
	while (_day <= 0){
		--_month;
		if (_month == 0){
			_month = 12;
			--_year;
		}
		_day += getMonthDay(_year, _month);
	}
	return *this;
}

//*this-d(���ߵ�ֵ����û�з����仯)
int Date::operator-(const Date& d){
	Date ret(*this);
	int flag = 1;
	if (ret < d)
		flag = -1;
	int day=0; 
	if (ret < d){
		while (ret < d){
			++ret;
			++day;
		}
	}
	else{
		while (ret>d){
			--ret;
			++day;
		}
	}
	return day*flag;
}

//++Date
Date& Date::operator++(){
	/*++_year;
	++_month;
	++_day;
	return *this;*/
	return (*this += 1);
}

//Date++
Date Date::operator++(int){
	//����++������ֵû�䣬����Date��ֵ���� 
	Date ret(*this);
	*this += 1;
	return ret;
}
Date& Date::operator--(){
	
	return (*this-=1); 
}
Date Date::operator--(int){
	Date ret(*this);
	*this -= 1;
	return ret;
}

//*this>d
bool Date::operator>(const Date& d) const{
	return _year > d._year
		|| _month > d._month
		|| _day > d._day;


	/*if (_year > d._year){
		return true;
	}*/
}
bool Date::operator<(const Date& d)const{
	return _year < d._year
		|| _month < d._month
		|| _day < d._day;
	//return !(*this >= d);
}
bool Date::operator==(const Date& d)const{
	return this->_year == d._year
		&&this->_month == d._month
		&&this->_day == d._day;
}


bool Date::operator>=(const Date& d)const{
	return (*this>d)||(*this == d);
}

bool Date::operator<=(const Date& d)const{
	return (*this < d) ||(*this == d);
}


bool Date::operator!=(const Date& d)const{
	return !(*this == d);
}

void Date:: disPlay(){
	cout << _year<<"-" << _month<<"-" << _day << endl;
}



