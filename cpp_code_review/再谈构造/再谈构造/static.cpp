

#include<iostream>
#include<stdlib.h>
using namespace std;

#if 0
class Date{
public :
	Date(int year){
		_count++;
		_year = year;
		cout << "Date(int)" << endl;
	}
	Date(const Date& d1){
		_count++;
		cout << "Date(const Date&)" << endl;
	}

	/*int getcount(){
		return _count;
		}*/

	static int getcount(){
		return _count;
		//��̬��Ա���������ܵ��÷Ǿ�̬����
		//��̬��Ա����û��thisָ��
	}

	void add(){
		getcount();
		//�Ǿ�̬��Ա�������Ե��þ�̬��Ա����
	}
	void operator<<(ostream& outs){
		outs<<_year<<endl;
	}
	
private:

	int _year;
	static int _count;
};
//��static���εı���Ҫ����������г�ʼ��
//���ж�����̬����
//��̬��Ա������ĳ���࣬�����ж����е�

int Date::_count = 0;

Date fun(Date d1){
	return d1;
}

int main(){
	Date d(2019);
	fun(d);
	cout << d.getcount()<< endl;
	//����ͨ�����ͼ������޶���ȥ����(Date::getcount)
	//Ҳ����ͨ������.�ķ�ʽȥ����(d.getcount)
	return 0;
}

//������κ������ã��������ο�������
//(fun��������ʱ������ʱ������������һ���µĶ��� )

#endif

//class Date{
//public:
//	Date(){
//		cout << "Date(int)" << endl;
//	}
//	Date(const Date&d){
//		cout << "Date (const Date&)" << endl;
//	}
//
//	static int count;
//};
//int Date::count = 0;
//
//int main(){
//	Date d;
//	cout << Date::count << endl;
//	cout << d.count << endl;
//	return 0;
//}
