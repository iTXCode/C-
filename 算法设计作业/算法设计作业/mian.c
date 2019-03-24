//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<windows.h>
//
//int get(int x, int y, int lt, int n)
//{
//	if (x == 0)
//		return lt + y;
//	else if (y == 0)
//		return lt + 4 * (n - 1) - x;
//	else if (y == n - 1)
//		return lt + n + x - 1;
//	else if (x == n - 1)
//		return lt + 3 * (n - 1) - y;
//	else
//		return get(x - 1, y - 1, lt + 4 * (n - 1), n - 2);
//}
//int main()
//{
//
//	printf("请输入要打印的n阶矩阵的阶数n=");
//	int n, i, j;
//	scanf("%d", &n);
//	for (i = 0; i < n; ++i) {
//		for (j = 0; j < n; ++j)
//			printf("%2d ", get(i, j, 1, n));
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<windows.h>
//
//
//int main()
//{
//	int n = 0;
//	int count = 0;
//	printf("求所需要求的n的阶乘数:");
//	scanf("%d",&n);
//	int sum = 1;
//	while (n != 0){
//		sum *= n;
//		n--;
//	}
//	printf("n的阶乘为%d\n", sum);
//	while (sum >5){
//		if (sum % 5 == 0){
//			sum = sum / 5;
//			count++;
//		}
//		else{
//			break;
//		}
//	}
//	
//	printf("n的阶乘中末尾一共有%d个0\n", count);
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<windows.h>
//
//
//int main()
//{
//	int A = 0; 
//	int B= 0;
//	int C = 0;
//	int D = 0;
//	int E = 0; 
//	for (A = 1; A <= 5; A++){
//		for (B = 1; B <=5; B++){
//			for (C = 1; C <= 5; C++){
//				for (D = 1; D <= 5; D++){
//					for (E = 1; E <=5; E++){
//						if (((B == 3) ^ (C == 5)) + ((D == 2) ^ (E == 4))\
//							+ ((B == 1) ^ (E == 4)) + ((C == 1) ^ (B == 2))\
//							+ ((D == 2) ^ (A == 3))==5){
//							printf("A=%d,B=%d,C=%d,D=%d,E=%d\n", A, B, C, D, E);
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>


int main(){
	int sum;
	int k = 0;
	printf("请输入要判断的数:");
	scanf("%d",&sum);
	k = (sum % 4 == 0) + (sum % 7 == 0) * 2 + (sum % 9 == 0) * 4;
	switch (k){
	case 0:
		printf("none\n");
		break;
	case 1:
		printf("能被4整除\n");
		break;
	case 2:
		printf("能被7整除\n");
		break;
	case 3:
		printf("能被4和7整除\n");
		break;
	case 4:
		printf("能被9整除\n");
		break;
	case 5:
		printf("能被4和9整除\n");
		break;
	case 6:
		printf("能被7和9整除\n");
		break;
	case 7:
		printf("能被4、7和9整除\n");
		break;
	}
	system("pause");
	return 0;
}
