//#include<iostream>
//using namespace std;
//int main(){
//	int *pa = new int;
//	//new 为关键字， 而int 为需要申请的空间类型 
//	int *pb = new int(1);
//    //申请一块空间，并且初始值赋为 1
//	delete pb;
//	//c++释放单个空间的方式
//	int *pc = new int[10];
//	//申请一块连续的空间，空间为10个int类型的空间大小为 40 字节
//	delete[]pc;
//	//c++释放连续空间的方式
//	//new/delete     new[]/delete []
//	return 0;
//}




//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//
//class A{
//private:
//	int _a;
//	int _b;
//};
//int main(){
//	A* pa = (A *)malloc(sizeof(A));
//	free(pa);
//	A *pb = new A;
//	delete pb;
//	A *pc = new A[10];
//	delete[]pc;
//	return 0;
//}

//#include<iostream>
//#include<stdlib.h>
//#include<windows.h>
//using namespace std;
//
//class A{
//public:
//	~A(){
//		//释放空间
//		//if(_pi){
//		//free(_pi);
//		//_pi=nullptr;
//		//}
//		cout << "~A" << endl;
//	}
//private:
//	int _a;
//	int _b;
//	int *_pi;
//	//加入申请了空间
//};
//int main(){
//	A* pa = (A *)malloc(sizeof(A));
//	free(pa);
//	A *pb = new A;
//	delete pb;
//	A *pc = new A[10];
//	delete[] pc;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<stdlib.h>
//#include<windows.h>
//using namespace std;
//
//class A{
//public:
//	A(){
//		cout << "A" << endl;
//	}
//
//	~A(){
//		//释放空间
//		//if(_pi){
//		//free(_pi);
//		//_pi=nullptr;
//		cout << "~A" << endl;
//	}
//private:
//	int _a;
//	int _b;
//	int *_pi;
//	//加入申请了空间
//};
//int main(){
//	/*A* pa = (A *)malloc(sizeof(A));
//	free(pa);*/
//	A *pb = new A;
//	//new 调用自定义类型的构造函数，malloc不会
//	delete pb;
//	//delete 调用自定义类型的析构函数，free不会 
//	/*A *pc = new A[10];
//	delete[] pc;*/
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//
//int main(){
//	//两种处理异常的方式
//	cout << "malloc:" << endl;
//	char *p = (char*)malloc(0x7ffffffff);
//	cout << (void*)p << endl;
//	cout << "new:" << endl;
//	try{
//		char *p = new char[0X7fffffff];
//		cout << (void*)p << endl;
//	}
//	catch (exception& e){
//		cout << e.what() << endl;
//		//特殊接口：e.what()
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//using namespace std;
//
//int main(){
//	//两种处理异常的方式
//	cout << "malloc:" << endl;
//	char *p = (char*)malloc(0x7ffffffff);
//	cout << (void*)p << endl;
//	free(p);
//	cout << "new:" << endl;
//	try{
//		char *p = new char[0X7fffffff];
//		cout << (void*)p << endl;
//	}
//	catch (exception& e){
//		cout << e.what() << endl;
//		//特殊接口：e.what()
//	}
//	//operator new:malloc + 异常
//	system("pause");
//	return 0;
//}