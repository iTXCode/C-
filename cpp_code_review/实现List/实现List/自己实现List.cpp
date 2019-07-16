#include<iostream>

using namespace std;


template<class T>
struct ListNode{
	//定义了循环双链表的每个结点结构
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
		//最简单的到头循环双链表
	}
private:
	pNode _head;
	//指向双端链表的头节点
};

int  main(){
	List<int> l;
	return 0;
}