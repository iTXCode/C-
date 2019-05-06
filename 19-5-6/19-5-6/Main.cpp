#include<iostream>
#include<windows.h>

using namespace std;

class Date{
public:
	Date(int year,int month,int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << _year<<"Äê:" << _month<<"ÔÂ:" << _day<<"ÈÕ" << endl;
	}
	~Date(){

	}
private:
	int _year;
	int _month;
	int _day;
};
void Add(int num1, int num2){
	cout << num1 + num2 << endl;
}
void Add( int num2){
	cout << 2* num2 << endl;
}
void Add(double num1, double num2){
	cout << num1 + num2 << endl;
}
int main(){
	int a = 12;
	int &ra = a;
	cout << "a="<<a << endl;
	cout << "*(&a)=" << *(&a) << endl;
	cout << "&a=" << &a << endl;
	cout << "ra="<<ra << endl;
	cout << "&ra=" << &ra << endl;
	Date date(1997,8,1);
	Add(1,2);
	Add(2);
	Add(1.0,2.0);
	system("pause");
	return 0;
}