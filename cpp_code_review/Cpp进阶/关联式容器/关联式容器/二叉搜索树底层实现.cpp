#if 0
//����������
#include<iostream>

using namespace std;


//�����Ķ���
template <class T>
struct BSTNode{
	BSTNode(const T&val=T())
	:_data(val)
	, _pLeft(nullptr)
	, _pRight(nullptr)
	{}
	T _data;
	BSTNode<T>* _pRight;
	BSTNode<T>* _pLeft;
};

//������������ʵ��

template <class T>

class BSTree{
public:
	typedef BSTNode<T>  Node;//��������
	typedef Node*  pNode;//�ṹ��ָ��

	//���캯��
	BSTree(const pNode root=nullptr) 
		:_root(root)
	{}

	pNode find(const T& val){
		if (_root == nullptr)
			return nullptr;
		pNode cur = _root;
		while (cur){
			if (cur->_data = val)
				return cur;
			else if (cur->_data > val){
				cur = cur->_pLeft;
			}
			else{
				cur = cur->_pRight;
			}
		}
		//�������ʱ��˵��û�ҵ�
		return nullptr;
	}
	/*
	������ܽ�
	����ȷ�����ڵ��Ƿ�Ϊ��,Ϊ��ֱ�ӽ�ֵ���뵽���ڵ�
	��Ϊ�յĻ�,���ն������������Բ��Һ��ʵĲ����
	���ҵ����ʵĲ�����ʱ���жϲ����Ľ��ֵ�Ͳ�����ֵ�Ĵ�С��ϵ,
	�ڽ�ֵ���뵽��Ӧ�Ľ��
	*/
	//����һ��ֵ
	bool insert(const T&val){
		
		if (_root == nullptr){
			_root = new Node(val);
			return true;
		}
		pNode cur = _root;
		pNode parent = nullptr;//��¼���ڵ��λ��
		

		while (cur){
			parent = cur;
			if (cur->_data > val){
				cur = cur->_pLeft;
			}
			else if (cur->_data < val){
				cur = cur->_pRight;
			}
			else{
				//�����������������ظ��Ľ��
				return false;
			}
		}
		pNode newnode = new Node(val);
		if (parent->_data >val){
			parent->_pLeft = newnode;
		}else
			parent->_pRight=newnode;
		return true;
	}

	//�������
	void Inorder(){
		_Inorder(_root);
		cout << endl;
	}
	void _Inorder(pNode root){
		if (root){
			_Inorder(root->_pLeft);
			cout << root->_data << "-->";
			_Inorder(root->_pRight);
		}
	}
	
	/*
	ɾ�����ܽ�
	1.Ѱ����Ҫɾ���Ľ���λ��
	2.��ʼɾ��
	2.1:ɾ��Ҷ�ӽڵ�
	  �ж���Ҫɾ���Ľ���Ƿ�Ϊ���ڵ�
	     ��������Ҷ�ӽڵ��ÿ����ɾ��
		 ���ǵĻ���ֱ�ӽ����ڵ��ÿ����ɾ��
	2.2:ɾ����Ҷ�ӽ��
	      1.ֻ�����Ӻ�ֻ���Һ��ӵ����
				��Ҫ�����ýڵ�ĸ��׽�������ӽڵ�Ĺ�ϵ
		  2.�������Ӷ��е����
				���ýڵ��������������߻�������������С���ƶ�����ǰλ��
				�ù��̷������ֵ�Ľ���������ɴ����������ӽ���ɾ��
	*/
	//ɾ������
	bool erase(const T& val){
		if (_root == nullptr)
			return false;
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur){
			if (cur->_data == val)
				break;
			else if (cur->_data > val){
				parent = cur;
				cur = cur->_pLeft;
			}
			else{
				parent = cur;
				cur = cur->_pRight;
			}
		}

		//ɾ��
		//1.ɾ��Ҷ�ӽ��
		if (cur->_pLeft == nullptr&&cur->_pRight == nullptr){
			//�Ƿ�ɾ�����ڵ�
			if (cur != _root){
				//�ø��׽���Ӧλ����Ϊ��
				if (parent->_pLeft == cur)
					parent->_pLeft = nullptr;
				else
					parent->_pRight = nullptr;
			}
			else{
				//ɾ��_root����Ϊ��
				_root = nullptr;
			}
			delete cur;
			cur = nullptr;
		}

		//2.��Ҷ�ӽڵ㣬����ֻ��һ�����(�ҽ��)
		//����ȷ����ǰ���ĸ��׽������߻����ұ�,��Ӧλ����Ϊcur->_pRight
		else if (cur->_pLeft == nullptr){
			if (cur != _root){
				if (parent->_pLeft == cur)
					//��ǰ���û�����ӣ������Һ���
					parent->_pLeft = cur->_pRight;
				else
					//��ǰ���û�����ӣ������Һ���
					parent->_pRight = cur->_pRight;
			}
			else{
				//��ɾ�����Ǹ��ڵ��
				//����_root
				_root = _root->_pRight;
			}
			delete cur;
			cur = nullptr;
		}

		//ɾ�����Ƿ�Ҷ�ӽ�㣬ȴ��ǰ�����Һ���Ϊ��
		else if (cur->_pRight == nullptr){
			if (cur != _root){
				if (parent->_pLeft == cur)
					//��ǰ���û���Һ��ӣ���������
					parent->_pLeft = cur->_pLeft;
				else
					//��ǰ���û���Һ��ӣ���������
					parent->_pRight = cur->_pLeft;
			}
			else{
				//��ɾ�����Ǹ��ڵ��
				//����_root
				_root = _root->_pLeft;
			}
			delete cur;
			cur = nullptr;
		}

		//3.���Һ��Ӷ�����,��Ҫ���û�
		else {
			//1.Ѱ���滻�ڵ�
			pNode pNext = cur->_pLeft;
			parent = cur;
			while (pNext->_pRight){
				parent = pNext;
				pNext = pNext->_pRight;
			}

			//2.�û�
			cur->_data = pNext->_data;
			//ָ���û�����ָ���ÿ�
			if (parent->_pRight == pNext)
				parent->_pRight = nullptr;
			parent->_pLeft = nullptr;
			delete pNext;
			pNext = nullptr;
		}
		return true;
	}

	
	~BSTree(){
		Distory(_root);
	}

	void Distory(pNode root){
		if (root){
			Distory(root->_pLeft);
			Distory(root->_pRight);
			delete root;
			root = nullptr;
		}
	}
private:
	pNode _root;
};

void testBSTree(){
	BSTree<int> bt;
	bt.insert(5);
	bt.insert(3);
	bt.insert(4);
	bt.insert(1);
	bt.insert(0);
	bt.insert(2);
	bt.insert(7);
	bt.insert(6);
	bt.insert(8);
	bt.insert(9);
	cout<<bt.find(5)<<endl;
	bt.Inorder();
	bt.erase(4);
	bt.Inorder();
	bt.erase(8);
	bt.Inorder();
	bt.erase(0);
	bt.Inorder();
	bt.erase(1);
	bt.Inorder();
	bt.erase(2);
	bt.Inorder();
	bt.erase(5);
	bt.Inorder();
	bt.erase(3);
	bt.Inorder();
	bt.erase(7);
	bt.Inorder();
	bt.erase(6);
	bt.Inorder();
	bt.erase(9);
}

int main(){
	testBSTree();
	return 0;
}
#endif 
