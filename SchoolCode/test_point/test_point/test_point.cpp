#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//��ʼ����̬����
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
		scanf("%d", *(a + i) + j);//Ҳ��дΪ&a[i][i]��ע������*(a+i)+j��*(*(a+i)+j)������
	return a;

}

//�������
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
		//����C����
		c = (int **)malloc(sizeof(int*)*a_row);//ȡa��������
		for (i = 0; i < a_row; i++)
			*(c + i) = (int *)malloc(sizeof(int)*b_column);

		//��ʼ��c����,��c�����Ԫ����0
		for (i = 0; i < a_row; i++)
		for (j = 0; j < b_column; j++)
			*(*(c + i) + j) = 0;

		//����c����a*b=c;
		for (i = 0; i < a_row; i++)
		for (j = 0; j < b_column; j++)
		for (k = 0; k < a_column; k++)
			*(*(c + i) + j) += (*(*(a + i) + k))*(*(*(b + k) + j));//kΪ�ӷ���־

		return c;
	}
}
//������
int main()
{
	int a_row, a_column;
	int b_row, b_column;

	int**a, **b, **c;
	//����a
	printf("Please input the row and column of target array1:\n");
	fflush(stdout);
	scanf("%d %d", &a_row, &a_column);
	a = initialarray(a_row, a_column);
	//����b
	printf("Please input the row and column of target array2:\n");
	fflush(stdout);
	scanf("%d %d", &b_row, &b_column);
	b = initialarray(b_row, b_column);
	//����c
	c = multiplyarray(a, b, a_row, a_column, b_row, b_column);
	outputarray(c, a_row, b_column);

	return 0;
}


//#include<iostream>
//
//int main(){
//	
//	int *(p[2]);//ָ������
//	printf("%d\n",*p[0]);
//	int *q[2];
//	return 0;
//}