#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>

long count;

void hanoi(int n, char a, char b, char c){
	if (n == 1){
		printf("第%d次，%c柱-->%c柱\n",++count,a,c);
	}
	else{
		hanoi(n - 1,a,c,b);
		printf("第%d次，%c柱-->%c柱\n", ++count, a, c);
		hanoi(n - 1, b, a, c);
	}
}
int main(){
	int h;
	printf("请输入A柱汉诺塔圆盘的数量:");
	scanf("%d",&h);
	count = 0;
	hanoi(h, 'A','B','C');
	system("pause");
	return 0;
}