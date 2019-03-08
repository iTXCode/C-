c++入门笔记

4.1基础的C++程序编写
#include<iostream>
#include<windows.h>
using namespace std;
//不写这句会出现cin与cout 未定义的错误

 namespace N1{
	int a = 10;
	int b = 20;
	int Add(int a, int b){
//命名空间中可以有函数的存在
		return a + b;
	}
	namespace N2{
//命名空间中可以出现嵌套式的命名空间
//引用时只需要注意调用方式即可
		int Swap(int x, int y){
			return x*y;
		}
	}
}

int main(){
	int a,b;
	cin >> a;
//c++语言的输入格式
	cin >> b;
	cout << "a=" << a << endl;
 //C++语言的输出格式，其中""中间的部分为输出的格式，而后面紧跟的
//则为输出的内容，“<<endl”表示的是“\n”->换行符
	cout <<"b=" <<b  << endl;
	cout << "a="<<N1::a << endl;
	cout << "b=" << N1::b << endl;
	cout << "a+b="<<N1::Add(a,b) << endl;
	cout << "a*b=" << N1::N2::Swap(a, b) << endl;
	system("pause");
	return 0;
}



5.函数重载
    5.1 概念：c++允许在同一作用域中声明几个功能相似的几个同名函数，这些函数的形参列表（参数的个数或类型或顺序）必须不同，
                  常用来处理实现功能类似数据类型不同的问题

//函数重载实例

#include<iostream>
#include<windows.h>

using namespace std;

int Add(int a,int b){
	return a + b;
}
double Add(double a, double b){
    //相较第一个而言形参的类型不同
	return a + b;
}
double Add(double a, int b, float c){
    //相较第一个而言形参的类型不同既个数不同
	return a + b + c;
}
int main(){
	int a = 10;
	int b = 20;
	double c = 2.0;
	double d = 3.0;
	float f = 3;
	cout<<Add(a,b)<<endl;
	cout << Add(c, d) << endl;
	cout << Add(d, a, f) << endl;
	system("pause");
	return 0;
}

   5.2名字修饰
        在c/c++中，一个程序要跑起来需要经历：预处理、编辑、汇编、链接等步骤
    5.2.1   预处理：去注释，宏替换，头文件展开
    5.2.2   汇编：语法检查，转换成汇编代码
    5.2.3   编译：汇编代码————>机器码
    5.2.4   链接：生成可执行文件

    5.2.5    在Linux下的修饰

void F1(int a);
  //——Z2F1I
         其中—Z为前缀，2代表函数名有两个字符，F1为函数名，而i(int)为参数的类型的首字母
void F1(char b);
//_Z2F1C
void F1(int a,char b);
//——Z2F1IC
     5.2.6    C语言的名字修饰规则非常简单，只是在函数名字前面加一个下划线(_函数名)，
         而在C++文件(xx.cpp)中在函数名字前面加一个  extern "c"既是告诉编辑器该函数按照c语言规则来编译

extern "c" int Add(int a,int b)
//一个函数的形式


       若需要全部都用C语言的风格来编辑，形式如下
extern "c"{
	C语言代码很多行;
}

函数重载总结


  1   C语言不支持，C++支持
  2   特点：函数名相同，参数不同(1.类型不同。2.顺序不同 3.参数个数不同)
  3   C++语言支持重载：函数名修饰规则　name mangling
  4   C语言中底层函数名："_" + 函数名
  5   C++底层函数名： 前缀+函数名+参数类型首字母


6：引用

     6.1 引用概念：引用不是重新定义了一个变量，而是给已经存在的变量取个别名，编译器不会为
	     引用变量开辟内存空间。它和它引用的变量公用同一块内存空间

示例代码如下：

#include<iostream>
#include<windows.h>

using namespace std;

void Testfun(){
	int a = 10;
	int &ra = a;
	cout << ra  << endl;
	//结果出现一个10
	cout << ra <<endl<< a<<endl;
	//结果出现两个10
}

int main(){
	Testfun();
	system("pause");
	return 0;
}
监视结果：&ra=&a,ra=a=10;

注意点： 引用类型和引用实体必须是相同类型的

        上例中如果出现  double &ra=a;  则会报错




    6.2 引用特性
	    1.引用在定义时必须初始化
		错误示例： int &ra;
		2.一个变量可以有多个引用
		正确示例：
		int a=10;
		int &ra=a;
		int &rra=a;
		int &rrra=a;
		3.引用一旦引用一个实体则不能在引用其他实体



	6.3 常引用

	void TestContRef(){
		const int a=10;
		//int & ra=1;   //该语句编译时出错，a为常量
		const int &ra=a;
		//int& b=10;    //该语句编译时出错，b为常量
		const int& b=10;
		double d=12.34;
		const int& rd==d;
		//隐式类型转换--->临时变量具有常性
		int c=d;
		//int& rd=d;     //该语句编译时出错，类型不同
		const int& rd=d;
		
	}

	6.4   使用场景
        
        