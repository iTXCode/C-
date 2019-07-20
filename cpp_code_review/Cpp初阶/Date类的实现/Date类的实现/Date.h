#include<iostream>

using namespace std;
class Date
{
public:
	//��ȡÿ���µ�����
	int getMonthDay(int year,int month);
	//���캯��
	Date(int year , int month , int day);
	//��������
	Date(const Date& d);
	//��ֵ������
	Date& operator=(const Date& d);
	//���ڼ�����
	Date operator+(int days);
	//���ڼ�����
	Date operator-(int days);
	//�����������������������
	int operator-(const Date& d);
	//++Date(�ȸı������ٷ���)
	Date& operator++();
	//
	Date operator++(int);
	Date& operator--();
	Date& operator+=(int day);
	Date& operator-=(int day);
	Date operator--(int);
	bool operator>(const Date& d)const;
	//1.��const��const�����Ե���const��Ա����
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