//#include<iostream>
//
//using namespace std;
//
//class A{
//	class B{
//	public:
//		void  display(A& a){
//			//外部类的私有成员只能通过外部类对象访问
//			cout << a._a << endl;
//			//外部类的静态私有成员可以通过外部类对象访问也可以直接访问
//			cout << a._A << endl;
//			cout << _A << endl;
//		}
//	private:
//		int _b;
//	};
//	//内部类是外部类的友元类(B是A的内部类，相当于B是A的友元类)
//	/*void display(B &b){
//	//外部类对于内部类没有任何访问权限，不能访问内部类的私有成员
//		cout << b._b << endl;
//		}*/
//private:
//	int _a;
//	static int _A;
//};
//
//int main(){
//
//
//	return 0;
//}