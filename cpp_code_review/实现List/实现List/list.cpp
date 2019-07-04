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
//�÷��������const_iterator��iterator������
template <class T,class Ref,class Ptr>
struct ListIterator{
	typedef ListNode<T> *pNode;
	typedef ListIterator<T, Ref, Ptr> self;
	pNode _node;
	ListIterator(pNode node)
		:_node(node)
	{}
	//++iterator
	//���ص���������
	//�������Լ��Ķ���������self
	self& operator++(){
		_node = _node->_next;
		return *this;
	}
	//iterator++;
	//����û�иı��ֵ��
	//�ƶ�����һ���ڵ��λ��
	self operator++(int){
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	
	//iterator !=l.end();
	//�Ƚ��ǲ���ͬһ���ڵ�(�Ƚ������ߵĵ�ַ�Ƿ���һ����)
	bool operator!=(const self& it){
		return _node != it._node;
	}
	//--it(ǰ��--),
	self& operator--(){
		_node = _node->_prev;
		return *this;
	}
	//it--(����--)����û�б��ֵ��Ȼ������--��
	self operator--(int){
		self tmp(*this);
		//��Ϊ���ص�û�б�֮ǰ�Ķ������������ⱸ��һ��
		_node = _node->_prev;
		return tmp;
	}

	//*iterator(������)
	//��ȡ�ڵ��_data
	Ref operator*(){
		return _node->_data;
	}


	//�ṹ���������
	//struct
	Ptr operator->(){
		return &_node->_data;
	}
};
//������ʵ��:ͨ����װ�ڵ㣬ʹ�ýڵ�Ĳ�����ɵ����� ��++
//��*��--��!=��==����
//��������
//1.���Ԫ�صķ��ʣ�������ָ���++��--��*����=��==��Щ����
//2.���������ڵ�֮��ռ䲻������ԭ��ָ��++��--
//�����ƶ�����һ���ڵ��λ�á�����������ʹ��ԭ��ָ��ʵ��
//3.��ͨ����װ�ڵ㣬���ʵ�ֵ���������ز���
//++��--��ͨ���ڵ��->next,->prevʵ��
//*:ͨ����ȡ�ڵ������ʵ��
//!+,==ͨ���жϽڵ�ĵ�ַ�Ƿ����ʵ��



//template <class T>
//struct ConstListIterator{
//	typedef ListNode<T> *pNode;
//	typedef ConstListIterator<T> self;
//	pNode _node;
//	ConstListIterator(pNode node)
//		:_node(node)
//	{}
//	//++iterator
//	//���ص���������
//	//�������Լ��Ķ���������self
//	self& operator++(){
//		_node = _node->_next;
//		return *this;
//	}
//	//iterator++;
//	//����û�иı��ֵ��
//	//�ƶ�����һ���ڵ��λ��
//	self operator++(int){
//		self tmp(*this);
//		_node = _node->_next;
//		return tmp;
//	}
//
//	
//	//iterator !=l.end();
//	//�Ƚ��ǲ���ͬһ���ڵ�(�Ƚ������ߵĵ�ַ�Ƿ���һ����)
//	bool operator!=(const self& it){
//		return _node != it._node;
//	}
//	//--it(ǰ��--),
//	self& operator--(){
//		_node = _node->_prev;
//		return *this;
//	}
//	//it--(����--)����û�б��ֵ��Ȼ������--��
//	self operator--(int){
//		self tmp(*this);
//		//��Ϊ���ص�û�б�֮ǰ�Ķ������������ⱸ��һ��
//		_node = _node->_prev;
//		return tmp;
//	}
//	//�ṹ���������
//	//struct
//	const T* operator->(){
//		return &_node->_data;
//	}
//
//	//*iterator(������)
//	//��ȡ�ڵ��_data
//	const T& operator*(){
//		return _node->_data;
//	}
//};
//��iterator��const_iterator��֮ͬ����
//iterator��const_iteratorΨһ��ͬ�ĵط�����:������*��->����ֵ��ͬ
//iterator��*��->�������ǿɶ���д�Ĳ���������ֵ����const
//const_iterator*  ��->����ֻ�ǿɶ�����������ֵ��const

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
	 //const�����ܵ��÷�const��Ա����ֻ�ܵ���const��Ա����operator++,
	//operator--�Ͳ���ִ����,�����޸ĳ�Ա_node��ֵ
	//����const�������޷�ִ��++��--����������������const������������
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
		//��ͷ�ڵ�֮������ýڵ�ȫ�����
		if (_head){
			delete[] _head;
			_head = nullptr;
		}
	}
	//list��Ҫʵ�����������ǳ����ֻ��������ģ���е�ͷָ��
	//���´���ڵ㣬���������ͷŽڵ��ʱ�����ɶ����ͷţ����³�����
	List(const List<T> &lst){
		//���ȴ���ͷָ��
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
		//����ÿһ���ڵ�,��������ͷ��ʼ����ÿһ���ڵ�
		//���뵽��ǰlist������ȥ
		for (const auto&e:lst){
			PushBack(e);
		}
		//���ʵ����Դ�Ŀ���
	}

	//��ͳд��
	//List<T> &operator=(const List<T>& lst){
	//	if (this != &lst){
	//		//�ͷ�ԭ�нڵ�
	//		clear();
	//		for (const auto&e : lst){
	//			PushBack(e);
	//		}
	//	}
	//	return *this;
	//}
	

	//�ִ�д��
	//�����Ƿ�������,���ÿ�������
	List<T>& operator=(List<T> lst){
		swap(_head,lst._head);
		return *this;
	}


	//β��
	void PushBack(const T& val){
		//pNode curNode = new Node(val);
		////�����õ�β��Ԫ��
		//pNode tail = _head->_prev;
		//tail->_next = curNode;
		//curNode->_prev = tail;
		//curNode->_next = _head;
		//_head->_prev = curNode;
		Insert(end(), val);
	}
	//��ͷ˫��ѭ���������κνṹ�����������һ���� 

	iterator begin(){
		return iterator(_head->_next);
		//ʹ�ö���ĵ�����������_head��_next
		//��װ����������Ķ���
	}

	iterator end(){
		return iterator(_head);
	}

	const_iterator begin() const{
		return const_iterator(_head->_next);
		//ʹ�ö���ĵ�����������_head��_next
		//��װ����������Ķ���
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
	//Erase:������ʧЧ
	//��ȡErase�ķ���ֵ�����µ�����
	//���ص��ǵ�ǰ��ɾ���Ľڵ����һ��λ��
	iterator Erase(iterator pos){
		if (pos != end()){
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			//���µ�����,ָ����һ��λ��
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