////6大成员函数
//
//#include<iostream>
//#include<stdlib.h>
//
//using namespace std;
//
//
//class A{
//	//【偏见改正】:没有成员的的类简称为空类，
//    //但是空类中并不是没有任何内容，任何一个类在
//	//程序员不写内容的情况下会自动生成6个默认成员函数
//};
//
//
//class Date{
//public :
//	//1.构造函数(初始化)
//	//1.函数名和类名相同，2.没有返回值，3.定义一个对象后
//	//不需要显示的调用构造函数，编译器自动调用构造函数对对象进行初始化
//	//4.可以重载
//	Date(int year,int month,int day){
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date()   //默认构造函数，在不写构造函数的情况下，编译器自动生成
//	//{}        //如果用户显示的定义了构造函数，编译器将不再生成
//	//默认构造函数:全缺省
//	//【注意】默认构造函数只能有一个
//	Date(int year = 1997, int month = 1){
//		_year = year;
//		_month =month;
//		
//	}
//
//
//	
//
//	void disPaly(){
//		cout << _year <<"-"<< _month<<"-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
////【补充】:作用限定符在类中是没有限定作用的，只对类外定义的变量等 
////有限定作用，在类中不标明作用限定符的时候，其作用限定默认是私有的
//};
//
//
//int main(){
//	Date d1(2019,5,26);
//	//Date d2(); //【注意】这种形式不是调用无参构造函数，其定义了一个
//	//Date类型的函数，函数返回值类型为Date
//	//正确的无参构造函数的调用方式(Data d2);
//	Date d2;
//
//	A a;   //调用的是无参的构造函数，
//	d1.disPaly();
//	system("pause");
//	return 0;
//}





//#include<iostream>
//#include<stdlib.h>
//
//using namespace std;
//
//class Date{
//public:
//	Date(){
//
//	}
//
//	~Date(){
//		cout << "~Date()" << endl;
//	}
//	
////析构函数
////【特点】：1.名字与类名相同，在名字前面加一个"~"
////          2.无返回值
////          3.一个类只能由一个析构函数
////          4.对象生命周期结束时。编译器自动调用析构函数
////【作用】:对象在销毁时会自动调用析构函数，完成类的一些资源清理工作
//
//private:
//	int _month;
//};
//
//int main(){
//	Date d;
//	//system("pause");
//	return 0;
//}





//#include<iostream>
//#include<stdlib.h>
//
//using namespace std;
//
//class Date{
//public:
//	Date(int year, int month){
//		_year = year;
//		_month = month;
//	}
//	void disPlay(){
//		cout << _year << "-" << _month<< endl;
//	}
//	//【拷贝构造】
//	//【特点】：
//	//1.拷贝构造函数是构造函数的一个重载形式
//	//2.拷贝构造的参数只有一个且必须使用引用传参，使用传值方式会引发无穷递归
//	Date(const Date& d1){
//		_year = d1._year;
//		_month = d1._month;
//	}
//
//private:
//	int _year;
//	int _month;
//};
//	
//
//int main(){
//	Date d(2019,5);
//	Date d1(d);  
//	//拷贝构造的使用格式(括号中的是你要拷贝的对象)
//	d.disPlay();
//	d1.disPlay();
//	//两者的输出结果相同
//	system("pause");
//	return 0;
//}
////【注】:拷贝构造参数必须使用引用传参，不能以传值的形式传参
////原因：如果拷贝构造的参数不是引用而是值传递，
////值传递就会发生值拷贝从而继续调用拷贝构造函数
////如果使用引用的话，参数是拷贝对象的别名没有发生值拷贝




//#include<iostream>
//#include<stdlib.h>
//
//using namespace std;
//
//class Date{
//public:
//	
//	Date(){
//		_year = 1997;
//		_month = 2;
//	}
//	bool operator==(const Date& d2){  //bool operator(Date *this,Date &d2)
//		return this->_year == d2._year
//			&&this->_month == d2._month;
//	}
//
//	//赋值运算符重载
//	void operator=(const Date&d1){
//		//要避免自己给自己赋值
//		if (this != &d1){
//		_year = d1._year;
//		_month = d1._month;
//		}
//	}
//
//	void disPlay(){
//		cout << _year << "-" << _month << endl;
//	}
//
//
//	
////private:
//	int _year;
//	int _month;
//};
//
//int operator+(Date &d1, int b)
//{
//	return d1._month + b;
//} 
//
////【运算符重载】
////【特点】:1.不能通过连接其他符号来创建新的操作符：比如operator@
////         2.重载操作符必须有一个类类型或者枚举类型的操作数
////         3.用于内置类型的操作符，其含义不能改变，
////          例如：内置的整型+，不能改变其含义
////         4.作为类成员的重载函数时，其形参看起来比操作数数
////         目少1成员函数的操作符有一个默认的形参this，限定为第一个形参
////         5. < .* >< ::  > < sizeof  > <  ?:  >< . >
////         注意以上5个运算符不能重载。
//
//bool operator==(const Date& d1, const Date& d2){
//	return d1._year == d2._year
//		&&d1._month == d2._month;
//}
//
//
//int main(){
//	Date d;
//	Date d1;
//
//	bool d2 = (d ==d1);
//	cout << "d==d1的结果为  " << d2 << endl;
//	cout << "d.operator==d1的结果为  " << (d.operator==(d1))<< endl;
//	//两种方式相同，只是一个在类里面调用一个在类外面调用
//	//运算符重载可读性更强
//	int b = 10;
//	int c = d1 + b;
//	cout << "c=" << c << endl;
//	d1.disPlay();
//	Date d3 = d;//这样调用的是拷贝构造
//	//拷贝构造一个新对象
//	Date d4;
//	d4 = d;  //这样才会调用赋值运算符重载
//	//d的值赋给d4
//	//d4 = d3 = d; 
//	//若要这样使用的话，赋值运算符重载函数需要一个返回值
//	//return *this;
//	system("pause");
//	return 0;
//}



