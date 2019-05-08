//#include<iostream>
//#include<windows.h>
//#include<time.h>
//using namespace std;
//struct A{
//public:
//	int a[10000];
//};
//A a;
//
//A TestFunc1(){
//	return a;
//}
//
//
//A& TestFunc2(){
//	return a;
//}
//
//void TestReturnByRefOrValue{
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	
//	size_t begin2 = clock( );
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2();
//
//	size_t end2 = clock();
//
//	cout << "TestFunc1 time:" << end1 - begin1/CLOCKS_PER_SEC << endl;
//	cout << "TestFunc2 time:" << end2 - begin2/CLOCKS_PER_SEC << endl;
//}
//
//int main(){
//	for (int i = 0; i < 10; ++i){
//		TestReturnByRefOrValue();
//	}
//	system("pause");
//	return 0;
//}



//#include<iostream>
//#include<windows.h>
//
//
//using namespace std;
//
//int main(){
//	int a = 10;
//	int& ra = a;
//	cout << &a << endl;
//	cout << &ra << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<windows.h>
//
//
//using namespace std;
//
//int main(){
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	int *pa = &a;
//	*pa = 20;
//	//可以通过引用名来改变原来的对象值
//	cout << a << endl;
//	cout << ra << endl;
//	cout << *pa << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<windows.h>
//
//
//using namespace std;
//
//int main(){
//	int a = 10;
//	int b = 10;
//	int& ra = a;
//	ra = 20;
//	//int& ra= b;//若为ra 编译器会显示重复定义 ra
//	int& rb = b;
//	cout << ra << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<windows.h>
//
//
//using namespace std;
//
//
//inline int Add(int a,int b){
//	return a + b;
//}
//int main(){
//	int ret = 0;
//	int a = 10;
//	int b = 20;
//	ret = Add(a,b);
//	cout << "Add(a,b)=" << ret << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//
//
//using namespace std;
//
//
//int TestAuto(){
//	return 1;
//}
//
//int main(){
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//
//int main(){
//	int a = 10;
//	auto b = &a;
//	auto* c = &a;
//	auto& d= a;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	system("pause");
//	return 0;
//}
//
//
