#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<time.h>


bool Choose(int p){
	if (p <= 0){
		return false;
	}
	for (int i = 2; i <=p / 2; i++){
		if (p % i == 0){
			return false;
		}
	}
	return true;
}

int Get_P(){
	srand(( int)time(NULL));
		int t = rand() % 10+1;
		if (Choose(t))
			return t;
		else{
			Get_P();
		}
		return 0;
}

int Get_Q(){
	while (1){
		srand(( int)time(NULL));
		int t = rand() % 10;
		if (Choose(t))
			return t;
		else{
			Get_Q();
		}
	}
	return 0;
}

int get_n(int p, int q){
	return p*q;
}

int get_N(int p, int q){
	return (p - 1)*(q - 1);
}

int get_d(int e, int N){
	for (int i = 1; i < N; i++){
		for (int j = 1; j < N; j++){
			if (i*e == j*N + 1){
				return  i;
			}
		}
	}
	return 0;
}

int get_s(int M, int d, int n){
	int x = 1;
	int m = M;
	for (int i = 0; i < d - 1; i++){
		m *= M;
	}
	return m%n;
}
int Ver(int S, int e, int n){
	int s = S;
	for (int i = 1; i < e; i++){
		s = s*S;
	}
	return s%n;
}


void TestRsa(){
	int p = 0;
	int q = 0;
	int g = 0;
	p = Get_P();
	printf("所选的p=%d\n",p);
	q = Get_Q();
	printf("所选的q=%d\n", q);
	int n = get_n(p, q);
	int N = get_N(p, q);
	printf("请选择e:");
	int e = 0;
	scanf("%d", &e);
	int d = get_d(e, N);
	printf("d=%d\n", d);
	int M = 0;
	printf("请输入明文M:");
	scanf("%d", &M);
	int S = get_s(M, d, n);
	printf("签名后的结果S=%d\n", S);
	int m = Ver(S, e, n);
	printf("明文=%d\n", m);
}
int main(){
	TestRsa();
	system("pause\n");
	return 0;
}