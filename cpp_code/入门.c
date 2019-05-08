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
引用格式：类型名& 引用变量名(对象名) = 引用对象

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
	1. 做参数
	        传指针和传引用效果一样；

		示例代码：
#include<iostream>
#include<windows.h>

using namespace std;

void Swap(int *pa,int *pb){
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void Swap(int &ra,int &rb){
	int tmp = ra;
	ra = rb;
	rb = tmp;
}

int main(){
	int a = 10;
	int b = 20;
	Swap(a, b);
	Swap(&a, &b);
	system("pause");
	return 0;
}
        

		2.做返回值
		#include<iostream>
        #include<windows.h>

        using namespace std;

		int& Testfuc(int &a){
			a+=10;
			return 0;
		}
		
          int main(){
	      int a = 10;
	      int &ra=Testfuc(a);
	      system("pause");
	      return 0;
         }

		 注意：如果函数返时，离开函数作用域后，其栈上空间已经还给了系统，因此不能用栈上的
		 空间做为引用类型的返回，如果函数类型返回，返回值的生命周期必须不受函数的限制(既函数周期比较长)

#include<iostream>
#include<windows.h>
#include<time.h>

using namespace std;

int main(){
	size_t beginl = clock();
	for (int i = 0; i < 10000; i++){
		cout << "i=" << i << endl;
	}
	size_t endl = clock();
	cout << (endl- beginl) /CLOCKS_PER_SEC<< endl;
		system("pause");
	return 0;
}
//以毫秒的形式输出循环的执行时间

           引用传值的效率高于值拷贝的形式；



6.6 指针与引用的区别

引用语法层面：和指针指向同一块内存空间，引用没有开辟新的空间
引用底层实现：引用开辟新的空间，和指针的的实现相同
int a=10;                               inta=10;
mov  dword ptr [a], OAh                  mov      dword ptr [a], 0Ah

int& ra = a;                             int* pa = &a;
lea       eax, [a]                       lea  еах,[a]
 mov      dword ptr [ra], eax            mov  dword ptr [pa], eax

ra = 20;                                 *pa = 20；
mov       eax, dword ptr [ra]             mov    eax, dword ptr[ра]
mov       dword ptr [eax], 14h            mov    dword ptr [eax], 14h 



引用和指针的不同点:
6.6.1. 引用在定义时必须初始化，指针没有要求
6.6.2. 引用在初始化时引用一个实体后，就不能再引用其他实体，而指针可以在任何时候指向任何一个同类型实
体
6.6.3. 没有NULL引用，但有NULL指针
6.6.4. 在sizeof中含义不同：引用结果为引用类型的大小，但指针始终是地址空间所占字节个数(32位平台下占4
个字节)
cout << sizeof(*a)<<endl;   //结果为4
6.6.5. 引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小
6.6.6. 有多级指针，但是没有多级引用
6.6.7. 访问实体方式不同，指针需要显式解引用，引用编译器自己处理
6.6.8. 引用比指针使用起来相对更安全

7.内联函数

7.1 概念：以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数压栈的开销，
内联函数提升程序运行的效率。


inline Add(int a,int b){
	return a+b;
}
int main(){
	int ret=Add(1,3) ------->
	return 0;
}


面试题：
【面试题】宏的优缺点？
优点：
1.增强代码的复用性。
2.提高性能。
缺点：
1.不方便调试宏。（因为预编译阶段进行了替换2.导致代码可读性差，可维护性差，容易误用。
3.没有类型安全的检查 。
C++有哪些技术替代宏
1. 常量定义 换用const
2. 函数定义 换用内联函数

8.关键字auto
特点：使用auto定义变量时必须对其进行初始化，在编译阶段编译器需要根据初始化表达式来推导auto的实际类
型。因此auto并非是一种“类型”的声明，而是一个类型声明时的“占位符”，编译器在编译期会将auto替换为变
量实际的类型。

#include<iostream>
#include<windows.h>

using namespace std;
int main(){
	int a = 10;
	auto b = a;
	double c = 20.3;
	auto d = c;
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	system("pause");
	return 0;
}

//显示出了类型的名称

8.2 使用规则
8.2.1. auto与指针和引用结合起来使用
用auto声明指针类型时，用auto和auto*没有任何区别，但用auto声明引用类型时则必须加&

int main()
{
    int x = 10;
    auto a = &x;
    auto* b = &x;
    auto& c = x;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    *a = 20;
    *b = 30;
     c = 40;
    return 0;
}

8.2.2 在同一行定义多个变量
当在同一行声明多个变量时，这些变量必须是相同的类型，否则编译器将会报错，因为编译器实际只对第一个
类型进行推导，然后用推导出来的类型定义其他变量。

void TestAuto()
{
    auto a = 1, b = 2; 
    auto c = 3, d = 4.0;  // 该行代码会编译失败，因为c和d的初始化表达式类型不同
}

若同一个程序中同时定义了多个 auto ，其会根据第一个变量表达式去推导类型。


8.3 auto不能推导的场景。

8.3.1   auto不能做函数的参数

// 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
void TestAuto(auto a)
{}

8.3.2  auto不能直接用来声明

void TestAuto()
{
    int a[] = {1,2,3};
    auto b[] = {4，5，6};
}


9. 基于范围的for循环(C++11)

9.1  
for循环后的括号由冒号“ ：”分为两部分：第一部分是范围内用于迭代的变量，第二
部分则表示被迭代的范围。

#include<iostream>
#include<windows.h>

using namespace std;

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (; i < size; i++){
		cout << "arr1[i]=" << arr[i] << endl;
	}
	cout << endl;
	for (int e : arr){
		cout << "arr2[i]=" << e << endl;
	}
	cout << endl;
	for (auto& e : arr){
		cout << "arr3[i]=" <<e << endl;
	}
	system("pause");
	return 0;
}
注意：与普通循环类似，可以用continue来结束本次循环，也可以用break来跳出整个循环


9.2 范围for的使用条件
1. for循环迭代的范围必须是确定的
对于数组而言，就是数组中第一个元素和最后一个元素的范围；对于类而言，应该提供begin和end的方法，
begin和end就是for循环迭代的范围。
注意：以下代码就有问题，因为for的范围不确定
void TestFor(int array[]) 
{ 
 for(auto& e : array) 
 cout<< e <<endl; 
}


10.指针空值nullptr(C++11)


#include<iostream>
#include<windows.h>

using namespace std;

int main(){
	int *p = NULL;
	int *pp = nullptr;
	cout << typeid(pp).name() << endl;
	cout << typeid(nullptr).name() << endl;
	system("pause");
	return 0;
}
结果如下： 
//int *
//std::nullptr_t







