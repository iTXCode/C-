
1.类的引入

1.1 c语言中对结构体的引用
struct ListNode
{
    int data;
    struct ListNode* next;
    struct ListNode* prev;
};
//类型：struct ListNode
//c++兼容c语言

int main(){
    struct ListNode node;
    return 0;
}

1.2 c++中也可以编过

#include<iostream>
#include<windows.h>
using namespace std;

struct ListNode
{
	int data;
	 ListNode* next;
	 ListNode* prev;
     //两个程序中的不同引用方式
};
//类型：struct ListNode
//c++兼容c语言

int main(){
	struct ListNode node;
	system("pause");
	return 0;
}


1.3 struct的双重身份

1.3.1 c语言中表示结构体。                 类型：struct ListNode   
1.3.2 C++中升级成了类。类型：ListNode ，   struct 类里面既可以定义变量，也可以定义函数

struct 是公有的，class 是私有的

2.类的定义
2.1 类的定义方式：
    class classname{
        //类体由成员变量和成员函数组成
    };  //一定要注意后面的分号

class  为关键字，classname 为类的名字 ，{}中的类为主体，注意类定义结束时后面的分号。
类中的元素称为类的成员：类的数据称为类的属性或者成员变量；类中的函数称为类的方法或者成员函数
 

2.2 类的两种定义方式

2.2.1 :  声明和定义全都放到类体中

需要注意的是：成员函数如果在类中定义，编译器可能会将其当成内联函数处理

2.2.1.1 ；声明和定义全都放到类体中
     class A{

	       //成员函数
	        void fun(){

	    }
	       //成员变量
	      int a;
	      int b;
	      int  c;
       };



2.2.1.2 :在类里面声明，在外定义
        class B{
	     void fun();
       };

        void B::fun(){
          //::作用域限定符
         }

2.2.2:声明在.h中，类的定义在.cpp中

        //b.h
         class B{
	        void fun() ;
        };
        //b.cpp  #include "p.h"
        void B::fun(){
          //::作用域解析符
         }


3.类的访问限定符及封装

3.1 访问限定符

C++实现封装的方式：用类将对象的属性与方法结合在一块，让对象更加完善，通过访问权限选择性的将其
接口提供给外部的用户使用。

访问限定符； 1.public(公有)   2.protected(保护)  3.private (私有)

      class A{
      public:
	       //成员函数
	        void fun(){

	    }
      private:
	       //成员变量
	      int a;
	      int b;
	      int  c;
       };

       int main(){
	    A x;
	    x.fun(); //可以访问到
	    x.b;//访问不到b
	    return 0;
      }

    被访问限定符修饰的变量或函数在类里面是通用的，在类外面private 修饰的变量或者函数在类外面
    不可以访问
      【访问限定符说明】
      1. public 修饰的成员在类外可以直接被访问
      2. protected 和 private 修饰的成员在类外不能直接被访问(此处 protected 和 private 是类似的)
      3. 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止
      4. class的默认访问权限为 private ， struct 为 public(因为struct要兼容C)

注意：访问限定符只在编译时有用，当数据映射到内存后，没有任何访问限定符上的区别

而 struct 定义的变量还是函数都是公有的，但  class 类中由公有的也有私有的


【面试题】
   问题：C++中struct和class的区别是什么？
   解答：C++需要兼容C语言，所以C++中struct可以当成结构体去使用。另外C++中struct还可以用来定义类。
   和class是定义类是一样的，区别是struct的成员默认访问方式是public，class是struct的成员默认访问方式
   是private。


   3.2 封装
   3.2.1 【面试题】 面向对象的三大特性：封装、继承、多态。
     在类和对象阶段，我们只研究类的封装特性，那什么是封装呢？
     封装：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来和对象进行
     交互。
    3.2.2 封装本质上是一种管理.
     


4.作用域

  4.1:类定义了一个新的作用域，类的所有成员都在类的作用域中。在类体外定义成员，需要使用 :: 作用域解析符
指明成员属于哪个类域。

class Person
{
public:
 void PrintPersonInfo();
private:
char _name[20];
 char _gender[3];
 int _age;
};
// 这里需要指定PrintPersonInfo是属于Person这个类域
void Person::PrintPersonInfo()
{
 cout<<_name<<" "_gender<<" "<<_age<<endl;
}





5.类的实例化

用类类型创建对象的过程，称为类的实例化
1. 类只是一个模型一样的东西，限定了类有哪些成员，定义出一个类并没有分配实际的内存空间来存储它
2. 一个类可以实例化出多个对象，实例化出的对象 占用实际的物理空间，存储类成员变量
3. 做个比方。类实例化出对象就像现实中使用建筑设计图建造出房子，类就像是设计图，只设计出需要什
么东西，但是并没有实体的建筑存在，同样类也只是一个设计，实例化出的对象才能实际存储数据，占用物理空间

类在计算机当中不占内存，只有来定义的对象才占内存

int a;   int--->变量类型        a---->int 类型的变量

class A( 楼房的设计图纸 )

A    ra   A --->类型    ra--->  A类型的变量  --->类的对象(按照图纸建造的房子)




6.类对象模型

结论：一个类的大小，实际就是该类中”成员变量”之和，当然也要进行内存对齐，注意空类的大小，空类比
较特殊，编译器给了空类一个字节来唯一标识这个类。


7.结构体内存对齐的规则


7.1.1. 第一个成员在与结构体偏移量为0的地址处。
7.1.2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
注意：对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
VS中默认的对齐数为8，gcc中的对齐数为4
7.1.3. 结构体总大小为：最大对齐数（所有变量类型最大者与默认对齐参数取最小）的整数倍。
7.1.4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。



8. this指针

8.1 this指针的引出


#include<iostream>
#include<windows.h>
using namespace std;

class Date{
public:
	void Print(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void SetDate(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main(){
	Date d1;
	d1.SetDate(2019, 3, 9);
	d1.Print();
	system("pause");
	return 0;
}

未完，看数。