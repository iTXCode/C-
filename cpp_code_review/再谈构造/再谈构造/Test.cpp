#include<iostream>

using namespace std;

#if 0
class Date{
public:
	Date(int year,int month,int day){
		_year = year;
		_month = month;
		_day = day;
	}
	//���ǹ��캯���ĳ�ʼ����
	//��Ȼ���ǣ���ֻ�ܽ������ĸ���ֵ
	//��ֵ���ԵĶ�Σ�����ʼ��ֻ����һ��

private:
	int _year;
	int _month;
	int _day;
};

int main(){
	Date d(2019, 5, 31);
	return 0;
}
#endif


#if 0
//����������������ʼ���б�
//��ʼ���б���ص�����
//1.��һ��ð�ſ�ʼ
//2.��������һ�����Ÿ��������ݳ�Ա�б�
//3.ÿ������ĳ�ʼ��ֵ������������
class Date{
public:
	Date(int year,int  month,int day)
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
int main(){
	Date d(2019, 5, 31);
	return 0;
}
#endif

#if 0
//��ʼ���б���Ҫע��ĵ�
class A{
public:
	A(int a)
		:_a(a)
	{

	}
private:
	int _a;
};

class B{
public:
	B(int a, int ret)
		:_a(a)
		, _n(10)
		, _ret(ret)
		
	{
	}
private:
	A _a;//û��Ĭ�Ϲ��캯��
	int &_ret;//����
	const int _n;//const���εı���
};
//��ע�⡿
//1.ÿ����Ա����ֻ�ܳ�ʼ��һ��(��ֻ���ڳ�ʼ�����б��г���һ��)
//2.���г������ó�Ա������const���εı������������͵ĳ�Ա(����û��Ĭ�Ϲ��캯��)
//������г�ʼ��
//3.����ʹ�ó�ʼ���б���г�ʼ��
//4.��Ա���������е���������������ڳ�ʼ���б��еĳ�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�����޹�
int main(){
	return 0;
}
#endif


