//#include <iostream>
//#include<windows.h>
//using namespace std;
//class A1{
//	char _ch;
//	double _d;
//};
//class A2{
//	double _d;
//	char _ch;
//};
//int main(){
//	cout << "A1�Ĵ�С="<<sizeof(A1) << endl;
//	cout << "A2�Ĵ�С=" << sizeof(A2) << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//class Date{
//public:
//	void Print(){
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	void SetDate(int year, int month, int day){
//		//����ĺ�������������Ʊ���ܿ����������ڲ��Ķ���
//		//���к����ṩ�˷����ڲ���Ա�Ļ���
//		_year = year;   // ����"_"���Ա����ͻ
//		_month = month;
//		_day = day;
//	}
//
//private:
//	//���������ٸ�����չƷ��
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main(){
//	Date d1;
//	Date d2;
//
//	d1.SetDate(2019, 3, 9);
//	d2.SetDate(2018, 3, 9);
//
//	d1.Print();
//	d2.Print();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//class  Date{
//public:
//	Date(){ //���캯������ʼ���˱�������Ķ���
//		_year = 2019;
//		_month = 3;
//		_day = 10;
//	}
//	Date(int year, int month, int day){
//		//��������,��������ͬ,������ͬ
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print(){
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main(){
//	Date d1;//����d1һ�����ͱ���ʼ��
//	d1.Print();
//
//	Date d2(2019,3,20);
//	d2.Print();
//
//	system("pause");
//	return 0;
//}


#include<iostream>
#include<windows.h>
using namespace std;
class  Date{
public:
	Date();//�������������������涨��
	Date(int year, int month, int day){
		//��������,��������ͬ,������ͬ
		_year = year;
		_month = month;
		_day = day;
	}
	void Print(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
Date::Date(){  //���캯�������������涨��
	_year = 2019;
	_month = 3;
	_day = 10;
}

int main(){

	Date d2(2019, 3, 20);
	d2.Print();

	Date d3; //���캯�����������ж��壬Ҳ���������ⶨ��
	d3.Print();
	system("pause");
	return 0;
}