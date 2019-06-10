
//#include<iostream>
////设计一个只能在堆上申请对象的类
//using namespace std;
//
//class HeapOnly{
//	friend void fun();
//public:
//	static HeapOnly* creatHeapOnly(){
//		return new HeapOnly;
//	}
//private:
//	HeapOnly(){
//		cout << "HeapOnly" << endl;
//	}
//	//HeapOnly(const HeapOnly& h) = delete;
//	//如果不将拷贝构造也"堵住"的话，还是可以将对象创建在栈上
//	//也可以将拷贝构造函数只声明不实现
//	HeapOnly(const HeapOnly& h); 
//};
//
//void fun(){
//	HeapOnly *h=HeapOnly::creatHeapOnly();
//	//HeapOnly h1(*h);
//	//如果不将拷贝构造函数delete,这种方式就可以调用拷贝构造
//}
//int main(){
//	//此时不能用HeapOnly h的方式申请对象，因为
//	//该类的构造函数已经被私有化了。
//	//HeapOnly h1(*h);
//	fun();
//	return 0;
//}
