//#include<iostream>
//#include<stdlib.h>
//
//
//using namespace std;
//
//class Person{
//public:
//	char name;//1
//	int age;//8
//	char sex;//1
//	char Adress;//10
//private:
//	char id;//11
//	int  acount;//15
//	//最终对齐数为默认对齐数的整数倍16
//};
//
//class A{ //类的大小为1
//public:
//	void fun(){  //在代码共享段,在栈上独立. 谁需要谁调用，不在类A
//               //内部
//		int b= 10;  
//	}
//};
//
//
////类中可以嵌套类
//class B{
//
//public:
//	//在类B中定义了一个嵌套的类 BB
//	//B中不包含声明的嵌套的类BB所定义的变量(对象)
//	//所以类B的对齐数任然为1
//   // 两者相互独立,没有从属关系
//	class BB{
//	public:
//		int a = 10;
//	};
////class A4   
////{  //内嵌的类相当于这样
////	int;
////};

//	
//};


//int main(){
//
//	int x = 1024;
//	Person p;
//	p.Adress='陕西';
//	p.age = 10;
//	p.name = 'jun';
//	p.sex = '男';
//	//只能访问到类中的公有成员，此时用'.'操作符访问不到
//	//Person类中的私有成员
//	cout << sizeof(p) << endl;  //16
//
//	Person *pp;
//	pp->Adress;
//
//	A a;
//	a.fun();
//	cout << sizeof(a) << endl;  //1
//
//
//	B b;
//	//b.BB; //显示不允许使用类型名
//	//提示IntelliSense: 不允许使用类型名	
//
//	B::BB bb;
//	cout << sizeof(b) << endl;//大小为1
//	cout << sizeof(bb) << endl; //大小为4
//	system("pause");
//	return 0;
//}
//
////【总结】:
////空类的内存对齐数为1,表示它确实存在于内存中
////定义类中只定义一个void型的函数，实例化后的对象的内存对齐数为1
////说明其实例化的对象中没有存放函数
////【注意】：sizeof不能用来计算函数的大小。
////【补充1】:类定义的对象访问类中的成员用"."操作符
////         类定义的指针访问类中的成员用"->"来访问
//
////【补充2】:大端：低地址存放高位，高地址存放低位
////          小端：低地址存低位，高地址存高位
