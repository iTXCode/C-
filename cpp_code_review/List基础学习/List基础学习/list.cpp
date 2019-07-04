#include<iostream>
#include<list>
#include<vector>
using namespace std;

template <class T>
void constprintList(const list<T> l1){
	auto lit = l1.cbegin();
	cout << "const������:";
	while (lit != l1.cend()){
		cout << *lit << " ";
		lit++;
	}
	cout << endl;
}

void printList(const list<int> l1){
	auto lit = l1.begin();
	cout << "���������:";
	while (lit != l1.end()){
		cout << *lit << " ";
		lit++;
	}
	cout << endl;
}

void rPrintList(const list<int> l){
	auto lit = l.rbegin();
	cout << "���������:";
	while (lit != l.rend()){
		cout << *lit << " ";
		lit++;
	}
	cout << endl;
}

//int main(){
//	list<int> l1(10,1);
//	list<int> l2(l1.begin(),l1.end());
//	vector<int> v(10, 2);
//	list<int> l3(v.begin(), v.end());
//	printList(l1);
//	printList(l2);
//	printList(l3);
//	l3.pop_back();
//	l3.push_back(1);
//	printList(l3);
//	rPrintList(l3);
//	constprintList(l3);
//	return 0;
//}

//int main(){
//	list<int> l1;
//	l1.push_front(1);
//	l1.push_front(1);
//	l1.push_front(1);
//	l1.push_front(1);
//	l1.push_front(0);
//	printList(l1);
//	l1.pop_front();
//	printList(l1);
//	list<int> l2;
//	l2.insert(l2.begin(),l1.begin(),l1.end());
//	//�����б�1.��ʼ��������λ��,2.����Ŀ��Ŀ�ʼλ��3.�������ݵĽ���λ��
//	printList(l2);
//
//	auto lit = l2.begin();
//	l2.insert(l2.begin(),5,10);
//	//��ָ����λ�ò���5��10��
//	printList(l2);
//	cout << "�����"<<*lit << endl;
//	//list��insert�ӿڲ������������ʧЧ
//	//list��erase�ӿڻ����������ʧЧ
//	//������ָ��Ŀռ��Ѿ���ɾ����
//	lit=l2.erase(lit);
//	*lit = 10;
//	//ɾ����λ�õĿռ��Ѿ�������ϵͳ,�޷�������������
//	//��ɾ�������Ľ������֮ǰ�ĵ����������Լ���ʹ��
//	cout << "ɾ����:"<<*lit << endl;
//	printList(l2);
//	cout << l2.size() << endl;
//	l2.clear();
//	cout << l2.size() <<endl;
//	return 0;
//}

//class Date{
//public:
//	Date(int year,int month,int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int,int,int)" << endl;
//	}
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{
//		cout << "Date(const Date&):" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//
//int main(){
//	list<int> l;
//	l.push_back(1);
//	l.emplace_front(2);
//	l.push_front(3);
//	l.emplace_front(4);
//	printList(l);
//
//	list<Date> l1;
//	l1.push_back(Date(2018, 1, 1));
//	l1.emplace_back(2018,3,3);
//
//	Date d(2018, 1, 1);
//	list<Date> l3;
//	l3.push_back(d);
//	l3.push_back(d);
//	cout << l1.size() << endl;
//	cout << l3.size() << endl;
//	l3.splice(l3.begin(), l1 );
//	//ƴ����������
//	cout << l1.size() << endl;
//	cout << l3.size() << endl;
//	
//	return 0;
//}

int main(){
	list<int> l(10, 1);
	l.push_back(2);
	l.remove(1);
	//ɾ�������������е�1
	printList(l);
	l.pop_back();
	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	l.push_back(3);
	l.push_back(4);
	l.push_back(2);
	l.push_back(6);
	l.sort();
	l.unique();
	//ʹ������ӿ�ǰҪ������
	printList(l);
	return 0;
}