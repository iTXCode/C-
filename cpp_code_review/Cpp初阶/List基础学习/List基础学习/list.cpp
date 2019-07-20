#include<iostream>
#include<list>
#include<vector>
using namespace std;

template <class T>
void constprintList(const list<T> l1){
	auto lit = l1.cbegin();
	cout << "const迭代器:";
	while (lit != l1.cend()){
		cout << *lit << " ";
		lit++;
	}
	cout << endl;
}

void printList(const list<int> l1){
	auto lit = l1.begin();
	cout << "正向迭代器:";
	while (lit != l1.end()){
		cout << *lit << " ";
		lit++;
	}
	cout << endl;
}

void rPrintList(const list<int> l){
	auto lit = l.rbegin();
	cout << "逆向迭代器:";
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
//	//参数列表1.开始插入对象的位置,2.插入目标的开始位置3.插入内容的结束位置
//	printList(l2);
//
//	auto lit = l2.begin();
//	l2.insert(l2.begin(),5,10);
//	//在指定的位置插入5个10；
//	printList(l2);
//	cout << "插入后"<<*lit << endl;
//	//list的insert接口不会引起迭代器失效
//	//list的erase接口会引起迭代器失效
//	//迭代器指向的空间已经被删除了
//	lit=l2.erase(lit);
//	*lit = 10;
//	//删除的位置的空间已经还给了系统,无法继续进行引用
//	//将删除函数的结果赋给之前的迭代器还可以继续使用
//	cout << "删除后:"<<*lit << endl;
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
//	//拼接两个对象
//	cout << l1.size() << endl;
//	cout << l3.size() << endl;
//	
//	return 0;
//}

int main(){
	list<int> l(10, 1);
	l.push_back(2);
	l.remove(1);
	//删除了链表中所有的1
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
	//使用这个接口前要先排序
	printList(l);
	return 0;
}