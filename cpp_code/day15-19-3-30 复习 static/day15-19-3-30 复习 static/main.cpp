//#include<iostream>
//
//#include<Windows.h>
//
////�����Ϊstatic����ĺ���Ϊ���е�
//using namespace std;
//class Date{
//public:
//  Date(int year){
//      _count++;
//      _year = year;
//      cout << "Date(int)" << endl;
//
//  }
//  Date(const Date& d1){
//
//      _count++;
//      _year = d1._year;
//      cout << "Dtae(const Date& d1)" << endl;
//
//  }
//
////private: //��static����Ϊ˽�г�Աʱ�Ͳ�����d1.count �ķ�ʽ�����ˡ�
//  int _year;
//  static int _count; 
//  //static����ı�������������г�ʼ��
//};
//
//int Date::_count = 0; //static����ı����������ʼ��
//
//Date fun1(Date d1){
//  return d1;
//
//}
//
//
//int main(){
//  Date d1(2019);
//  Date d2(2015);
//  Date d3(2015);//����Ϊֹ�Ѿ�������3�ι��캯��
//  fun1(d1);    //
//  cout << d1._count<< endl;
//  cout << &d1._count << endl;
//  cout << &d2._count << endl;
//  cout << &d3._count << endl;
//  system("pause");
//  return 0;
//
//}


//#include<iostream>
//
//#include<Windows.h>
//
////�����Ϊstatic����ĺ���Ϊ˽�е�
//using namespace std;
//
//class Date{
//
//public:
//
//  Date(int year){
//      _count++;
//      _year = year;
//      cout << "Date(int)" << endl;
//
//  }
//
//  Date(const Date& d1){
//
//      _count++;
//     _year = d1._year;
//     cout << "Dtae(const Date& d1)" << endl;
//  }
//
//  int getCount(){
//      //�����ǽ�count ��ֵ������Ҫ����count�ĵط�
//      return _count;
//
//  }
//
//
//
////��Ϊ��̬������,���ִ��󣬾�̬�������ܵ��÷Ǿ�̬����     
// // static int getCount(){
// //                    //
// //       return _count;
// //  }
//private:
//  int _year;
//  static int _count;
// 
//
//};
//
//int Date::_count = 0;
//
////static����ı����������ʼ��
//
//Date fun1(Date d1){             //fun(Date *this)
//                      //�Ǿ�̬�������Ե��÷Ǿ�̬����
//  return d1;
//}
//
//
//
//int main(){
//  Date d1(2019);
//  Date d2(2015);
//  Date d3(2015);
//  fun1(d1);
//  cout << d1.getCount() << endl;
//  system("pause");
//  return 0;
//}
//


//#include<iostream>
//#include<windows.h>
//
//using namespace std;
//
//class Date{
//public:
//
//	Date(int year,int month,int day)
//	:_year(year)
//	,_month(month)
//	,_day(day)
//	{
//		cout << _year <<"-"<< _month<<"-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//int main(){
//	Date d1(2019,3,30);
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include<windows.h>
//using namespace std;
//class A{
//public:
//	//B��A���ڲ���,�൱��B��A����Ԫ��
//	class B{
//
//	public:
//		void display(A& a){
//			cout << a._a << endl;
//			//�ⲿ�����ͨ��˽�г�Աֻ��ͨ�� ����. �ķ�ʽ����
//			cout << _s << endl;          //ֱ�ӷ���
//			cout << a._s << endl;        //����. �ķ�ʽ����
//			//�ⲿ��ľ�̬��˽�г�Ա����ͨ�� ����. �ķ�ʽ���� Ҳ����ֱ�ӷ���
//	
//		}
//	private:
//		int _b;
//
//		void Display(B& b){
//			//�ⲿ������ڲ���û���κ���Խ�ķ���Ȩ�ޣ����ܷ����ڲ���˽�г�(_b)
//			cout << b._b << endl;
//		}
//
//	};
//private:
//	int _a=10;//�Ǿ�̬�����ֱ���ڶ����ʱ���ʼ��
//	static int _s;//��̬������������������г�ʼ��
//
//};
//
//int A::_s = 0;
//int main(){
//	 A::B b;
//	 A a;
//	 b.display(a);
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
//int main(){
//	string s1;
//	string s2 ("hello");
//	string s3(s2);//��������
//	string s4 = "world!";
//	//�������Ĺ��캯������ʽ����ת��(explicit)
//	cout <<s1<< endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
////��������ʹ��
//void test_string(){
//	string num = "1234";
//	string::iterator it = num.begin();
//	while (it!=num.end()){
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}
//int main(){
//	test_string();
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//#include<windows.h>
//
//using namespace std;
//
////��������ʹ��
//void test_string( ){
//	string num = "1234";
//	string::iterator it = num.begin();
//	while (it != num.end()){
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(5);
//	vector<int> ::iterator vit = v.begin();
//	while (vit != v.end()){
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;
//
//	list<int> l;
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(6);
//
//	list<int>::iterator lit = l.begin();
//	while (lit != l.end()){
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;
//
//
//}
//int main(){
//	test_string();
//	system("pause");
//	return 0;
//}


