
#define _CRT_SECURE_NO_WARNINGS 1

//代码模板  snppit
#include<stdio.h>
#include<windows.h>
#include<math.h>

int a[20], n;

int check(int k)
{
	int i;
	for (i = 1; i <= k - 1; i++)
	if ((abs(a[i] - a[k]) == abs(i - k)) || (a[i] == a[k]))
		return 0;
	return 1;
}

void output()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("%d\n", a[i]);
		if (i%n == 0)
			printf("---\n");
	}

}

void backdate(int n)
{
	int k;
	a[1] = 0;
	k = 1;
	while (k > 0)
	{
		a[k] = a[k] + 1;
		while ((a[k] <= n) && (check(k) == 0))
			a[k] = a[k] + 1;
		if (a[k] <= n)
		if (k == n)
			output();
		else
		{
			k = k + 1;
			a[k] = 0;
		}
		else
			k = k - 1;
	}
}


int  main()
{
	printf("请输入皇后的个数:");
	scanf("%d", &n);
	printf("-----\n");
	backdate(n);
	system("pause");
	return 0;
}

