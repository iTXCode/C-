#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//初始化动态数组
int **initialarray(int a_row, int a_column)
{
	int i, j;

	int **a = NULL;

	a = (int**)malloc(sizeof(int*)*a_row);

	for (i = 0; i < a_row; i++)
		*(a + i) = (int*)malloc(sizeof(int)*a_column);

	printf("Please input Array Elements:\n");
	fflush(stdout);

	for (i = 0; i < a_row; i++)
	for (j = 0; j < a_column; j++)
		scanf("%d", *(a + i) + j);//也可写为&a[i][i]，注意区分*(a+i)+j与*(*(a+i)+j)的区别
	return a;

}

//输出矩阵
void outputarray(int **a, int a_row, int a_column)
{
	int i, j;
	int k = 0;
	printf("Output the result:\n");
	for (i = 0; i < a_row; i++){
		for (j = 0; j < a_column; j++){

			printf("%d ", *(*(a + i) + j));
			k++;
			if (a_column == k)
			{
				printf("\n");
				k = 0;
			}
		}
	}
}
// c = a * b
int ** multiplyarray(int **a, int **b, int a_row, int a_column, int b_row, int b_column)
{
	int **c;
	int i, j, k;
	if (a_column != b_row)
	{
		printf("Array1 cannot multiply Array2!");
		exit(0);
	}
	else
	{
		//构建C数组
		c = (int **)malloc(sizeof(int*)*a_row);//取a数组行数
		for (i = 0; i < a_row; i++)
			*(c + i) = (int *)malloc(sizeof(int)*b_column);

		//初始化c数组,给c数组的元素置0
		for (i = 0; i < a_row; i++)
		for (j = 0; j < b_column; j++)
			*(*(c + i) + j) = 0;

		//计算c数组a*b=c;
		for (i = 0; i < a_row; i++)
		for (j = 0; j < b_column; j++)
		for (k = 0; k < a_column; k++)
			*(*(c + i) + j) += (*(*(a + i) + k))*(*(*(b + k) + j));//k为加法标志

		return c;
	}
}
//主程序
int main()
{
	int a_row, a_column;
	int b_row, b_column;

	int**a, **b, **c;
	//数组a
	printf("Please input the row and column of target array1:\n");
	fflush(stdout);
	scanf("%d %d", &a_row, &a_column);
	a = initialarray(a_row, a_column);
	//数组b
	printf("Please input the row and column of target array2:\n");
	fflush(stdout);
	scanf("%d %d", &b_row, &b_column);
	b = initialarray(b_row, b_column);
	//数组c
	c = multiplyarray(a, b, a_row, a_column, b_row, b_column);
	outputarray(c, a_row, b_column);

	return 0;
}


//#include<iostream>
//
//int main(){
//	
//	int *(p[2]);//指针数组
//	printf("%d\n",*p[0]);
//	int *q[2];
//	return 0;
//}