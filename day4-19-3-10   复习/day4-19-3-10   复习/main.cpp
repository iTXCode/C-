////#include<iostream>
////#include<windows.h>
////using namespace std;
////
////class Date{
////public:
////	void Print(){
////		cout << _year << "-" << _month << "-" << _day << endl;
////	}
////	void SetDate(int year, int month, int day){
////		//����ĺ�������������Ʊ���ܿ����������ڲ��Ķ���
////		_year = year;   // ����"_ "���Ա����ͻ
////		_month = month;
////		_day = day;
////	}
////private:
////	//���������ٸ�����չƷ��
////	int _year;
////	int _month;
////	int _day;
////};
////int main(){
////	Date d1;
////	Date d2;
////	d1.SetDate(2019, 3, 9);
////	d2.SetDate(2018, 3, 9);
////	d1.Print();
////	d2.Print();
////	system("pause");
////	return 0;
////}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//
//class Date{
//public:
//
//	void Func(){
//		cout << "Date::Func()" << endl;
//	}
//	void Print(){
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	���������ٸ�����չƷ��
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main(){
//	Date* p1 = NULL;//�˴�Ϊ�գ�this������û�з��ʣ���������
//	p1->Func();
//	Date* p2 = NULL;//�˴�Ϊ�գ�������this ʱ��thisΪ��
//	���ܱ����ʣ�������
//	p2.Print();
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<windows.h>
//using namespace std;
//
//class  Date{
//public:
//	//Date(){   //  ����1
//	//	_year = 2019;
//	//	_month = 3;
//	//	_day = 10;
//	//}
//	//Date(int year, int month, int day){
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	Date (int year = 2019, int month = 3, int day = 10){
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	////////////////////////////~Date(){  //����������������
//	////////////////////////////	cout << "~Date()" << endl;
//	////////////////////////////}
//	Date ( Date& d){  
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print(){
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main(){
//	Date d1;
//	d1.Print();
//
//	Date d2(2018, 6, 30);// ����2
//	d2.Print();
//	
//
//	Date d3(2019);
//	d3.Print();
//
//	Date d4(d2);
//	d4.Print();
//
//	system("pause");
//	return 0;
//}
//
//
