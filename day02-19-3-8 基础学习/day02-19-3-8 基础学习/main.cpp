#define _CRT_SECURE_NO_WARNINGS 1
//
////#include<iostream>
////#include<windows.h>
////using namespace std;
////不写这句会出现cin与cout 未定义的错误
////
//// namespace N1{
////	int a = 10;
////	int b = 20;
////	int Add(int a, int b){
////命名空间中可以有函数的存在
////		return a + b;
////	}
////	namespace N2{
////命名空间中可以出现嵌套式的命名空间
////引用时只需要注意调用方式即可
////		int Swap(int x, int y){
////			return x*y;
////		}
////	}
////}
////
////int main(){
////	int a,b;
////	cin >> a;
////c++语言的输入格式
////	cin >> b;
////	cout << "a=" << a << endl;
//// C++语言的输出格式，其中""中间的部分为输出的格式，而后面紧跟的
////则为输出的内容，“<<endl”表示的是“\n”->换行符
////	cout <<"b=" <<b  << endl;
////	cout << "a="<<N1::a << endl;
////	cout << "b=" << N1::b << endl;
////	cout << "a+b="<<N1::Add(a,b) << endl;
////	cout << "a*b=" << N1::N2::Swap(a, b) << endl;
////	system("pause");
////	return 0;
////}

//因该特别注意C语言与C++语言的语法的不同；

//F.h
//F.cpp
//main.cpp


//1.预处理  头文件展开/宏替换/条件编译/注释删除。。。。
//F.i  main.i
//2.编译  语法检查,生成汇编代码
//F.s  Main.s
// int i=1;
//i += 1; 

//3.汇编  转成机器码
//F.o  main.o
//4。链接
//


//a.out 可执行程序


//./a.out 


//终端父进程 fork 子进程，waitpid  

//


//#include<iostream>
//using namespace std;
//
//
//int main(){
//	int a = 10;
//	cout << a << endl;
//	return 0;
//}



//函数重载
//
//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//int Add(int a,int b){
//	return a + b;
//}
//
//double Add(double a, double b){
//	return a + b;
//}
//double Add(double a, int b, float c){
//	return a + b + c;
//}
//int main(){
//	int a = 10;
//	int b = 20;
//	double c = 2.0;
//	double d = 3.0;
//	float f = 3;
//	cout<<Add(a,b)<<endl;
//	cout << Add(c, d) << endl;
//	cout << Add(d, a, f) << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//void Testfun(){
//	int a = 10;
//	int &ra = a;
//	cout << ra  << endl;
//	//结果出现一个10
//	cout << ra <<endl<< a<<endl;
//	//结果出现两个10
//}
//
//int main(){
//	Testfun();
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<windows.h>

using namespace std;

int& Add(int a, int b){
	int c = a + b;
	return c;
}

int main(){
	int &rd = Add(1, 2);
	cout << "Add(1,2)=" << rd << endl;
	system("pause"); 
	return 0;
}