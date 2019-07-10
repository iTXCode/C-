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
	//ÿ��˫����ڵ�Ľṹ
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
	//��ͳд���ĸ�ֵ���������
	//List<T> &operator=(const List<T>& lst){
	//	if (this != &lst){
	//		clear();
	//		for (auto& e : lst){
	//			Push_Back(e);
	//		}
	//	}
	//	return *this;
	//	//������Լ����Լ���ֵ�Ļ�ֱ�ӽ�thisָ�� ���ؼ���
	//}

	void clear(){
		if (_head){
			pNode cur = _head->_next;
			while (cur != _head){
				pNode next = cur->_next;
				delete cur;
				//ɾ��_head֮������нڵ�
			}
			_head->_prev = _head;
			_head->_next = _head;
			//��ѭ��˫������������(��Ϊ�ձ�)
		}
	}

	//�ִ�д��
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