#include<iostream>

using namespace std;

template <class T>
struct ListNode{
	ListNode(const T&val=T())
	:_prev(nullptr)
	, _next(nullptr)
	, _data(val)
	{}
	ListNode<T>* _prev;
	ListNode<T> *_next;
	T _data;
	//每个双链表节点的结构
};
template <class T>
class List{
public:
	typedef ListNode Node;
	typedef Node* pNode;
	List(const T&val=T())
		:_head(new Node(val))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}
	List(const List<T> &lst){
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
		for (auto& e : lst){
			Push_Back(e);
		}
	}
	//传统写法的赋值运算符重载
	//List<T> &operator=(const List<T>& lst){
	//	if (this != &lst){
	//		clear();
	//		for (auto& e : lst){
	//			Push_Back(e);
	//		}
	//	}
	//	return *this;
	//	//如果是自己给自己赋值的话直接将this指针 返回即可
	//}

	void clear(){
		if (_head){
			pNode cur = _head->_next;
			while (cur != _head){
				pNode next = cur->_next;
				delete cur;
				//删除_head之后的所有节点
			}
			_head->_prev = _head;
			_head->_next = _head;
			//将循环双链表连接起来(置为空表)
		}
	}

	//现代写法
	List<T>& operator=(const List<T>&lst){
		swap(_head, lst->_head);
		return *this;
	}

	void Push_Back(const T&val){
		pNode newnode = new Node(val);
		pNode cur = _head->_prev;
		cur->_next = newnode;
		newnode->_prev = cur;
		newnode->_next = _head;
		_head->prev = newnode;
	}
private:
	T _head;
};

int main(){

	return 0;
}