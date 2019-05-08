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
////		//构造的函数类似于买门票才能看到兵马用内部的东西
////		_year = year;   // 加上"_ "可以避免冲突
////		_month = month;
////		_day = day;
////	}
////private:
////	//类似与兵马俑里面的展品。
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
//	类似与兵马俑里面的展品。
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main(){
//	Date* p1 = NULL;//此处为空，this解引用没有访问，可以运行
//	p1->Func();
//	Date* p2 = NULL;//此处为空，解引用this 时，this为空
//	不能被访问，程序奔溃
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
//	//Date(){   //  特征1
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
//	////////////////////////////~Date(){  //析构函数出现问题
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
//	Date d2(2018, 6, 30);// 特征2
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
