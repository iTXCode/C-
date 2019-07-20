#include<iostream>

using namespace std;


template<class T>
struct ListNode{
	//定义了循环双链表的每个结点结构
	ListNode(const T&val = T())
	:_prev(nullptr)
	, _next(nullptr)
	, _data(val)
	{}
	ListNode<T>* _prev;
	ListNode<T>* _next;
	T _data;
};

template<class T,class Ref,class Ptr>
struct ListIterator{
	//结构体默认的权限是公有的
	//class 默认的权限是私有的
	typedef ListNode<T>* pNode;
	typedef ListIterator<T,Ref,Ptr> self;
	//泛型编程版的迭代器，是iterator和const_iterator
	//公用模板
	pNode _node;
	ListIterator(pNode node)
		:_node(node)
	{}

	//++iterator
	self& operator++(){
		_node=_node->_next;
		return *this;
	}
	//iterator++
	//后置++不反回引用的原因是该函数需要返回函数
	//内部是局部变量(除了作用域范围生命周期就结束了)
	self operator++(int){
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	//--iterator
	self& operator--()
	{
		_node = _node->_prev;
		return  *this;
	}
	//iterator--
	self operator--(int){
		self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	//比较两个结点不是同一个结点
	bool operator!=(const self& lst){
		return _node != lst._node;
	}

	//去迭代器内的值
	//*iterator(解引用)
	Ref operator*(){
		return _node->_data;
	}
	//访问结构体内容
	Ptr operator->(){
		return &_node->_data;
	}

};
template <class T>
class List{
public:
	typedef  ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&,const T*> const_iterator;
	List(const T &val = T())
		:_head(new Node(val))
	{
		_head->_prev = _head;
		_head->_next = _head;
		//空的循环双链表
	}

	//拷贝构造函数的实现
	List(const List<T> &lst){
		_head = new Node;
		_head->_prev = _head;
		_head->_next = _head;

		for (auto& e : lst)
			PushBack(e);
	}
	/*
	1.首先申请新的结点
	2.将循环双链表设置为空
	3.实现资源的拷贝
	【注意】
	不能简单的将_head指向l的资源，可能造成二次释放
	*/

	~List(){
		clear();
		if (_head){
			delete[] _head;
			_head = nullptr;
		}
	}
	List<T>& operator=(List<T>& lst){
		swap(_head, lst._head);
		return *this;
	}

	void PushBack(const T &val){
		pNode cur = new Node(val);
		pNode tmp = _head->_next;
		_head->_prev=cur;
		cur->_next = _head;
		tmp->_next = cur;
		cur->_prev = tmp;
	}

	void insert(iterator pos,const T&val){
		pNode tmp = new Node(val);
		pNode tail = pos._node;
		pNode cur = tail->_prev;
		tail->_next = tmp;
		tmp->_prev = tail;
		tmp->_next = cur;
		cur->_prev = tmp;
	}

	void PushFront(const T& val){
		insert(begin(), val);
		//头插
	}
	

	iterator Erase(iterator pos){
		if (pos != end()){
			pNode cur = pos->_node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			cur->_prev = prev;
			cur->_next = next;
			delete cur;
			pos = iterator (next);
		}
		return pos;
	}
	iterator begin(){
		return iterator(_head->_next);
	}
	iterator end(){
		return iterator(_head);
	}
	const_iterator begin()const {
		return const_iterator(_head->_next);
	}
	const_iterator end()const{
		return const_iterator(_head);
	}
	void PopFront(){
		Erase(begin());
	}

	void PopBack(){
		Erase(--end());
	}
	//此处的end()函数所返回的结点是头指针
	void clear(){
		if (_head){
			pNode tmp = _head->_next;
			while (tmp != _head){
				pNode next = tmp->_next;
				delete tmp;
				tmp = next;
			}
		}
		_head->_next = _head;
		_head->_prev = _head;
	}
	//自己的错误点在于，错以为头指针一直要指着头节点
	//只要空间不丢失的话，可以一直将循环双链表清除干净
private:
	pNode _head;
	//指向双端链表的头节点
};


template<class T>
void PrintList(const List<T>& L){
	auto lst = L.begin();
	while (lst != L.end()){
		cout << (*lst) << " ";
		lst++;
	}
	cout << endl;
}

int  main(){
	List<int> l;
	l.PushBack(1);
	l.PushFront(2);
	PrintList(l);
	List<char*> L;
	L.PushBack("hello ");
	L.PushBack("world!");
	PrintList(L);
	return 0;
}