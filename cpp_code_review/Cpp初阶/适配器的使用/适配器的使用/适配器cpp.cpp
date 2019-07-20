#if 0
#include <iostream>

//˫�˶���
using namespace std;

//��������ʵ��
//Ϊ��ʵ�ֵ�������ģ�廰(��ͨ��������const�������Ĵ��븴��)
//һ��ʹ�����������ķ�����ʵ�ָù���
template<class T, class Ref, class Ptr>
class DequeIterator{
public:
	typedef DequeIterator<T, Ref, Ptr> self;
	Ref oparetor*(){
		return *cur;
	}
	self& operator++(){
		cur++;
		if (cur == last){
			node++;
			first = *node;
			last = first + bufferLen;
			cur = first;
		}
		return *this;
	}
private:
	T* frist; //ָ�򻺳����ĵ�һ��λ��
	T* last;  //ָ�򻺳��������һ��λ��
	T* cur;   //�˵�������ָ�� �������е�����Ԫ�أ�����"����"������
	T** node;//ָ���пص�ָ��
};

//++node��ĸ���
//first=*node;
//cur=first;
//last=first+�������ĳ���

template <class T>

class Deque{
public:
	iterator begin(){
		return _start;
	}

	iterator end(){
		return _finish;
	}
private:
	iterator _start;
	iterator _finish;
	T** _map;
};
int main(){

	return 0;
}

#endif


#if 0
//���ȶ���
#include<iostream>
#include<queue>
#include<functional>
using namespace std;


int main(){
	priority_queue<int> pq;
	pq.push(100);
	pq.push(1);
	pq.push(12);
	pq.push(14);
	pq.push(0);
	//�����Ķ�Ĭ���Ǵ��
	while (!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}


	//����С�ѵķ�ʽ
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(100);
	q.push(1);
	q.push(12);
	q.push(14);
	q.push(0);
	//�����Ķ�Ĭ���Ǵ��
	while (!q.empty()){
		cout << q.top() << endl;
		q.pop();
	}
	return 0;
}

#endif



#if 0
#include<iostream>
#include<queue>
#include<functional>
using namespace std;


class Date{
	friend ostream& operator<<(ostream&  _cout, const Date& d);
public:
	Date(int y, int m, int d)
		:_year(y)
		, _month(m)
		, _day(d)
	{

	}

	bool operator<(const Date& d)const{
		return _year < d._year ||
			_month < d._month ||
			_day < d._day;
	}

