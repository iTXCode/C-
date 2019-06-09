//#include<iostream>
//
//using namespace std;
//
//int main(){
//	int *p = (int*)calloc(1, sizeof(int));
//     //用calloc动态申请空间时,第一个参数看似是将你申请的空间
//	//初始化为该值，其实系统会自动初始化为0
//	cout << *p << endl;
//	free(p);
//	int* p3 = (int*)realloc(p, sizeof(int)* 10);
//  realloc用来将指定的空间扩容
//	return 0;
//}