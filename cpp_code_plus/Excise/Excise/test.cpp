
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
	void getTime(Time t){//����һ�ο�������
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
	//���������ʱ������������������ͷ���Դ
}
#endif



#if 0

//�ڲ���
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
			//��ͬ�ı�������ͨ������.�ķ�ʽ����
			cout << A::_a << endl;
			cout << _a << endl;
			//�ڲ�����Զ��ⲿ��ľ�̬����ֱ�ӷ���
			//Ҳ����ͨ������. �ĺ�����+�������޶����ķ�ʽ����
			return _a;
		}
		
		
	};
	ostream &operator<<(ostream &_out){
		_out <<_a<< endl;
		return _out;
		//�����<<����
	}
	void disPlay(){
		cout << _a << endl;
	}
	
private:
	static int _a;
	int a_;
};

int A::_a = 0;

//��Ԫ������ʹ��
istream &operator>>(istream &_cin,const A&a){
	_cin >> a._a;
	return _cin;
}


//�ڲ������ⲿ�����Ԫ��


int main(){
	A a;
	A::B b;
	cin >> a;
	a.disPlay();
	cout<<b.getA(a)<<endl;
	a<< cout;
	return 0;
}

//��ע�⡿��һ������������Ԫ��/��Ԫ������
//�����������ĺ��������з��ʸ�������г�Ա.
//�������ڲ�����˵�������ⲿ�����Ԫ��
//���ⲿ����ڲ���û���κη���Ȩ��

#endif