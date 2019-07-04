#include<iostream>

using namespace std;
template <class T>
struct ListNode{
	ListNode(const T& val=T())
	:_next(nullptr)
	, _prev(nullptr)
	, _data(val)
	{}
	ListNode<T>* _next;
	ListNode<T> *_prev;
	T _data;
};


//template <class T>
//用泛型来解决const_iterator和iterator的问题
template <class T,class Ref,class Ptr>
struct ListIterator{
	typedef ListNode<T> *pNode;
	typedef ListIterator<T, Ref, Ptr> self;
	pNode _node;
	ListIterator(pNode node)
		:_node(node)
	{}
	//++iterator
	//返回迭代器本身
	//定义其自己的东西引入了self
	self& operator++(){
		_node = _node->_next;
		return *this;
	}
	//iterator++;
	//返回没有改变的值；
	//移动到下一个节点的位置
	self operator++(int){
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	
	//iterator !=l.end();
	//比较是不是同一个节点(比较其两者的地址是否是一样的)
	bool operator!=(const self& it){
		return _node != it._node;
	}
	//--it(前置--),
	self& operator--(){
		_node = _node->_prev;
		return *this;
	}
	//it--(后置--)返回没有变得值，然后自身--；
	self operator--(int){
		self tmp(*this);
		//因为返回的没有变之前的东西，所以在这备份一下
		_node = _node->_prev;
		return tmp;
	}

	//*iterator(解引用)
	//获取节点的_data
	Ref operator*(){
		return _node->_data;
	}


	//结构体访问内容
	//struct
	Ptr operator->(){
		return &_node->_data;
	}
};
//迭代器实现:通过封装节点，使用节点的操作完成迭代器 的++
//，*，--，!=，==功能
//迭代器：
//1.完成元素的访问，类似于指针的++，--，*，！=，==这些操作
//2.对于链表，节点之间空间不连续，原生指针++，--
//不能移动到下一个节点的位置。迭代器不能使用原生指针实现
//3.故通过封装节点，间接实现迭代器的相关操作
//++，--；通过节点的->next,->prev实现
//*:通过获取节点的数据实现
//!+,==通过判断节点的地址是否相等实现



//template <class T>
//struct ConstListIterator{
//	typedef ListNode<T> *pNode;
//	typedef ConstListIterator<T> self;
//	pNode _node;
//	ConstListIterator(pNode node)
//		:_node(node)
//	{}
//	//++iterator
//	//返回迭代器本身
//	//定义其自己的东西引入了self
//	self& operator++(){
//		_node = _node->_next;
//		return *this;
//	}
//	//iterator++;
//	//返回没有改变的值；
//	//移动到下一个节点的位置
//	self operator++(int){
//		self tmp(*this);
//		_node = _node->_next;
//		return tmp;
//	}
//
//	
//	//iterator !=l.end();
//	//比较是不是同一个节点(比较其两者的地址是否是一样的)
//	bool operator!=(const self& it){
//		return _node != it._node;
//	}
//	//--it(前置--),
//	self& operator--(){
//		_node = _node->_prev;
//		return *this;
//	}
//	//it--(后置--)返回没有变得值，然后自身--；
//	self operator--(int){
//		self tmp(*this);
//		//因为返回的没有变之前的东西，所以在这备份一下
//		_node = _node->_prev;
//		return tmp;
//	}
//	//结构体访问内容
//	//struct
//	const T* operator->(){
//		return &_node->_data;
//	}
//
//	//*iterator(解引用)
//	//获取节点的_data
//	const T& operator*(){
//		return _node->_data;
//	}
//};
//【iterator和const_iterator不同之处】
//iterator和const_iterator唯一不同的地方在于:操作符*和->返回值不同
//iterator的*和->操作都是可读可写的操作，返回值不加const
//const_iterator*  和->操作只是可读操作，返回值加const

class Date
{
public:
	int _year;
	int _month;
	int _day;
};

template <class T>
class List{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T,T&,T*> iterator;
	//typedef ConstListIterator<T> const_iterator;
	//typedef const ListIterator<T> const_iterator;
	 //const对象不能调用非const成员函数只能调用const成员函数operator++,
	//operator--就不能执行了,不能修改成员_node的值
	//导致const迭代器无法执行++，--操作，故这样定义const迭代器不可行
	//

