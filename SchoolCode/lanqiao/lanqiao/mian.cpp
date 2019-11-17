#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include<iostream>

void fun(char* str){
	while (*str!='\0'){
		if (*str == 'a'){
			printf("a");
			return;
		}
		else if (*str == 'e'){
			printf("e");
			return;
		}
		else if (*str == 'i'){
			printf("i");
			return;
		}
		else if (*str == 'o'){
			printf("o");
			return;
		}
		else if (*str == 'u'){
			printf("u");
			return;
		}
		str++;
	}
	printf("n");
	return;
}
int main(){
	char str[24];
	scanf("%s",str);
	fflush(stdin);
	fun(str);
	return 0;
}
#endif 


#if  0
#include<iostream>

int Function(int num){
	int n = num;
	while (n>0){
		int x = n % 10;
		if (x == 2){
			return 0;
		}
		n =n/10;
	}
	return 1;
}
int main(){
	int num;
	
	scanf("%d",&num);
	int number=0;
	for (int i = 1; i <= num; i++){
	number += Function(i);
	}
	printf("%d\n",number);
	return 0;
}
#endif 


//#include<stdio.h>
//
//int Fun(int num,int x,int y,int z){
//	if (num%x != 0 && num%y != 0 && num%z != 0){
//		return 1;
//	}
//	return 0;
//}
//int main(){
//	int num = 0;
//	int x, y, z;
//	scanf("%d",&num);
//	scanf("%d %d %d", &x, &y, &z);
//	int size = 0;
//	for (int i = 1; i <= num; i++){
//		size += Fun(i, x, y, z);
//	}
//	printf("%d\n",size);
//	return 0;
//}


#include<stdio.h>
#include<malloc.h>

int **array_Init(int x,int y){
	int **a = NULL;
	a = (int **)malloc(sizeof(int*)*x);
	for (int i = 0; i < y; i++){
		*(a + i) = (int *)malloc(sizeof(int)*y);
	}
	int k = 1;
	for (int n = 0; n <= x / 2; n++)
	{
		for (int j = n; j <= y - n - 1; j++)   //上
			*(*(a+n)+j)= k++;
		for (int i = n + 1; i<x - n - 1; i++) //右
			*((*(a+i))+y - n - 1) = k++;
		for (int j = y - n - 1; j>n; j--)//下
			*(*(a+x - n - 1)+j) = k++;
		for (int i = x - n - 1; i > n; i--)//左
		    *(*(a+i)+n) = k++;
	}

	return a;
}


int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int **arr=array_Init(n,m);
	int p_x, p_y;
	scanf("%d %d",&p_x,&p_y );
	printf("%d\n",arr[p_x-1][p_y-1]);
	return 0;
}


//#include<stdio.h>
//#include<malloc.h>
//
//
//void Print_array(char **a, int x, int y){
//	for (int i = 1; i < x-1; i++){
//		for (int j = 1; j < y-1; j++){
//			printf("%c ", *(*(a + i) + j));
//		} 
//		printf("\n");
//	}
//}
//char **Arr_Init(int x, int y){
//	char **a = NULL;
//	a = (char **)malloc(sizeof(char*)*x);
//	for (int i = 0; i < x; i++){
//		*(a + i) = (char *)malloc(sizeof(char)*y);
//	}
//
//	for (int i = 0; i < x ; i++){
//		for (int j = 0; j < y ; j++){
//			*(*(a + i) + j )= '0';
//		}
//	}
//
//	for (int i = 1; i <x-1; i++){
//		for (int j = 1; j < y-1; j++){
//			scanf("%c",*(a + i) + j);
//		}
//		getchar();
//	}
//	return a;
//}
//
//void Fun(char** arr,int x,int y){
//	for (int i = 1; i < x-1; i++){
//		for (int j = 1;j < y-1; j++){
//			if (*(*(arr + i) + j) == 'g'){
//				if ((*(*arr + i - 1) + j) != '0'){
//					*(*(arr + i - 1) + j)= 'g';
//				}
//				 if (*(*(arr + i + 1) + j) != '0'){
//					*(*(arr + i +1) + j) = 'g';
//				}
//			    if (*(*(arr + i ) + j-1) != '0'){
//					*(*(arr + i ) + j-1) = 'g';
//				}
//				  if (*(*(arr + i) + j +1) != '0'){
//					*(*(arr + i) + j + 1) = 'g';
//				}
//			}
//		}
//	}
//}
//int main(){
//	int n = 0, m = 0;
//	scanf("%d %d", &n, &m);
//	getchar();
//	char **arr=Arr_Init(n+2, m+2);
//	Fun(arr, n, m);
//	Print_array(arr, n+2, m+2);
//	return 0;
//}