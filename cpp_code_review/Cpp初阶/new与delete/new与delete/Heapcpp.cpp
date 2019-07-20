//只能在堆上创建对象
#if 0
#include<iostream>

using namespace std;


class Heap{
	friend void fun1();
public:
	static Heap *getheap(){
		return new Heap;
	}
	Heap(const Heap& hp) = delete;
private:
	Heap(){}
};

void fun1(){
	Heap *hp = Heap::getheap();
	//Heap hp2(*hp);
}
//【只能在堆上创建对像的类】
//1.构造函数私有化
//2.提供公共接口:在堆上创建对象
//3.在类外无法创建对象，函数用类名去调用，公共接口必须为static接口
//4.防止拷贝
//<1>:拷贝构造私有化，只声明不实现
//<2>:拷贝构造声明成delete函数(c++11特性)
int main(){
	Heap *hp = Heap::getheap();
	//Heap hp2(*hp);
	return 0;
}

#endif