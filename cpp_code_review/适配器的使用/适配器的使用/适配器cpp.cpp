#if 0
#include <iostream>

//双端队列
using namespace std;

//迭代器的实现
//为了实现迭代器的模板话(普通迭代器和const迭代器的代码复用)
//一般使用三个参数的方法来实现该功能
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
	T* frist; //指向缓冲区的第一个位置
	T* last;  //指向缓冲区的最后一个位置
	T* cur;   //此迭代器所指的 缓冲区中的现行元素，用于"遍历"缓冲区
	T** node;//指向中控的指针
};

//++node后的更新
//first=*node;
//cur=first;
//last=first+缓冲区的长度

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
//优先队列
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
	//创建的堆默认是大堆
	while (!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}


	//定义小堆的方式
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(100);
	q.push(1);
	q.push(12);
	q.push(14);
	q.push(0);
	//创建的堆默认是大堆
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
	cout << "默认大堆:" << endl;
	while (!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << "小堆:" << endl;
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


//适配器
#include<iostream>
#include<vector>
#include<list>
using  namespace std;

template <class T, class Container>


//template <class T,class Container=list<T>>
//定义的时候可以给一个默认的模板参数
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
//queue本来就是适配器，所以底层用双端队列来实现(deque)

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

//适配器：把已有的容器转换为另一种容器的设计方法，本质上是一种 转换
// stack：可以用list, vector, deque
//默认用deque队列：尾插尾删时间复杂度为O(1)，
//增容的代价比较小。每次只需要开辟新的buffer，
//如果中控满载，只需要开辟一个更大的区域，把指针数组拷贝，
//不需要拷贝数据，也不会造成内存碎片


//queue : 可以用list和deque，默认是deque, 
//不能用vector实现，vector不提供pop_front接口
//priority_queue : 可以用vector，
//deque默认的容器vector，因vector随机访问效率高，
//它底层的逻辑结构是堆，
//不能用list实现在插入删除的时候，
//不能通过随机访问的形式进行元素的 调整 ，
//无法保证堆的性质。

#endif


////仿函数或者叫函数对象
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
//	//可以使用自己定义的仿函数来使用优先队列
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




//堆的实现
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <class T, class Container = vector<T>>

class PriortyQueue{
public:

	//小堆中插入元素
	void Push(const T& val){
		//先把元素放到数组的最后一个位置
		_con.push_back(val);
		shifUp(_con.size() - 1);
		//向上调整，使其满足堆的性质
	}
	//小堆的方式插入并按堆的方式调节

	void shifUp(size_t child){
		size_t parent = (child - 1) / 2;
		while (child > 0){
			if (_con[child] < _con[parent]){
				swap(_con[child], _con[parent]);
				//更新父子结点的位置
				child = parent;
				parent = (child - 1) / 2;
			}
			else{
				break;
				//走到这里说明父节点大于每个子节点就不需要调整了
			}
		}
	}

	void Pop(){
		swap(_con[0], _con[_con.size() - 1]);
		//将堆根元素和最后的叶子结点交换位置
		_con.pop_back();
		//将堆尾元素pop掉
		shifDown(0);
		//向下调整，使其满足堆的性质  
	}

	void shifDown(size_t parent){
		//从根部开始调整
		size_t child = 2 * parent + 1;
		//还是大堆的话；8
		//看看是不是有右孩子存在,且值大于左孩子的值，取右孩子的值
		while (child < _con.size()){
			if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				child++;
			if (_con[child] < _con[parent]){
				swap(_con[child], _con[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else{
				//性质已经满足，结束调整
				break;
			}
		}
	}


	//【大堆】大堆的方式插入并按堆的方式调节
	//void Push(const T& val){
	//	//先把元素放到数组的最后一个位置
	//	_con.push_back(val);
	//	shifUp(_con.size() - 1);
	//	//向上调整，使其满足堆的性质
	//}
	//
	//void shifUp(size_t child){
	//	size_t parent = (child - 1) / 2;
	//	while (child > 0){
	//		if (_con[child] > _con[parent]){
	//			swap(_con[child], _con[parent]);
	//			//更新父子结点的位置
	//			child = parent;
	//			parent = (child - 1) / 2;
	//		}
	//		else{
	//			break;
	//			//走到这里说明父节点大于每个子节点就不需要调整了
	//		}
	//	}
	//}

	//void Pop(){
	//	swap(_con[0], _con[_con.size() - 1]);
	//	//将堆根元素和最后的叶子结点交换位置
	//	_con.pop_back();
	//	//将堆尾元素pop掉
	//	shifDown(0);
	//	//向下调整，使其满足堆的性质  
	//}

	//void shifDown(size_t parent){
	//	//从根部开始调整
	//	size_t child = 2 * parent + 1;
	//	//还是大堆的话；
	//	//看看是不是有右孩子存在,且值大于左孩子的值，取右孩子的值
	//	while (child<_con.size()){
	//		if (child + 1 < _con.size() && _con[child + 1] > _con[child])
	//			child++;
	//		if (_con[child] > _con[parent]){
	//			swap(_con[child], _con[parent]);
	//			parent = child;
	//			child = 2 * parent + 1;
	//		}
	//		else{
	//			//性质已经满足，结束调整
	//			break;
	//		}
	//	}
	//}


	T& Top(){
		return _con[0];
		//返回堆中的最大/最小的
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