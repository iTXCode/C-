//#include<iostream>
//#include<time.h>
//using namespace std;
//
//int Get_n(int p, int q){
//	int  N=(p - 1)*(q - 1);
//	 return N;
//}
//
//int MiYao(int N, int e){
//	int x = 0;
//	int d=1;
//	for(int i=1;i<N;i++){
//		x = i*e;
//		for (int j = 1; j < N; j++){
//			if (x == j*N + 1){
//				return i;
//			}
//		}
//	}
//	return 0;
//}
//
//int  Jia_Mi(int m, int e, int n){
//	int M;//密文
//	int c = 1;
//	for (int i = 0; i < e; i++){
//		c *= m;
//	}
//	return M = c%n;
//}
//
//
//int Jie_Mi(int m, int e, int n){
//	int M;
//	int c = 1;
//	for (int i = 0; i < e; i++){
//		c *= m;
//	}
//	return M = c%n;
//}
//
//bool Sushu(int n){
//	for (int i = 2; i < n / 2; i++){
//		if (n%i == 0){
//			return false;
//		}
//	}
//	return true;
//}
//void Test(){
//	printf("请输入一个明文数字:");
//	int M = 0;
//	cin >> M;
//	cout << "请输入两个素数p,q:";
//	int p, q;
//	while (1){
//		cin >> p;
//		cin >> q;
//		if (Sushu(p) && Sushu(q)){
//			break;
//		}
//		else{
//			cout << "你输入的两个数不都是素数请重新输入!" << endl;
//		}
//	}
//	int n = p*q;
//	int N = Get_n(p, q);
//	int e;
//	cout << "请选择一个公钥e:";
//	cin >> e;
//	int d = MiYao(N, e);
//	printf("其私钥结果为:%d\n", d);
//
//	int J = Jia_Mi(M, e, n);
//	cout << "其密文为:" << J << endl;
//
//	int m = Jie_Mi(J, d, n);
//	cout << "其明文为:" << m << endl;
//}
//
//
//int main(){
//	Test();
//	return 0;
//}