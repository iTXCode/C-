////6���Ա����
//
//#include<iostream>
//#include<stdlib.h>
//
//using namespace std;
//
//
//class A{
//	//��ƫ��������:û�г�Ա�ĵ�����Ϊ���࣬
//    //���ǿ����в�����û���κ����ݣ��κ�һ������
//	//����Ա��д���ݵ�����»��Զ�����6��Ĭ�ϳ�Ա����
//};
//
//
//class Date{
//public :
//	//1.���캯��(��ʼ��)
//	//1.��������������ͬ��2.û�з���ֵ��3.����һ�������
//	//����Ҫ��ʾ�ĵ��ù��캯�����������Զ����ù��캯���Զ�����г�ʼ��
//	//4.��������
//	Date(int year,int month,int day){
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date()   //Ĭ�Ϲ��캯�����ڲ�д���캯��������£��������Զ�����
//	//{}        //����û���ʾ�Ķ����˹��캯��������������������
//	//Ĭ�Ϲ��캯��:ȫȱʡ
//	//��ע�⡿Ĭ�Ϲ��캯��ֻ����һ��
//	Date(int year = 1997, int month = 1){
//		_year = year;
//		_month =month;
//		
//	}
//
//
//	
//
//	void disPaly(){
//		cout << _year <<"-"<< _month<<"-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
////�����䡿:�����޶�����������û���޶����õģ�ֻ�����ⶨ��ı����� 
////���޶����ã������в����������޶�����ʱ���������޶�Ĭ����˽�е�
//};
//
//
//int main(){
//	Date d1(2019,5,26);
//	//Date d2(); //��ע�⡿������ʽ���ǵ����޲ι��캯�����䶨����һ��
//	//Date���͵ĺ�������������ֵ����ΪDate
//	//��ȷ���޲ι��캯���ĵ��÷�ʽ(Data d2);
//	Date d2;
//
//	A a;   //���õ����޲εĹ��캯����
//	d1.disPaly();
//	system("pause");
//	return 0;
//}





//#include<iostream>
//#include<stdlib.h>
//
//using namespace std;
//
//class Date{
//public:
//	Date(){
//
//	}
//
//	~Date(){
//		cout << "~Date()" << endl;
//	}
//	
////��������
////���ص㡿��1.������������ͬ��������ǰ���һ��"~"
////          2.�޷���ֵ
////          3.һ����ֻ����һ����������
////          4.�����������ڽ���ʱ���������Զ�������������
////�����á�:����������ʱ���Զ���������������������һЩ��Դ������
//
//private:
//	int _month;
//};
//
//int main(){
//	Date d;
//	//system("pause");
//	return 0;
//}





//#include<iostream>
//#include<stdlib.h>
//
//using namespace std;
//
//class Date{
//public:
//	Date(int year, int month){
//		_year = year;
//		_month = month;
//	}
//	void disPlay(){
//		cout << _year << "-" << _month<< endl;
//	}
//	//���������졿
//	//���ص㡿��
//	//1.�������캯���ǹ��캯����һ��������ʽ
//	//2.��������Ĳ���ֻ��һ���ұ���ʹ�����ô��Σ�ʹ�ô�ֵ��ʽ����������ݹ�
//	Date(const Date& d1){
//		_year = d1._year;
//		_month = d1._month;
//	}
//
//private:
//	int _year;
//	int _month;
//};
//	
//
//int main(){
//	Date d(2019,5);
//	Date d1(d);  
//	//���������ʹ�ø�ʽ(�����е�����Ҫ�����Ķ���)
//	d.disPlay();
//	d1.disPlay();
//	//���ߵ���������ͬ
//	system("pause");
//	return 0;
//}
////��ע��:���������������ʹ�����ô��Σ������Դ�ֵ����ʽ����
////ԭ�������������Ĳ����������ö���ֵ���ݣ�
////ֵ���ݾͻᷢ��ֵ�����Ӷ��������ÿ������캯��
////���ʹ�����õĻ��������ǿ�������ı���û�з���ֵ����




//#include<iostream>
//#include<stdlib.h>
//
//using namespace std;
//
//class Date{
//public:
//	
//	Date(){
//		_year = 1997;
//		_month = 2;
//	}
//	bool operator==(const Date& d2){  //bool operator(Date *this,Date &d2)
//		return this->_year == d2._year
//			&&this->_month == d2._month;
//	}
//
//	//��ֵ���������
//	void operator=(const Date&d1){
//		//Ҫ�����Լ����Լ���ֵ
//		if (this != &d1){
//		_year = d1._year;
//		_month = d1._month;
//		}
//	}
//
//	void disPlay(){
//		cout << _year << "-" << _month << endl;
//	}
//
//
//	
////private:
//	int _year;
//	int _month;
//};
//
//int operator+(Date &d1, int b)
//{
//	return d1._month + b;
//} 
//
////����������ء�
////���ص㡿:1.����ͨ���������������������µĲ�����������operator@
////         2.���ز�����������һ�������ͻ���ö�����͵Ĳ�����
////         3.�����������͵Ĳ��������京�岻�ܸı䣬
////          ���磺���õ�����+�����ܸı��京��
////         4.��Ϊ���Ա�����غ���ʱ�����βο������Ȳ�������
////         Ŀ��1��Ա�����Ĳ�������һ��Ĭ�ϵ��β�this���޶�Ϊ��һ���β�
////         5. < .* >< ::  > < sizeof  > <  ?:  >< . >
////         ע������5��������������ء�
//
//bool operator==(const Date& d1, const Date& d2){
//	return d1._year == d2._year
//		&&d1._month == d2._month;
//}
//
//
//int main(){
//	Date d;
//	Date d1;
//
//	bool d2 = (d ==d1);
//	cout << "d==d1�Ľ��Ϊ  " << d2 << endl;
//	cout << "d.operator==d1�Ľ��Ϊ  " << (d.operator==(d1))<< endl;
//	//���ַ�ʽ��ͬ��ֻ��һ�������������һ�������������
//	//��������ؿɶ��Ը�ǿ
//	int b = 10;
//	int c = d1 + b;
//	cout << "c=" << c << endl;
//	d1.disPlay();
//	Date d3 = d;//�������õ��ǿ�������
//	//��������һ���¶���
//	Date d4;
//	d4 = d;  //�����Ż���ø�ֵ���������
//	//d��ֵ����d4
//	//d4 = d3 = d; 
//	//��Ҫ����ʹ�õĻ�����ֵ��������غ�����Ҫһ������ֵ
//	//return *this;
//	system("pause");
//	return 0;
//}



