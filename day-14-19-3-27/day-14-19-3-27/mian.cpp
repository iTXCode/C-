#include<iostream>
#include<windows.h>

using namespace std;

template<class T>
T Add( T left,  T right)//调用方式为引用
{
	return left + right;
}


int main(){
	int a = 0, b = 1;
	double aa = 1.0000000, bb = 2.000000;

	int sum=Add(a,b);
	double sum1 = Add(aa, bb);
	 Add<int>(a, aa);
	cout << "sum="<<sum << endl;
	cout << "sum1="<<sum1 << endl;
	cout << Add<int>(a, aa) << endl;
	cout << Add(a,(int)bb) << endl;
	system("pause");
	return 0;
}