//#include<iostream>
//
//#include<Windows.h>
//
////此情况为static定义的函数为公有的
//using namespace std;
//class Date{
//public:
//  Date(int year){
//      _count++;
//      _year = year;
//      cout << "Date(int)" << endl;
//
//  }
//  Date(const Date& d1){
//
//      _count++;
//      _year = d1._year;
//      cout << "Dtae(const Date& d1)" << endl;
//
//  }
//
////private: //将static定义为私有成员时就不能用d1.count 的方式访问了。
//  int _year;
//  static int _count; 
//  //static定义的变量在类外面进行初始化
//};
//
//int Date::_count = 0; //static定义的变量在类外初始化
//
//Date fun1(Date d1){
//  return d1;
//
//}
//
//
//int main(){
//  Date d1(2019);
//  Date d2(2015);
//  Date d3(2015);//到此为止已经调用了3次构造函数
//  fun1(d1);    //
//  cout << d1._count<< endl;
//  cout << &d1._count << endl;
//  cout << &d2._count << endl;
//  cout << &d3._count << endl;
//  system("pause");
//  return 0;
//
//}


//#include<iostream>
//
//#include<Windows.h>
//
////此情况为static定义的函数为私有的
//using namespace std;
//
//class Date{
//
//public:
//
//  Date(int year){
//      _count++;
//      _year = year;
//      cout << "Date(int)" << endl;
//
//  }
//
//  Date(const Date& d1){
//
//      _count++;
//     _year = d1._year;
//     cout << "Dtae(const Date& d1)" << endl;
//  }
//
//  int getCount(){
//      //作用是将count 的值传到需要调用count的地方
//      return _count;
//
//  }
//
//
//
////改为静态函数后,出现错误，静态函数不能调用非静态函数     
// // static int getCount(){
// //                    //
// //       return _count;
// //  }
//private:
//  int _year;
//  static int _count;
// 
//
//};
//
//int Date::_count = 0;
//
////static定义的变量在类外初始化
//
//Date fun1(Date d1){             //fun(Date *this)
//                      //非静态函数可以调用非静态函数
//  return d1;
//}
//
//
//
//int main(){
//  Date d1(2019);
//  Date d2(2015);
//  Date d3(2015);
//  fun1(d1);
//  cout << d1.getCount() << endl;
//  system("pause");
//  return 0;
//}
//


//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//class Date{
//public:
//
//	Date(int year,int month,int day)
//	:_year(year)
//	,_month(month)
//	,_day(day)
//	{
//		cout << _year <<"-"<< _month<<"-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//int main(){
//	Date d1(2019,3,30);
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include<windows.h>
//using namespace std;
//class A{
//public:
//	//B是A的内部类,相当于B是A的友元类
//	class B{
//
//	public:
//		void display(A& a){
//			cout << a._a << endl;
//			//外部类的普通的私有成员只能通过 对象. 的方式访问
//			cout << _s << endl;          //直接访问
//			cout << a._s << endl;        //对象. 的方式访问
//			//外部类的静态的私有成员可以通过 对象. 的方式访问 也可以直接访问
//	
//		}
//	private:
//		int _b;
//
//		void Display(B& b){
//			//外部类对于内部类没有任何优越的访问权限，不能访问内部的私有成(_b)
//			cout << b._b << endl;
//		}
//
//	};
//private:
//	int _a=10;//非静态变可以直接在定义的时候初始化
//	static int _s;//静态变量必须在类外面进行初始化
//
//};
//
//int A::_s = 0;
//int main(){
//	 A::B b;
//	 A a;
//	 b.display(a);
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
//int main(){
//	string s1;
//	string s2 ("hello");
//	string s3(s2);//拷贝构造
//	string s4 = "world!";
//	//单参数的构造函数的隐式类型转换(explicit)
//	cout <<s1<< endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
////迭代器的使用
//void test_string(){
//	string num = "1234";
//	string::iterator it = num.begin();
//	while (it!=num.end()){
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}
//int main(){
//	test_string();
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//#include<windows.h>
//
//using namespace std;
//
////迭代器的使用
//void test_string( ){
//	string num = "1234";
//	string::iterator it = num.begin();
//	while (it != num.end()){
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(5);
//	vector<int> ::iterator vit = v.begin();
//	while (vit != v.end()){
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;
//
//	list<int> l;
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(6);
//
//	list<int>::iterator lit = l.begin();
//	while (lit != l.end()){
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;
//
//
//}
//int main(){
//	test_string();
//	system("pause");
//	return 0;
//}


