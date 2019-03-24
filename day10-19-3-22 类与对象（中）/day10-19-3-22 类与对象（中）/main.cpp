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
//// 以下测试函数能通过编译吗？
//int main(){
//	Date d1;
//	d1.print();
//
//	Date  d2(d1);   //拷贝构造
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
//	//void operator=(const Date& d){  //默认含有第一个参数的地址，
//	//	//已经被this指针所指代
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
//// 这里d1调用的编译器生成operator=完成拷贝，d2和d1的值也是一样的。
//	Date d3(d1);  //拷贝构造
//	d1 = d2;  //赋值运算符的用运
//
//	d3.print();
//	d1.print();
//	//用运这个表达式需要调用函数Date operator=(const Date& d)
//	d3 = d2 = d1;//被转换成 d3=(d2.oprator=(&d2,d1))
//	d3.print();
//	system("pause");
//	return 0;
//}