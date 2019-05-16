#include<iostream>

using namespace std;

//1.命名空间中可以定义变量、函数、结构体、类
namespace A{
	int a = 10;  //定义了变量
	void b(){   //定义函数

	}
	struct test_struct {  //定义了结构体

	};
	class Person{   //定义类

	};
}


//2. 命名空间可以嵌套命名空间
namespace A{

	namespace B{   //嵌套的命名空间
		int a = 10;
	}
}

//命名空间是开放的，可以随时往其中添加内容
namespace  A{ 
	//其会和之前的命名空间A 合并
	int c = 10;
}
//5.命名空间可以是无名的
namespace {
	int d = 10;
	int e = 20;
}  //相当于定义了static int d=10 和 static int e=20;

//6.命名空间可以起别名

namespace C{
	int a = 520;
}

void test1(){
	namespace D = C;
	cout << "命名空间C下的a=" << C::a << endl;
	cout << "命名空间D下的a=" << D::a << endl;
}

//void test(){
//	cout << "命名空间A中的A="<<A::a << endl;
//	cout << "命名空间A中的A="<<A::B::a << endl;
//	cout << A::a << A::c << endl;
//}


int main(){
	test1();
	return 0;
}