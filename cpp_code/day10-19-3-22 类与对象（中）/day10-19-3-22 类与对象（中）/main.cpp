//#include<iostream>
//#include<windows.h>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1){
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void print(){
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	~Date(){
//		cout << "~Date" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// ���²��Ժ�����ͨ��������
//int main(){
//	Date d1;
//	d1.print();
//
//	Date  d2(d1);   //��������
//	d2.print();
//
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1){
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main(){
//
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//d2=d1
//	//d2.operator(d1)
//	//d2.operator(&d2,d1)
//	//void operator=(const Date& d){  //Ĭ�Ϻ��е�һ�������ĵ�ַ��
//	//	//�Ѿ���thisָ����ָ��
//	//	if (this != &d){
//	//		this->_year = d._year;
//	//		this->_month = d._month;
//	//		this->_day = d._day;
//	//	}
//	//}
//	Date operator=(const Date& d){
//		if (this != &d){
//			this->_year = d._year;
//			this->_month = d._month;
//			this->_day = d._day;
//		}
//		return *this;
//	}
//		void print(){
//			cout << _year << "-" << _month << "-" << _day << endl;
//		}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main(){
//	Date d1(2018,10, 20);
//	Date d2(2019,10, 10);
//	d1.print();
//// ����d1���õı���������operator=��ɿ�����d2��d1��ֵҲ��һ���ġ�
//	Date d3(d1);  //��������
//	d1 = d2;  //��ֵ�����������
//
//	d3.print();
//	d1.print();
//	//����������ʽ��Ҫ���ú���Date operator=(const Date& d)
//	d3 = d2 = d1;//��ת���� d3=(d2.oprator=(&d2,d1))
//	d3.print();
//	system("pause");
//	return 0;
//}