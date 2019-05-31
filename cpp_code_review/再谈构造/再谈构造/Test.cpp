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
	//这是构造函数的初始化吗？
	//当然不是，这只能叫做语句的赋初值
	//赋值可以的多次，而初始化只能有一次

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
//下面我们来看看初始化列表
//初始化列表的特点如下
//1.以一个冒号开始
//2.接着是以一个逗号隔开的数据成员列表
//3.每个对象的初始化值都放在括号内
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
//初始化列表需要注意的点
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
	A _a;//没有默认构造函数
	int &_ret;//引用
	const int _n;//const修饰的变量
};
//【注意】
//1.每个成员变量只能初始化一次(既只能在初始化泪列表中出现一次)
//2.类中出现引用成员变量、const修饰的变量或者类类型的成员(该类没有默认构造函数)
//必须进行初始化
//3.尽量使用初始化列表进行初始化
//4.成员变量在类中的声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关
int main(){
	return 0;
}
#endif


