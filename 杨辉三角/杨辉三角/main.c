//#include<stdio.h>
//#include<windows.h>
//
//#define N  10
//
//int main(){
//	int arr[N][N] = {0};
//	int i, j;
//	for ( i = 0; i < N; i++){
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//		for ( j = 0; j < i + 1; j++){
//			if (i <= 1){
//				printf("%d ", arr[i][j]);
//				continue;	
//			}
//			else{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//			printf("%d ", arr[i][j]);
//			
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}


//#include<stdio.h>
//#include<windows.h>
//
//#define N  10
//int arr[N][N] = { 0 };
//void Triangle(int sum){
//	arr[sum][0] = 1;
//	arr[sum][sum] = 1;
//	for (int i = 2; i <= sum; i++){
//		arr[sum][i] = arr[i - 1][i - 2] + arr[i - 1][i - 1];
//		printf("%d ",arr[sum][i]);
//	}
//}
//
//int main(){
//	Triangle(0);
//	system("pause");
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

int main(){
	int  n = 0;
	int  sum = 2;
	int count = 2;
	printf("please enter n is:");
	scanf("%d",&n);
	if (n == 1){
		sum = 2;
		
	}
	else{
		for (int i = 2; i <= n; i++){
			count *= 10;
			sum += count;
		}
	}
	printf("sum=%d\n", sum);
	system("pause");
	return 0;
}

