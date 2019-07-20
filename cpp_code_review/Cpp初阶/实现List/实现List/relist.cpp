#include<iostream>

using namespace std;


template<class T>
struct ListNode{
	//������ѭ��˫�����ÿ�����ṹ
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
	//�ṹ��Ĭ�ϵ�Ȩ���ǹ��е�
	//class Ĭ�ϵ�Ȩ����˽�е�
	typedef ListNode<T>* pNode;
	typedef ListIterator<T,Ref,Ptr> self;
	//���ͱ�̰�ĵ���������iterator��const_iterator
	//����ģ��
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
	//����++���������õ�ԭ���Ǹú�����Ҫ���غ���
	//�ڲ��Ǿֲ�����(����������Χ�������ھͽ�����)
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

	//�Ƚ�������㲻��ͬһ�����
	bool operator!=(const self& lst){
		return _node != lst._node;
	}

	//ȥ�������ڵ�ֵ
	//*iterator(������)
	Ref operator*(){
		return _node->_data;
	}
	//���ʽṹ������
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
		//�յ�ѭ��˫����
	}

	//�������캯����ʵ��
	List(const List<T> &lst){
		_head = new Node;
		_head->_prev = _head;
		_head->_next = _head;

		for (auto& e : lst)
			PushBack(e);
	}
	/*
	1.���������µĽ��
	2.��ѭ��˫��������Ϊ��
	3.ʵ����Դ�Ŀ���
	��ע�⡿
	���ܼ򵥵Ľ�_headָ��l����Դ��������ɶ����ͷ�
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
		//ͷ��
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
	//�˴���end()���������صĽ����ͷָ��
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
	//�Լ��Ĵ�������ڣ�����Ϊͷָ��һֱҪָ��ͷ�ڵ�
	//ֻҪ�ռ䲻��ʧ�Ļ�������һֱ��ѭ��˫��������ɾ�
private:
	pNode _head;
	//ָ��˫�������ͷ�ڵ�
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