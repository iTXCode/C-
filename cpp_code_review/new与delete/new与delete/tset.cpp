#if 0
#include<iostream>

using namespace std;

class A{
public:
	A(){
		cout << "A(int)" << endl;
	}
	~A(){
		cout << "~A()" << endl;
	}
private:
	int _a;
};


int main(){
	/*A *pa = (A*)malloc(sizeof(A));
	free(pa);*/
	//free 不会调用析构函数
	
	//A *pb = new A;
	//new会调用自定义类型构造函数，malloc不会
	//new-->operator new -->构造函数
	//delete pb;
	//delete-->析构-->operator delete
	 //delete会调用自定义类型的析构函数，free不会 
	//A *pc = new A[10];

	//delete[] pc;

	int *p = new int(2);
	//申请空间并且进行初始化
	delete p;
	//这种方式会报错
	//int *p = (int*)operator new(sizeof(int));
	//operator delete(p);
	return 0;
}

//operator new 底层：malloc+异常
//operator delete :free

#endif

//【总结】new/delete:
//自定义类型:new malloc delete free
// new :operator new--->malloc +构造
//malloc:malloc

//new[N]:operator new [N]-->operator new -->malloc +N次构造

//delete：构造+operator delete--》free
//free:free

//delete[]:N(析构+operator delete --->free)


//内置类型：
//new ;malloc+异常
//malloc:malloc

//delete:分装free
//free:free