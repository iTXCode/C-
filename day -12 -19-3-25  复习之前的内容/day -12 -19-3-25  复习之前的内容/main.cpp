#include<iostream>
#include<windows.h>

using namespace std;

namespace A{
	int a;
	int b;
	int Add(int max,int min){
		int x = 0;
		if (max > min){
			x = max;
		}
		else{
			x = min;
		}
		return x;
	}
}

namespace B{
	int Change(int x,int y){
		return x + y;
	}
	namespace C{
		int aDD(int x, int y){
			return x*y;
		}
	}
}
int main(){
	cout << "Addmax(4,5)=" << A::Add(4, 5) << endl;
	cout << "Change(4,5)=" << B::Change(4,5) << endl;
	cout << "aDD(8,9)=" << B::C::aDD(8,9)<< endl;
	system("pause");
	return 0;
}
//命名空间中可以定义变量也可以定义函数
//而且命名空间中还可嵌套另一个命名空间



