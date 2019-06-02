#include<iostream>
//只能在栈上创建对象
using namespace std;

class Stack{
public:
	static Stack getStack(){
		return Stack();
	}
private:
	Stack(){

	}
	//构造函数私有化，不能创建对象，只能通过类名的方式去调用
};


class Stack2{
public:

	//new-->operator new
	void* operator new(size_t n) = delete;
};

int main(){
	Stack s = Stack::getStack();
	Stack s1(s);
	//Stack2 s2 = new Stack2;
	return 0;
}
//【总结】
//new--->operator new-->构造
//一：
//1.构造函数私有化，简介阻止new关键字的执行逻辑
//2.提供公共接口：在堆上创建对象
//3.在类外无法创建，函数用类名调用，公共接口必须是static接口

//二：
//1.重载operator new 函数，声明私有成员，并且不实现
//2.构造公有