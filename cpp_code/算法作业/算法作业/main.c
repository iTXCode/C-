//#include<stdio.h>
//#include <windows.h>
//void Search(int i, int j);
//void Out();
//int Check(int i, int j, int k);
//int maze[8][8] = {
//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 1, 1, 1, 1, 0, 1, 0 },
//	{ 0, 0, 0, 0, 1, 0, 1, 0 },
//	{ 0, 1, 0, 0, 0, 0, 1, 0 },
//	{ 0, 1, 0, 1, 1, 0, 1, 0 },
//	{ 0, 1, 0, 0, 0, 0, 1, 1 },
//	{ 0, 1, 0, 0, 1, 0, 0, 0 },
//	{ 0, 1, 1, 1, 1, 1, 1, 0 }
//};
//int fx[4] = { 1, -1, 0, 0 };
//int fy[4] = { 0, 0, -1, 1 };
//int i, j, k, total;
//int main()
//{
//	int total = 0;
//	maze[0][0] = 3;
//	Search(0, 0);
//	system("pause");
//	return 0;
//}
//void Search(int i, int j)
//{
//	int k, newi, newj;
//	for (k = 0; k <= 3; k = k + 1)
//	if (Check(i, j, k) == 1)
//	{
//		newi = i + fx[k];
//		newj = j + fy[k];
//		maze[newi][newj] = 3;
//		if (newi == 7 && newj == 7)
//			Out();
//		else
//			Search(newi, newj);
//	}
//	maze[i][j] = 2;
//}
//void Out()
//{
//	int i, j;
//	for (i = 0; i <= 7; i++)
//	{
//		printf("\n");
//		for (j = 0; j <= 7; j++)
//		if (maze[i][j] == 3)
//		{
//			printf("V");
//			total = total + 1;
//		}
//		else
//			printf("*");
//	}
//	printf("%d", total);
//}
//int Check(int i, int j, int k)
//{
//	int flag = 1;
//	i = i + fx[k];
//	j = j + fy[k];
//	if (i<0 || i>7 || j<0 || j>7)
//		flag = 0;
//	else if (maze[i][j] != 0)
//		flag = 0;
//	return(flag);
//}




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int main()
{
	int i, j, k, m, n, rest, a[100][100], gain[100];
	float q[100], f[100], temp[100];
	printf("how many items?\n");
	scanf("%d", &m);
	printf("how many money?\n");
	scanf("%d", &n);
	printf("please input one item gain table:\n");
	for (j = 0; j <= n; j++)
	{
		scanf("%f", &q[j]);
		f[j] = q[j];
	}
	for (j = 0; j <= n; j++)
		a[1][j] = j;
	for (k = 2; k <= m; k++)
	{
		printf("input another item gain table:\n");
		for (j = 0; j <= n; j++)
		{
			temp[j] = q[j];
			scanf("%f", &q[j]);
			a[k][j] = 0;
		}
		for (j = 0; j <= n; j++)
		for (i = 0; i <= j; i++)
		if (f[j - i] + q[i] > temp[j])
		{
			temp[j] = f[j - i] + q[i];
			a[k][j] = i;
		}
		for (j = 0; j <= n; j++)
			f[j] = temp[j];
	}
	rest = n;
	for (i = m; i >= 1; i--)
	{
		gain[i] = a[i][rest];
		rest = rest - gain[i];
	}

	for (i = 1; i <= m; i++)
		printf("%f ", gain[i]);
	printf("%f", f[n]);
	system("pause");
	return 0;
}