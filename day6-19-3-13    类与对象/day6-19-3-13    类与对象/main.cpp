//#include<iostream>
//
//using namespace std;
//
//class Date{
//public:
//	Date(int year){
//		_year = year;
//	}
//private:
//	int _year;
//};
//
//int main(){
//	Date d1(2019);
//	Date d2 = 2018;
//	return 0;
//}
//

//#include<iostream>
//
//using namespace std;
//
//class Date{
//public:
//	explicit Date(int year){
//		_year = year;
//	}
//private:
//	int _year;
//};
//
//int main(){
//	Date d1(2019);
//	//Date d2 = 2018;
//	//������explicit ���������÷�������
//	return 0;
//}

//#include<iostream>
//#include<Windows.h>
//
//using namespace std;
//int Count = 0;
////����ȫ�ֱ��������㺯�����õĴ���
////ȷ��ȫ�ֱ�����������Ķ�

////����ȫ�ֱ�������������Ϊ�������ý���
////��ʹ��ֵ�������
//class Date{
//public:
//	Date(int year){
//		Count++;
//		_year = year;
//		cout << "Date(int)" << endl;
//	}
//	Date(const Date& d1){
//		Count++;
//		_year = d1._year;
//		//_count = d1._count;
//		//_count++;
//		cout << "Dtae(const Date& d1)" << endl;
//	}
//	/*int getcount(){
//		return _count;
//	}*/
//private:
//	int _year;
//	//int _count;
//};
//Date fun1(Date d1){
//	return d1;
//}
//
//int main(){
//	Date d1(2019);
//	//Date d2 = 2018;
//	fun1(d1);
//	cout << Count<< endl;
//	//d1.getcount();
//	system("pause");
//	return 0;
//}
//


//#include<iostream>
//#include<Windows.h>
//
////�����Ϊstatic����ĺ���Ϊ���е�
//using namespace std;
//class Date{
//public:
//	Date(int year){
//		_count++;
//		_year = year;
//		
//		cout << "Date(int)" << endl;
//	}
//	Date(const Date& d1){
//		_count++;
//		_year = d1._year;
//		cout << "Dtae(const Date& d1)" << endl;
//	}
////private:
//	int _year;
//	static int _count; 
//	//static����ı�������������г�ʼ��
//};
//
//int Date::_count = 0;
//
////static����ı����������ʼ��
//Date fun1(Date d1){
//	return d1;
//}
//
//int main(){
//	Date d1(2019);
//	Date d2(2015);
//	Date d3(2015);
//	fun1(d1);
//	cout << d1._count<< endl;
//	cout << &d1._count << endl;
//	cout << &d2._count << endl;
//	cout << &d3._count << endl;
//	system("pause");
//	return 0;
//}
//

//#include<iostream>
//#include<Windows.h>
//
////�����Ϊstatic����ĺ���Ϊ˽�е�
//using namespace std;
//class Date{
//public:
//	Date(int year){
//		_count++;
//		_year = year;
//
//		cout << "Date(int)" << endl;
//	}
//	Date(const Date& d1){
//		_count++;
//		_year = d1._year;
//		cout << "Dtae(const Date& d1)" << endl;
//	}
//	int getCount(){
//		//�����ǽ�_count ��ֵ������Ҫ����_count�ĵط�
//		return _count;
//	}
//private:
//	int _year;
//	static int _count;
//	//static����ı�������������г�ʼ��
//};
//
//int Date::_count = 0;
//
////static����ı����������ʼ��
//Date fun1(Date d1){
//	return d1;
//}
//
//int main(){
//	Date d1(2019);
//	Date d2(2015);
//	Date d3(2015);
//	fun1(d1);
//	cout << d1.getCount() << endl;
//	system("pause");
//	return 0;
//}
//
//

//class A{
//	//B��A���ڲ���,�൱��B��A���ڲ���
//	class B{
//	public:
//		void display(A& a){
//			cout << a._a << endl;
//			//�ⲿ�����ͨ��˽�г�Աֻ��ͨ�� ����. �ķ�ʽ����
//			cout << _s << endl;          //ֱ�ӷ���
//			cout << a._s << endl;        //����. �ķ�ʽ����
//			//�ⲿ��ľ�̬��˽�г�Ա����ͨ�� ����. �ķ�ʽ���� Ҳ����ֱ�ӷ���
//	private:
//		int _b;
//		}
//		void Display(B& b){
//			//�ⲿ������ڲ���û���κ���Խ�ķ���Ȩ�ޣ����ܷ����ڲ���˽�г�Ա(_b)
//			cout << b._b << endl;
//		}
//	};
//private:
//	int _a;
//	static int _s;
//};
//


//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//class Date{
//public:
//	Date(){
//		static int count = 0;
//		cout << "������:"<<++count << endl;
//	}
//};
//
//int main(){
//	Date array[10];   //������10��
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//class A{
//public:
//	class Sum{
//	public:
//		Sum(){
//			_sum += _i;
//			++_i;
//		}
//	};
//	int Sum_solution(int n){
//		Sum arr[5];
//		return _sum;
//	}
//private:
//	static int _sum;
//	static int _i;
//};
//
//int A::_sum = 0;
//int A::_i = 1;
//int main(){
//	A a;
//	cout << a.Sum_solution(0) << endl;
//	system("pause");
//	return 0;
//}

//
//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//int main(){
//	int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	int year, month, day;
//	cin >> year>> month>> day;
//	int total = days[month - 1] + day;
//	if (month>2){
//		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)){
//			total += 1;
//		}
//	} 
//	cout << total << endl;
//	system("pause");
//	return 0;
//}