//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//#include<windows.h>
//
//using namespace std;
//
////��������ʹ�ã���ӡ��ԭ�����ַ�������
//void test_string(){
//	string num = "1234";
//	string::iterator it = num.begin();
//	int value = 0;
//	while (it != num.end()){
//		value *= 10;
//		value += *it - '0';
//		it++;
//	}
//	cout << value << endl;
//
//}
//
//
//void test_string1(){
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(5);
//	vector<int> ::iterator vit = v.begin();
//	while (vit != v.end()){
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;
//}
//
//
//
//void test_string2(){
//
//	list<int> l;
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(6);
//
//	list<int>::iterator lit = l.begin();
//	while (lit != l.end()){
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;
//}
//
//
//void  test_string3(){
//	string num = "1234";
//
//	//���������
//	string::reverse_iterator rit = num.rbegin();
//	while (rit != num.rend()){
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}
//int main(){
//	test_string();
//	test_string1();
//	test_string2();
//	test_string3();
//	system("pause");
//	return 0;
//}
//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//
//void  test_string3(){
//	string num = "1234";
//
//	//���������
//	string::reverse_iterator rit = num.rbegin();
//	while (rit != num.rend()){
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}
//int main(){
//
//	test_string3();
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//int StrToNum(const string& str){
//	int value=0;
//	string::const_iterator it = str.begin();
//	while (it != str.end()){
//		value *= 10;
//		value += (*it - '0');
//		++it;
//	}
//	return value;
//}
//
//void  test_string3(){
//	string num = "1234";
//
//	//���������
//	string::reverse_iterator rit = num.rbegin();
//	while (rit != num.rend()){
//		(*rit) += 1;
//		++rit;
//	}
//	cout << endl;
//	cout << StrToNum(num) << endl;
//
//}
//int main(){
//
//	test_string3();
//	system("pause");
//	return 0;
//}
//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//int StrToNum(const string& str){
//	int value = 0;
//	for (size_t i = 0; i < str.size();++i){
//		value *= 10;
//		value += (str[i]-'0');
//	}
//	return value;
//}
//
//void  test_string3(){
//	string num = "1234";
//
//	//���������
//	string::reverse_iterator rit = num.rbegin();
//	while (rit != num.rend()){
//		(*rit) += 1;
//		++rit;
//	}
//	cout << endl;
//	cout << StrToNum(num) << endl;
//
//}
//int main(){
//
//	test_string3();
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//int StrToNum(const string& str){
//	int value = 0;
//	for (auto e:str){
//		value *= 10;
//		value += (e - '0');
//	}
//	return value;
//}
//
//void  test_string(){
//	string num = "1234";
//
//	//���������
//	string::reverse_iterator rit = num.rbegin();
//	while (rit != num.rend()){
//		(*rit) += 1;
//		++rit;
//	}
//	cout << endl;
//	cout << StrToNum(num) << endl;
//
//}
//int main(){
//
//	test_string();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//#include<windows.h>
//
//using namespace std;
//
//int StrToNum(const string& str){
//	int value = 0;
//	for (auto e : str){
//		value *= 10;
//		value += (e - '0');
//	}
//	return value;
//}
//
//void  test_string(){
//	string num = "1234";
//
//	//���������
//	string::iterator rit = num.begin();
//	while (rit != num.end()){
//		(*rit) += 1;
//		++rit;
//	}
//	cout << endl;
//	cout << StrToNum(num) << endl;
//
//}
//int main(){
//
//	test_string();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
//void  test_string(){
//	string s("hello world!");
//	cout << s << endl;
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	//Ϊ�ַ���Ԥ���ռ� reserve
//	s.reserve(50);
//	cout << s << endl;
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	s.resize(51);
//	//resize �ռ䲻���Ļ����ݣ��ռ乻�Ļ�ʣ��λ����
//	//0 ����������ֵ�û��ͻ��ʣ��λ�ò��ɸ�����ֵ
//	//s.resize(80,'1');
//	cout << s << endl;
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	
//}
//int main(){
//
//	test_string();
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<windows.h>
//
//using namespace std;
//
//void  test_string(){
//	string s1 = "hello";
//	s1 += ' ';
//	s1 += "world";
//	string s2 = "!!!!";
//	s1 += s2;
//	cout << s1 << endl;
//}
//int main(){
//
//	test_string();
//	system("pause");
//	return 0;
//}


#include<iostream>
#include<string>
#include<windows.h>

using namespace std;

void  test_string(){
	string s1 = "hello ";
	string s2 = "world!!";
	cout << s1 + "world!" << endl;
	cout << "hello " + s2 << endl;
	cout << s1+s2 << endl;
}
int main(){

	test_string();
	system("pause");
	return 0;
}
