#include<iostream>

using namespace std;


template<class T>
struct ListNode{
	//������ѭ��˫�����ÿ�����ṹ
	ListNode(const T&val=T() )
	:_prev(nullptr)
	, _next(nullptr)
	, _data(val)
	{}
	ListNode<T>* _prev;
	ListNode<T>* _next;
	T _data;
};
template <class T>
class List{
public:
	typedef  ListNode<T> Node;
	typedef Node* pNode;
	List(const T &val=T() )
	:_head(new Node(val))
	{
		_head->_prev = _head;
		_head->_next = _head;
		//��򵥵ĵ�ͷѭ��˫����
	}
private:
	pNode _head;
	//ָ��˫�������ͷ�ڵ�
};

int  main(){
	List<int> l;
	return 0;
}