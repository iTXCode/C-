#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>

int k, i = 0;
char a[100];
char b[100], m[100], n[100];

int jiami()
{
	printf("���������ģ� \n");
	scanf("%s", a);
	for (i = 0; a[i] != '\0'; i++)
	{
		b[i] = a[i] - 64;
	}
	printf("������һλ��Կ \n");
	scanf("%d", &k);
	printf("\n");
	for (i = 0; b[i] != '\0'; i++)
	{
		m[i] = (b[i] + k) % 26 + 64;
	}
	printf("%s\n", &m);
	return 0;
}

int jiemi()
{
	printf("���������ģ� \n");
	scanf("%s", a);
	for (i = 0; a[i] != '\0'; i++)
	{
		b[i] = a[i] - 64;
	}
	printf("������һλ��Կ \n");
	scanf("%d", &k);
	printf("\n");

	for (i = 0; b[i] != '\0'; i++)
	{
		n[i] = (b[i] - k) % 26 + 64;
	}
	printf("%s\n", n);
	return 0;
}

void menu(){
	printf("**********************\n");
	printf("****1.����  2.����****\n");
	printf("*******0.�˳�*********\n");
	printf("**********************\n");
}
int main()
{
	
	printf("��������\n");
	printf("���������ѡ��\n");
	int m;
	do 
	{ 
		menu();
		scanf("%d", &m);
		switch (m)
		{
		case 1:  
			jiami(); 
			break;
		case 2:  
			jiemi(); 
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("����������\n");
			break;
		}
	} while (m);
	return 0;
}


