#include<iostream>
#include<stdlib.h>

using  namespace std;

void swap(int *pa, int *pb){
	int temp=*pa;
	*pa = *pb;
	*pb = temp;
	//交换的是两个参数原来地址空间中的值，
	//既原函数中定义的变量x,y的地址空间中的值被交换了
}

//void swap(int &a, int &b){
//	int temp = a;
//	a = b;
//	b = temp;
//   //交换的是两个参数原来地址空间中的值，
//   //既原函数中定义的变量x,y的地址空间中的值被交换了
//}


void  swap(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	//交换的是临时拷贝创建的空间里的值
	//其原地址空间内的值并没有被交换 
}
int main(){
	int x = 10;
	int y = 20;
	swap(&x, &y);
	swap(x, y);
	system("pause");
	return 0;
}