	bool operator>(const Date& d)const{
		return _year > d._year ||
			_month > d._month ||
			_day > d._day;
	}


private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream&  _cout, const Date& d){
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

int main(){
	priority_queue<Date> pq;
	pq.push(Date(2019, 7, 12));
	pq.push(Date(2019, 7, 10));
	pq.push(Date(2019, 7, 5));
	cout << "Ĭ�ϴ��:" << endl;
	while (!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << "С��:" << endl;
	priority_queue<Date, vector<Date>, greater<Date>> q;


	q.push(Date(2019, 7, 12));
	q.push(Date(2019, 7, 10));
	q.push(Date(2019, 7, 5));
	while (!q.empty()){
		cout << q.top() << endl;
		q.pop();
	}
	return 0;
}
#endif



#if 0


//������
#include<iostream>
#include<vector>
#include<list>
using  namespace std;

template <class T, class Container>


//template <class T,class Container=list<T>>
//�����ʱ����Ը�һ��Ĭ�ϵ�ģ�����
class Stack{
public:
	void Push(const T& x){
		_con.push_back(x);
	}
	void Pop(){
		_con.pop_back();
	}

	T& Top(){
		return _con.back();
	}

	const T& Top() const{
		_con.back();
	}
	size_t Size(){
		return _con.size();
	}
	bool Empty(){
		return _con.empty();
	}
private:
	Container _con;
};

//int main(){
//	Stack<int, vector<int>> st;
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//	st.Push(5);
//	while (!st.Empty()){
//		cout << st.Top() <<" ";
//		st.Pop();
//	}
//	cout << endl;
//	return 0;
//}


int main(){
	Stack<int, list<int>> st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	st.Push(5);
	while (!st.Empty()){
		cout << st.Top() << " ";
		st.Pop();
	}
	cout << endl;
	return 0;
}

#endif


#if 0
#include<iostream>
#include<vector>
#include<list>
#include<deque>
using  namespace std;

template <class T, class Container = deque<T>>
//queue�������������������Եײ���˫�˶�����ʵ��(deque)

class Queue{
public:
	void Push(const T& x)
	{
		_con.push_back(x);
	}
	void Pop(){
		_con.pop_front();
	}

	T& Front(){
		return _con.front();
	}


	T& Back(){
		return _con.back();
	}


	size_t Size(){
		return _con.size();
	}

	bool Empty(){
		return _con.empty();
	}
private:
	Container _con;
};

int main(){
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	while (!q.Empty()){
		cout << q.Front() << " ";
		q.Pop();
	}
	cout << endl;
	return 0;
}

//�������������е�����ת��Ϊ��һ����������Ʒ�������������һ�� ת��
// stack��������list, vector, deque
//Ĭ����deque���У�β��βɾʱ�临�Ӷ�ΪO(1)��
//���ݵĴ��۱Ƚ�С��ÿ��ֻ��Ҫ�����µ�buffer��
//����п����أ�ֻ��Ҫ����һ����������򣬰�ָ�����鿽����
//����Ҫ�������ݣ�Ҳ��������ڴ���Ƭ


//queue : ������list��deque��Ĭ����deque, 
//������vectorʵ�֣�vector���ṩpop_front�ӿ�
//priority_queue : ������vector��
//dequeĬ�ϵ�����vector����vector�������Ч�ʸߣ�
//���ײ���߼��ṹ�Ƕѣ�
//������listʵ���ڲ���ɾ����ʱ��
//����ͨ��������ʵ���ʽ����Ԫ�ص� ���� ��
//�޷���֤�ѵ����ʡ�

#endif


////�º������߽к�������
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//class Greater{
//public:
//	bool operator()(const int &a, const int &b){
//		return a > b;
//	}
//};
//int main(){
//	Greater g;
//	cout << g(2, 3) << endl;
//	priority_queue<int, vector<int>,Greater> d;
//	//����ʹ���Լ�����ķº�����ʹ�����ȶ���
//	d.push(1);
//	d.push(2);
//	d.push(3);
//	d.push(4);
//	d.push(5);
//	d.push(6);
//
//	while (!d.empty()){
//		cout << d.top() << " ";
//		d.pop();
//	}
//	cout << endl;
//	return 0;
//}




//�ѵ�ʵ��
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <class T, class Container = vector<T>>

class PriortyQueue{
public:

	//С���в���Ԫ��
	void Push(const T& val){
		//�Ȱ�Ԫ�طŵ���������һ��λ��
		_con.push_back(val);
		shifUp(_con.size() - 1);
		//���ϵ�����ʹ������ѵ�����
	}
	//С�ѵķ�ʽ���벢���ѵķ�ʽ����

	void shifUp(size_t child){
		size_t parent = (child - 1) / 2;
		while (child > 0){
			if (_con[child] < _con[parent]){
				swap(_con[child], _con[parent]);
				//���¸��ӽ���λ��
				child = parent;
				parent = (child - 1) / 2;
			}
			else{
				break;
				//�ߵ�����˵�����ڵ����ÿ���ӽڵ�Ͳ���Ҫ������
			}
		}
	}

	void Pop(){
		swap(_con[0], _con[_con.size() - 1]);
		//���Ѹ�Ԫ�غ�����Ҷ�ӽ�㽻��λ��
		_con.pop_back();
		//����βԪ��pop��
		shifDown(0);
		//���µ�����ʹ������ѵ�����  
	}

	void shifDown(size_t parent){
		//�Ӹ�����ʼ����
		size_t child = 2 * parent + 1;
		//���Ǵ�ѵĻ���8
		//�����ǲ������Һ��Ӵ���,��ֵ�������ӵ�ֵ��ȡ�Һ��ӵ�ֵ
		while (child < _con.size()){
			if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				child++;
			if (_con[child] < _con[parent]){
				swap(_con[child], _con[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else{
				//�����Ѿ����㣬��������
				break;
			}
		}
	}


	//����ѡ���ѵķ�ʽ���벢���ѵķ�ʽ����
	//void Push(const T& val){
	//	//�Ȱ�Ԫ�طŵ���������һ��λ��
	//	_con.push_back(val);
	//	shifUp(_con.size() - 1);
	//	//���ϵ�����ʹ������ѵ�����
	//}
	//
	//void shifUp(size_t child){
	//	size_t parent = (child - 1) / 2;
	//	while (child > 0){
	//		if (_con[child] > _con[parent]){
	//			swap(_con[child], _con[parent]);
	//			//���¸��ӽ���λ��
	//			child = parent;
	//			parent = (child - 1) / 2;
	//		}
	//		else{
	//			break;
	//			//�ߵ�����˵�����ڵ����ÿ���ӽڵ�Ͳ���Ҫ������
	//		}
	//	}
	//}

	//void Pop(){
	//	swap(_con[0], _con[_con.size() - 1]);
	//	//���Ѹ�Ԫ�غ�����Ҷ�ӽ�㽻��λ��
	//	_con.pop_back();
	//	//����βԪ��pop��
	//	shifDown(0);
	//	//���µ�����ʹ������ѵ�����  
	//}

	//void shifDown(size_t parent){
	//	//�Ӹ�����ʼ����
	//	size_t child = 2 * parent + 1;
	//	//���Ǵ�ѵĻ���
	//	//�����ǲ������Һ��Ӵ���,��ֵ�������ӵ�ֵ��ȡ�Һ��ӵ�ֵ
	//	while (child<_con.size()){
	//		if (child + 1 < _con.size() && _con[child + 1] > _con[child])
	//			child++;
	//		if (_con[child] > _con[parent]){
	//			swap(_con[child], _con[parent]);
	//			parent = child;
	//			child = 2 * parent + 1;
	//		}
	//		else{
	//			//�����Ѿ����㣬��������
	//			break;
	//		}
	//	}
	//}


	T& Top(){
		return _con[0];
		//���ض��е����/��С��
	}

	bool Empty(){
		return _con.empty();
	}

	size_t Size(){
		return _con.size();
	}
private:
	Container _con;
};


int main(){
	PriortyQueue<int, vector<int>> p;
	p.Push(1);
	p.Push(5);
	p.Push(3);
	p.Push(2);
	p.Push(6);
	while (!p.Empty()){
		cout << p.Top() << " ";
		p.Pop();
	}
	cout << endl;
	return 0;
}