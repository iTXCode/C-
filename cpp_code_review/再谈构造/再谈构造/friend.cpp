#include<iostream>
#include<stdlib.h>

using namespace std;

#if 0
class Date{
	friend void operator<<(ostream &out, Date d);
	//��Ԫ����
	//��Ԫ��ϵ���ܴ���
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

////��Ԫ��
//class Date{
//	friend class Time;
//public:
//	Date(){
//		
//	}
//	//void disPlay(Time &a){
//	//	cout << a._t << endl;
//	//	//��Ԫ��ϵ�ǵ���Ĳ����д�����
//	////�����Է��ʵ�
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////Time��Date����Ԫ�࣬����Time���п��Է���Date���еĳ�Ա
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