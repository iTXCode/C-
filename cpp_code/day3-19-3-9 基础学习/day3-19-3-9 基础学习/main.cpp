//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//void Swap(int *pa,int *pb){
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//void Swap(int &ra,int &rb){
//	int tmp = ra;
//	ra = rb;
//	rb = tmp;
//}
//
//int main(){
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	Swap(&a, &b);
//	system("pause");
//	return 0;
//}



//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//int& Testfuc(int &a){
//	a += 10;
//	return a;
//}
//
//int main(){
//	int a = 10;
//	int &ra = Testfuc(a);
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//#include<time.h>
//
//using namespace std;
//
//int main(){
//	size_t beginl = clock();
//	for (int i = 0; i < 10000; i++){
//		cout << "i=" << i << endl;
//	}
//	size_t endl = clock();
//	cout << (endl- beginl) /CLOCKS_PER_SEC<< endl;
//		system("pause");
//	return 0;
//}
////以毫秒的形式输出循环的执行时间

//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//int main(){
//	int a = 10;
//	auto b = a;
//	double c = 20.3;
//	auto d = c;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	system("pause");
//	return 0;
//}

//显示出了类型的名称


//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//int main(){
//	int arr[] = {1,2,3,4,5,6,7,8,9};
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (; i < size; i++){
//		cout << "arr1[i]=" << arr[i] << endl;
//	}
//	cout << endl;
//	for (int e : arr){
//		cout << "arr2[i]=" << e << endl;
//	}
//	cout << endl;
//	for (auto& e : arr){
//		cout << "arr3[i]=" <<e << endl;
//	}
//	system("pause");
//	return 0;
//}


#include<iostream>
#include<windows.h>

using namespace std;

int main(){
	int *p = NULL;
	int *pp = nullptr;
	cout << typeid(pp).name() << endl;
	cout << typeid(nullptr).name() << endl;
	system("pause");
	return 0;
}