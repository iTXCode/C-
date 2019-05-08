//#include<iostream>
//
//using namespace std;
//
//class Date{
//public:
//	Date(int year){
//		_year = year;
//	}
//private:
//	int _year;
//};
//
//int main(){
//	Date d1(2019);
//	Date d2 = 2018;
//	return 0;
//}
//

//#include<iostream>
//
//using namespace std;
//
//class Date{
//public:
//	explicit Date(int year){
//		_year = year;
//	}
//private:
//	int _year;
//};
//
//int main(){
//	Date d1(2019);
//	//Date d2 = 2018;
//	//当加了explicit 后这种引用方法出错
//	return 0;
//}

//#include<iostream>
//#include<Windows.h>
//
//using namespace std;
//int Count = 0;
////定义全局变量来计算函数调用的次数
////确定全局变量可以任意改动

////定义全局变量，来避免因为函数调用结束
////而使其值出现误差
//class Date{
//public:
//	Date(int year){
//		Count++;
//		_year = year;
//		cout << "Date(int)" << endl;
//	}
//	Date(const Date& d1){
//		Count++;
//		_year = d1._year;
//		//_count = d1._count;
//		//_count++;
//		cout << "Dtae(const Date& d1)" << endl;
//	}
//	/*int getcount(){
//		return _count;
//	}*/
//private:
//	int _year;
//	//int _count;
//};
//Date fun1(Date d1){
//	return d1;
//}
//
//int main(){
//	Date d1(2019);
//	//Date d2 = 2018;
//	fun1(d1);
//	cout << Count<< endl;
//	//d1.getcount();
//	system("pause");
//	return 0;
//}
//


//#include<iostream>
//#include<Windows.h>
//
////此情况为static定义的函数为公有的
//using namespace std;
//class Date{
//public:
//	Date(int year){
//		_count++;
//		_year = year;
//		
//		cout << "Date(int)" << endl;
//	}
//	Date(const Date& d1){
//		_count++;
//		_year = d1._year;
//		cout << "Dtae(const Date& d1)" << endl;
//	}
////private:
//	int _year;
//	static int _count; 
//	//static定义的变量在类外面进行初始化
//};
//
//int Date::_count = 0;
//
////static定义的变量在类外初始化
//Date fun1(Date d1){
//	return d1;
//}
//
//int main(){
//	Date d1(2019);
//	Date d2(2015);
//	Date d3(2015);
//	fun1(d1);
//	cout << d1._count<< endl;
//	cout << &d1._count << endl;
//	cout << &d2._count << endl;
//	cout << &d3._count << endl;
//	system("pause");
//	return 0;
//}
//

//#include<iostream>
//#include<Windows.h>
//
////此情况为static定义的函数为私有的
//using namespace std;
//class Date{
//public:
//	Date(int year){
//		_count++;
//		_year = year;
//
//		cout << "Date(int)" << endl;
//	}
//	Date(const Date& d1){
//		_count++;
//		_year = d1._year;
//		cout << "Dtae(const Date& d1)" << endl;
//	}
//	int getCount(){
//		//作用是将_count 的值传到需要调用_count的地方
//		return _count;
//	}
//private:
//	int _year;
//	static int _count;
//	//static定义的变量在类外面进行初始化
//};
//
//int Date::_count = 0;
//
////static定义的变量在类外初始化
//Date fun1(Date d1){
//	return d1;
//}
//
//int main(){
//	Date d1(2019);
//	Date d2(2015);
//	Date d3(2015);
//	fun1(d1);
//	cout << d1.getCount() << endl;
//	system("pause");
//	return 0;
//}
//
//

//class A{
//	//B是A的内部类,相当于B是A的内部类
//	class B{
//	public:
//		void display(A& a){
//			cout << a._a << endl;
//			//外部类的普通的私有成员只能通过 对象. 的方式访问
//			cout << _s << endl;          //直接访问
//			cout << a._s << endl;        //对象. 的方式访问
//			//外部类的静态的私有成员可以通过 对象. 的方式访问 也可以直接访问
//	private:
//		int _b;
//		}
//		void Display(B& b){
//			//外部类对于内部类没有任何优越的访问权限，不能访问内部的私有成员(_b)
//			cout << b._b << endl;
//		}
//	};
//private:
//	int _a;
//	static int _s;
//};
//


//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//class Date{
//public:
//	Date(){
//		static int count = 0;
//		cout << "调用了:"<<++count << endl;
//	}
//};
//
//int main(){
//	Date array[10];   //调用了10次
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//class A{
//public:
//	class Sum{
//	public:
//		Sum(){
//			_sum += _i;
//			++_i;
//		}
//	};
//	int Sum_solution(int n){
//		Sum arr[5];
//		return _sum;
//	}
//private:
//	static int _sum;
//	static int _i;
//};
//
//int A::_sum = 0;
//int A::_i = 1;
//int main(){
//	A a;
//	cout << a.Sum_solution(0) << endl;
//	system("pause");
//	return 0;
//}

//
//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//int main(){
//	int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	int year, month, day;
//	cin >> year>> month>> day;
//	int total = days[month - 1] + day;
//	if (month>2){
//		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)){
//			total += 1;
//		}
//	} 
//	cout << total << endl;
//	system("pause");
//	return 0;
//}
