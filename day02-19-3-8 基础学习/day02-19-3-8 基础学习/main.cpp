#define _CRT_SECURE_NO_WARNINGS 1
//
////#include<iostream>
////#include<windows.h>
////using namespace std;
////��д�������cin��cout δ����Ĵ���
////
//// namespace N1{
////	int a = 10;
////	int b = 20;
////	int Add(int a, int b){
////�����ռ��п����к����Ĵ���
////		return a + b;
////	}
////	namespace N2{
////�����ռ��п��Գ���Ƕ��ʽ�������ռ�
////����ʱֻ��Ҫע����÷�ʽ����
////		int Swap(int x, int y){
////			return x*y;
////		}
////	}
////}
////
////int main(){
////	int a,b;
////	cin >> a;
////c++���Ե������ʽ
////	cin >> b;
////	cout << "a=" << a << endl;
//// C++���Ե������ʽ������""�м�Ĳ���Ϊ����ĸ�ʽ�������������
////��Ϊ��������ݣ���<<endl����ʾ���ǡ�\n��->���з�
////	cout <<"b=" <<b  << endl;
////	cout << "a="<<N1::a << endl;
////	cout << "b=" << N1::b << endl;
////	cout << "a+b="<<N1::Add(a,b) << endl;
////	cout << "a*b=" << N1::N2::Swap(a, b) << endl;
////	system("pause");
////	return 0;
////}

//����ر�ע��C������C++���Ե��﷨�Ĳ�ͬ��

//F.h
//F.cpp
//main.cpp


//1.Ԥ����  ͷ�ļ�չ��/���滻/��������/ע��ɾ����������
//F.i  main.i
//2.����  �﷨���,���ɻ�����
//F.s  Main.s
// int i=1;
//i += 1; 

//3.���  ת�ɻ�����
//F.o  main.o
//4������
//


//a.out ��ִ�г���


//./a.out 


//�ն˸����� fork �ӽ��̣�waitpid  

//


//#include<iostream>
//using namespace std;
//
//
//int main(){
//	int a = 10;
//	cout << a << endl;
//	return 0;
//}



//��������
//
//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//int Add(int a,int b){
//	return a + b;
//}
//
//double Add(double a, double b){
//	return a + b;
//}
//double Add(double a, int b, float c){
//	return a + b + c;
//}
//int main(){
//	int a = 10;
//	int b = 20;
//	double c = 2.0;
//	double d = 3.0;
//	float f = 3;
//	cout<<Add(a,b)<<endl;
//	cout << Add(c, d) << endl;
//	cout << Add(d, a, f) << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//void Testfun(){
//	int a = 10;
//	int &ra = a;
//	cout << ra  << endl;
//	//�������һ��10
//	cout << ra <<endl<< a<<endl;
//	//�����������10
//}
//
//int main(){
//	Testfun();
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<windows.h>

using namespace std;

int& Add(int a, int b){
	int c = a + b;
	return c;
}

int main(){
	int &rd = Add(1, 2);
	cout << "Add(1,2)=" << rd << endl;
	system("pause"); 
	return 0;
}