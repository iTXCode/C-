
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
	friend int Sum();
	friend istream &operator>>(istream &_cin,const A&a);
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
			a.a_ = 12;
			cout << a.a_<< endl;
			//不同的变量必须通过对象.的方式访问
			cout << A::_a << endl;
			cout << _a << endl;
			//内部类可以对外部类的静态变量直接访问
			//也可以通过对象. 的和类名+作用域限定符的方式访问
			return _a;
		}
		
		
	};
	ostream &operator<<(ostream &_out){
		_out <<_a<< endl;
		return _out;
		//运算符<<重载
	}
	void disPlay(){
		cout << _a << endl;
	}
	
private:
	static int _a;
	int a_;
};

int A::_a = 0;

//友元函数的使用
istream &operator>>(istream &_cin,const A&a){
	_cin >> a._a;
	return _cin;
}


//内部类是外部类的友元类


int main(){
	A a;
	A::B b;
	cin >> a;
	a.disPlay();
	cout<<b.getA(a)<<endl;
	a<< cout;
	return 0;
}

//【注意】在一个类中申明友元类/友元函数后，
//可以在申明的函数或类中访问该类的所有成员.
//而对于内部类来说，它是外部类的友元类
//而外部类对内部类没有任何访问权限

#endif