	typedef ListIterator<T,const T&, const T*> const_iterator;
	List(const T&val=T())
		:_head(new Node(val))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}

	~List(){
		clear();
		//把头节点之外的所用节点全部清除
		if (_head){
			delete[] _head;
			_head = nullptr;
		}
	}
	//list需要实现深拷贝，否则浅拷贝只拷贝对象模型中的头指针
	//不会拷贝节点，析构函数释放节点的时候会造成二次释放，导致程序奔溃
	List(const List<T> &lst){
		//首先创建头指针
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
		//拷贝每一个节点,迭代器从头开始遍历每一个节点
		//插入到当前list对象中去
		for (const auto&e:lst){
			PushBack(e);
		}
		//深拷贝实现资源的拷贝
	}

	//传统写法
	//List<T> &operator=(const List<T>& lst){
	//	if (this != &lst){
	//		//释放原有节点
	//		clear();
	//		for (const auto&e : lst){
	//			PushBack(e);
	//		}
	//	}
	//	return *this;
	//}
	

	//现代写法
	//传参是发生拷贝,调用拷贝构造
	List<T>& operator=(List<T> lst){
		swap(_head,lst._head);
		return *this;
	}


	//尾插
	void PushBack(const T& val){
		//pNode curNode = new Node(val);
		////首先拿到尾部元素
		//pNode tail = _head->_prev;
		//tail->_next = curNode;
		//curNode->_prev = tail;
		//curNode->_next = _head;
		//_head->_prev = curNode;
		Insert(end(), val);
	}
	//带头双向循环链表，对任何结构，插入操作是一样的 

	iterator begin(){
		return iterator(_head->_next);
		//使用定义的迭代器函数将_head的_next
		//封装成像迭代器的东西
	}

	iterator end(){
		return iterator(_head);
	}

	const_iterator begin() const{
		return const_iterator(_head->_next);
		//使用定义的迭代器函数将_head的_next
		//封装成像迭代器的东西
	}

	const_iterator end() const{
		return const_iterator(_head);
	}
	void Insert(iterator pos,const T& val){
		pNode newnode = new Node(val);
		pNode cur = pos._node;
		pNode prev = cur->_prev;
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = cur;
		cur->_prev = newnode;
	}
	void PushFront(const T&val){
		Insert(begin(), val);
	}
	//Erase:迭代器失效
	//获取Erase的返回值，更新迭代器
	//返回的是当前被删除的节点的下一个位置
	iterator Erase(iterator pos){
		if (pos != end()){
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			//更新迭代器,指向下一个位置
			pos = iterator(next);
		}
		return pos;
	}

	void PopFront(){
		Erase(begin());
	}
	void PopBack(){
		Erase(--end());
	}

	void clear(){
		if (_head){
			pNode cur = _head->_next;
			while (cur != _head){
				pNode next = cur->_next;
				delete cur;
				cur = next;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
	}
private:
	pNode _head;
};

//void testIterator(){
//	List<Date> lst;
//	lst.PushBack(Date());
//	lst.PushBack(Date());
//	lst.PushBack(Date());
//	auto lit = lst.begin();
//	while (lit != lst.end()){
//		lit.operator->()->_year = 2018;
//		lit->_year = 2018;
//		lit->_month = 1;
//		lit->_day = 1;
//		cout << (*lit)._year << endl;
//		cout << lit->_year << "-" << lit->_month << "-" << lit->_day << " ";
//		++lit;
//	}
//	cout << endl;
//}

template <class T>
void printList(const List<T>& lt){
	auto lit = lt.begin();
	while (lit != lt.end()){
		cout << *lit << " "; 
		++lit;
	}
	cout << endl;
}

int main(){
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	printList(l);
	l.Erase(l.begin());
	printList(l);
	l.Erase(--l.end());
	printList(l);
	List<int> l1;
	l1 = l;
	printList(l1);
	return 0;
}