//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//#include<windows.h>
//
//using namespace std;
//
////迭代器的使用，打印出原来的字符串方法
//void test_string(){
//	string num = "1234";
//	string::iterator it = num.begin();
//	int value = 0;
//	while (it != num.end()){
//		value *= 10;
//		value += *it - '0';
//		it++;
//	}
//	cout << value << endl;
//
//}
//
//
//void test_string1(){
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(5);
//	vector<int> ::iterator vit = v.begin();
//	while (vit != v.end()){
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;
//}
//
//
//
//void test_string2(){
//
//	list<int> l;
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(6);
//
//	list<int>::iterator lit = l.begin();
//	while (lit != l.end()){
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;
//}
//
//
//void  test_string3(){
//	string num = "1234";
//
//	//反向迭代器
//	string::reverse_iterator rit = num.rbegin();
//	while (rit != num.rend()){
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}
//int main(){
//	test_string();
//	test_string1();
//	test_string2();
//	test_string3();
//	system("pause");
//	return 0;
//}
//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//
//void  test_string3(){
//	string num = "1234";
//
//	//反向迭代器
//	string::reverse_iterator rit = num.rbegin();
//	while (rit != num.rend()){
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}
//int main(){
//
//	test_string3();
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//int StrToNum(const string& str){
//	int value=0;
//	string::const_iterator it = str.begin();
//	while (it != str.end()){
//		value *= 10;
//		value += (*it - '0');
//		++it;
//	}
//	return value;
//}
//
//void  test_string3(){
//	string num = "1234";
//
//	//反向迭代器
//	string::reverse_iterator rit = num.rbegin();
//	while (rit != num.rend()){
//		(*rit) += 1;
//		++rit;
//	}
//	cout << endl;
//	cout << StrToNum(num) << endl;
//
//}
//int main(){
//
//	test_string3();
//	system("pause");
//	return 0;
//}
//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//int StrToNum(const string& str){
//	int value = 0;
//	for (size_t i = 0; i < str.size();++i){
//		value *= 10;
//		value += (str[i]-'0');
//	}
//	return value;
//}
//
//void  test_string3(){
//	string num = "1234";
//
//	//反向迭代器
//	string::reverse_iterator rit = num.rbegin();
//	while (rit != num.rend()){
//		(*rit) += 1;
//		++rit;
//	}
//	cout << endl;
//	cout << StrToNum(num) << endl;
//
//}
//int main(){
//
//	test_string3();
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//int StrToNum(const string& str){
//	int value = 0;
//	for (auto e:str){
//		value *= 10;
//		value += (e - '0');
//	}
//	return value;
//}
//
//void  test_string(){
//	string num = "1234";
//
//	//反向迭代器
//	string::reverse_iterator rit = num.rbegin();
//	while (rit != num.rend()){
//		(*rit) += 1;
//		++rit;
//	}
//	cout << endl;
//	cout << StrToNum(num) << endl;
//
//}
//int main(){
//
//	test_string();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//int StrToNum(const string& str){
//	int value = 0;
//	for (auto e : str){
//		value *= 10;
//		value += (e - '0');
//	}
//	return value;
//}
//
//void  test_string(){
//	string num = "1234";
//
//	//反向迭代器
//	string::iterator rit = num.begin();
//	while (rit != num.end()){
//		(*rit) += 1;
//		++rit;
//	}
//	cout << endl;
//	cout << StrToNum(num) << endl;
//
//}
//int main(){
//
//	test_string();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
//void  test_string(){
//	string s("hello world!");
//	cout << s << endl;
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	//为字符串预留空间 reserve
//	s.reserve(50);
//	cout << s << endl;
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	s.resize(51);
//	//resize 空间不够的话增容，空间够的话剩余位置用
//	//0 补，若给定值得话就会把剩余位置补成给定的值
//	//s.resize(80,'1');
//	cout << s << endl;
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	
//}
//int main(){
//
//	test_string();
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
//void  test_string(){
//	string s1 = "hello";
//	s1 += ' ';
//	s1 += "world";
//	string s2 = "!!!!";
//	s1 += s2;
//	cout << s1 << endl;
//}
//int main(){
//
//	test_string();
//	system("pause");
//	return 0;
//}


#include<iostream>
#include<string>
#include<windows.h>

using namespace std;

void  test_string(){
	string s1 = "hello ";
	string s2 = "world!!";
	cout << s1 + "world!" << endl;
	cout << "hello " + s2 << endl;
	cout << s1+s2 << endl;
}
int main(){

	test_string();
	system("pause");
	return 0;
}
