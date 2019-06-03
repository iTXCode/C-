
#if 0
#include<iostream>

using namespace std;


class Time{
	friend class Date;
public:
	Time(int hour, int minute, int second)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << "Time(int)" << endl;
	}
	Time(const Time &t){
		cout << "Time(const Time&)" << endl;
	}

	

private:
	int _hour;
	int _minute;
	int _second;
};

class Date{
	
public:
	Date(int year,int month,int day)
		:_year(year)
		,_month(month)
		, _day(day)
	{
		cout << "Date(int)" << endl;
	}
	Date(const Date& d){
		cout << "Date(const Date&)" << endl;
	}
	void getTime(Time t){//调用一次拷贝构造
		t._hour = 12;
		t._minute = 00;
		t._second = 00;
	}
	~Date(){
		cout << "~Date()" << endl;
	}

	void  display(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;

};

int main(){
	Time t(9,36,00);
	Date d(2019,6,3);
	
	d.getTime(t);
	d.display();
	return 0;
	//程序结束的时候调用了析构函数，释放资源
}
#endif


#if 0
//内部类
#include<iostream>

using  namespace std;

class A{
public:
	A(){
		cout << "A(int)" << endl;
	}
	A(const A&a){
		cout << "A(const A&)" << endl;
	}
	~A(){
		cout << "~A()" << endl;
	}
	class B{
	public:
		static int  getA(A a){
			a._a = 10;
			return _a;
		}
		
		
	};
	ostream &operator<<(ostream &_out){
		_out <<_a<< endl;
		return _out;
		//运算符<<重载
	}
	
private:
	static int _a;
};


//内部类是外部类的友元类
int A::_a = 0;

int main(){
	A a;
	A::B b;
	cout<<b.getA(a)<<endl;
	a<< cout;
	return 0;
}

#endif