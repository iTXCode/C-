#if 0
//二叉搜索树
#include<iostream>

using namespace std;


//树结点的定义
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

//搜索二叉树的实现

template <class T>

class BSTree{
public:
	typedef BSTNode<T>  Node;//结点的引用
	typedef Node*  pNode;//结构体指针

	//构造函数
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
		//到这里的时候说明没找到
		return nullptr;
	}
	/*
	插入的总结
	首先确定根节点是否为空,为空直接将值插入到根节点
	不为空的话,按照二叉搜索树的性查找合适的插入点
	当找到合适的插入点的时候判断插入点的结点值和插入结点值的大小关系,
	在将值插入到对应的结点
	*/
	//插入一个值
	bool insert(const T&val){
		
		if (_root == nullptr){
			_root = new Node(val);
			return true;
		}
		pNode cur = _root;
		pNode parent = nullptr;//记录根节点的位置
		

		while (cur){
			parent = cur;
			if (cur->_data > val){
				cur = cur->_pLeft;
			}
			else if (cur->_data < val){
				cur = cur->_pRight;
			}
			else{
				//二叉搜索树不存在重复的结点
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

	//中序遍历
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
	删除的总结
	1.寻找所要删除的结点的位置
	2.开始删除
	2.1:删除叶子节点
	  判断索要删除的结点是否为根节点
	     若不是则将叶子节点置空最后删除
		 若是的话，直接将根节点置空最后删除
	2.2:删除非叶子结点
	      1.只有左孩子和只有右孩子的情况
				需要建立该节点的父亲结点与其子节点的关系
		  2.两个孩子都有的情况
				将该节点的左子树中最大者或者右子树中最小者移动到当前位置
				该过程发生结点值的交换最终完成带有两个孩子结点的删除
	*/
	//删除操作
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

		//删除
		//1.删除叶子结点
		if (cur->_pLeft == nullptr&&cur->_pRight == nullptr){
			//是否删除根节点
			if (cur != _root){
				//让父亲结点对应位置置为空
				if (parent->_pLeft == cur)
					parent->_pLeft = nullptr;
				else
					parent->_pRight = nullptr;
			}
			else{
				//删除_root，树为空
				_root = nullptr;
			}
			delete cur;
			cur = nullptr;
		}

		//2.非叶子节点，但是只有一个结点(右结点)
		//首先确当当前结点的父亲结点在左边还是右边,对应位置置为cur->_pRight
		else if (cur->_pLeft == nullptr){
			if (cur != _root){
				if (parent->_pLeft == cur)
					//当前结点没有左孩子，但有右孩子
					parent->_pLeft = cur->_pRight;
				else
					//当前结点没有左孩子，但有右孩子
					parent->_pRight = cur->_pRight;
			}
			else{
				//若删除的是根节点的
				//更新_root
				_root = _root->_pRight;
			}
			delete cur;
			cur = nullptr;
		}

		//删除的是非叶子结点，却当前结点的右孩子为空
		else if (cur->_pRight == nullptr){
			if (cur != _root){
				if (parent->_pLeft == cur)
					//当前结点没有右孩子，但有左孩子
					parent->_pLeft = cur->_pLeft;
				else
					//当前结点没有右孩子，但有左孩子
					parent->_pRight = cur->_pLeft;
			}
			else{
				//若删除的是根节点的
				//更新_root
				_root = _root->_pLeft;
			}
			delete cur;
			cur = nullptr;
		}

		//3.左右孩子都存在,需要做置换
		else {
			//1.寻找替换节点
			pNode pNext = cur->_pLeft;
			parent = cur;
			while (pNext->_pRight){
				parent = pNext;
				pNext = pNext->_pRight;
			}

			//2.置换
			cur->_data = pNext->_data;
			//指向置换结点的指针置空
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
