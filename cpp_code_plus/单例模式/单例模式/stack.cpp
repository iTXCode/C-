//#include<iostream>
//
//using namespace std;
//
//class Stack{
//public:
//	static Stack getStack(){
//		return Stack();
//	}
//private:
//	Stack(){
//
//	}
//};
//class stack2{
//	///new --> opeator new-->malloc;
//	void *operator new(size_t n) = delete;
//	//放在公共的申明下，依旧不可调动
//	//无法使用被删除的函数
//private:
//	void *operator new(size_t n);
//};
//
//
//int main(){
//	//Stack *ps=new Stack;//1.开空间 2.构造(已经用delete封死)
//	Stack s = Stack::getStack();
//	Stack cp(s);  //cp在栈上
//	//stack2 ps = new stack2;
//	return 0;
//}
//
////1.构造函数私有化，间接阻止new 关键字的执行逻辑
////2.构造公共接口：在栈上创建对象
////3.在类外面无法创建对象，函数用类名调用，
////公共接口必须为static接口


#include<iostream>

using namespace std;

class Stack{
public:
	static Stack getStack(){
		return Stack();
	}
	//void *operator new(size_t n) = delete;
	//void operator delete(void *p) = delete;
private:
	Stack(){

	}
	void *operator new(size_t n);
	void operator delete(void *p);
};

int main(){
	Stack stack = Stack::getStack();
	Stack stack1(stack);
	//Stack stack3 = new Stack;
	//将new的路径删除，或者只声明不实现。
	return 0;
}