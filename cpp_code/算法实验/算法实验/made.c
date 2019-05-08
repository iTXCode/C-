//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include <windows.h>
//
//int n= 5, m = 4;
//int fx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 },
//fy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 },
//a[5][4];
//int dep, x, y, count;
//
//void output()
//{
//	count = count + 1;
//	printf("\n\n");
//	printf("count = %d", count);
//	for (y = 0; y < n; y++)
//	{
//		printf("\n");
//		for (x = 0; x < m; x++)
//			printf("%2d  ", a[y][x]);
//		
//	}
//}
//
//int check(int i, int j)
//{
//	int flag = 1;
//	if (i<0 || i>4 || j<0 || j>3)
//		flag = 0;
//	else if (a[i][j] != 0)
//		flag = 0;
//	return flag;
//}
//
//
//
//void find(int x, int y, int dep)
//{
//	int i, xx, yy;
//	for (i = 0; i < 8; i++)
//	{
//		xx = x + fx[i];
//		yy = y + fy[i];
//		if (check(xx, yy) == 1)
//		{
//
//			a[xx][yy] = dep;
//			if (dep == n*m)
//				output();
//			else
//				find(xx, yy, dep + 1);
//			a[xx][yy] = 0;
//		}
//	}
//}
//
//
//
//void main()
//{
//	int i, j;
//	count = 0;
//	dep = 1;
//	printf("请输入马的起始坐标(x,y):");
//	scanf("%d%d", &x,&y);
//	if (x > (n - 1 )|| y > (m - 1) || x < 0 || y < 0)
//	{
//		printf("x,y error!");
//		return;
//	}
//
//	for (i = 0; i < n; i++)
//	for (j = 0; j < m; j++)
//		a[i][j] = 0;
//	a[x][y] = 1;
//	find(x, y, 2);
//	if (count == 0)
//		printf("Non solution!");
//	system("pause");
//}
//
//
