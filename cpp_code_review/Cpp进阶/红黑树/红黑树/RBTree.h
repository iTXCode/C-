#pragma once 

#include<iostream>
using namespace std;

enum COLOR{
	RED, BLACK
};
template <class T>

struct RBTreeNode{
	RBTreeNode(const T& data = T(), COLOR color = RED)
	:_pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _data(data)
	, _color(color)
	{}
	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	T _data;
	COLOR _color;

};

template<class T>
struct RBTreeIterator{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;
public:
	RBTreeIterator(Node* pNode)
		:_pNode(pNode)
	{

	}

	//具有指针操作
	T& operator*(){
		return _pNode->_data;
	}

	T& operator->(){
		return &(operator*());
		//一般不直接取,通过解引用的方式来取地址
	}

	//迭代器可以移动
	//前置++
	Self& operator++(){
		Increament();
		return *this;
	}
	//后置++
	Self operator++(int){
		Self temp(*this);
		Increament();
		return temp;
	}

	//前置--
	Self& operator--(){
		DeIncreament();
		return *this;
	}

	Self& operator--(int){
		Self temp(*this);
		DeIncreament();
		return temp;
	}

	bool operator==(const Self &s)const{
		return _pNode == s._pNode;
	}
	bool operator!=(const Self &s)const{
		return _pNode != s._pNode;
	}
private:
	void Increament(){
		if (_pNode->_pRight){
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft){
				_pNode = _pNode->_pLeft;
			}
		} 
		else{
			//比_pNode大的元素可能在其双亲中
			Node* pParent = _pNode->_pParent;
			while (_pNode == pParent->_pRight){
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			//根节点没有右子树,并且迭代器正好在根节点的位置
			if (_pNode->_pRight!=pParent)
			_pNode = pParent;
		}
	}

	void DeIncreament(){
		//end--能够走到最大节点的位置

		if (_pNode->_pParent->_pParent == _pNode&& RED==_pNode->_color){
			_pNode = _pNode->_pRight;
		}
		else if (_pNode->_pLeft){
			//如果左子树存在,在左子树中找最大的节点
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight){
				_pNode = _pNode->_pRight;
			}
		}
		else{
			//如果这个左子树不存在,就从该节点开始向上找
			Node* pParent = _pNode->_pParent;
			while (_pNode == pParent->_pLeft){
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			_pNode = pParent;
		}

	}
private:
	Node * _pNode;
};

template  <class T,class KOFV>

class RBTree{
	typedef RBTreeNode<T> Node;
public:
	//迭代器使用的接口实现
	typedef RBTreeIterator<T> iterator;

	iterator begin(){
		return iterator(_pHead->_pLeft);
	}
	iterator end(){
		return iterator(_pHead);
	}
	iterator Find(const T&data)const{
		Node* pCur = _pHead->_pParent;
		while (pCur)
		{
			if (KOFV()(data) == KOFV()(pCur->_data)){
				return iterator(pCur);
			}
			else if (KOFV()(data) < KOFV()(pCur->_data)){
				pCur = pCur->_pLeft;
			}
			else{
				pCur = pCur->_pRight;
			}
			return end();//没找到
		}
	}
public:
	RBTree()
		:_size(0)
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
		//只有一个节点的时候,该节点和头结点
		//建立起联系,让整个树完整的体现
	}

	pair<iterator,bool> Insert(const T&data){
		//首先判断红黑树是否为空,判断头结点的双亲指针域是否为空
		//若为空,则其为空树
		Node*& pRoot = GetRoot();
		Node* pNewNode = nullptr;
		if(nullptr == pRoot){
			//处理只有头结点,没有根节点的情况
			//空树的处理方式
			pNewNode =pRoot= new Node(data,BLACK);
			pRoot->_pParent = _pHead;
			
		}
		else{
			//1.按照二叉搜索树的性质，
			//找到待插入节点再红黑树中的位置
			Node* pCur = pRoot;
			Node* pParent = nullptr;
			while (pCur){
				pParent = pCur;
				if (KOFV()(data)<KOFV()(pCur->_data))
					//KOFV()()仿函数的使用方式
					pCur = pCur->_pLeft;
				else if (KOFV()(data)>KOFV()(pCur->_data))
					pCur = pCur->_pRight;
				else
					return make_pair(iterator(pCur),false);
				//红黑树不允许存在节点数据相同的情况
			}
			//插入新的节点,不指明颜色即为红色
			pNewNode = pCur = new Node(data);
			if (KOFV()(data )< KOFV()(pParent->_data))
				pParent->_pLeft = pCur;
			else
				pParent->_pRight = pCur;
			pCur->_pParent = pParent;//更新插入节点的双亲节点

			//检测:新节点插入后,是否有连在一起的红色节点
			while (pParent != _pHead && RED == pParent->_color){
				//【情况一】:要插入位置的父亲节点为红色
				//祖父为根节点的情况,
				//插入的节点若为黑色,该路径上就多了一个黑色节点
				//(只将双亲节点给成黑色也会造成这种情况)
				//需要将双亲节点和叔叔节点同事给成黑色且插入的节点为红色节点

				//若祖父节点不是根节点的话,上述改动方式会使这两条路径相比
				//同地位的路径多出了一个黑色节点,所以需要让这两条路径少一个黑色节点
				//方法:将祖父节点变成红色的节点
				//继续监测祖父节点的双亲节点


				//【情况二】:cur、p是红色 g是黑色 u:不存在||存在&黑色
				//u:不存在,cur 一定为新插入的节点
				//判断的依据:如果cur不是新插入的节点,那么两个红节点就连接到一起了
				//
				//u:存在&黑色 cur一定不是新插入的节点&以前一定为黑色
				//判断依据:g、u都为黑色,g右子树上有两个黑节点
				//而p、cur都为红的话,g左子树上只有一个黑节点(不满足红黑树性质)
				//所以cur必然是黑色调整过来的,此时需要调整整个红黑树了
				//cur变红的原因是其子树中插入了新的节点后调整所致
				//(若p之前是黑色的话就没必要进行调整了)
				//[解决办法]:将p改成黑色,g变成红色,(导致g的右子树中少了一个黑色节点)
				//此时需要以g为轴进行右旋 g和g的右子树移动脱离原树
				//将p的右子树接到g的左子树上,在将g所在的树整个移动到p的右子树位置
				// 



				//【情况三】:cur、p为红色&cur 为p的右子树,g和u都为黑色
				//【解决办法】:想办法将其变成情况二,以p为轴进行左单旋
				//将cur提高成p的双亲节点,让p变成cur的子树,使cur左子树为p的右子树
				//将指向cur和p的指针交换下位置
				//然后在使用情况二进行处理
				Node *grandFather = pParent->_pParent;
				//情况一:叔叔存在且为红
				if (pParent == grandFather->_pLeft){
					Node *uncle = grandFather->_pRight;
					if (uncle && uncle->_color == RED){
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						pCur = grandFather;
						pParent = pCur->_pParent;
					}
					else{
						//叔叔节点不存在或者为黑-->情况二或者情况三
						if (pCur == pParent->_pRight){
							//情况三-->将情况三装换成情况二
							RotateLeft(pParent);
							std::swap(pParent, pCur);
						}
						//处理情况二
						grandFather->_color = RED;
						pParent->_color = BLACK;
						RotateRight(grandFather);
					}
				}
				else{
					//叔叔节点在祖父节点的左侧 
					Node* uncle = grandFather->_pLeft;
					if (uncle && RED == uncle->_color){
						//叔叔存在且为红的情况
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						pCur = grandFather;
						pParent = pCur->_pParent;
					}
					else{
						if (pCur == pParent->_pLeft){
							RotateRight(pParent);
							std::swap(pParent, pCur);
						}
						pParent->_color = BLACK;
						grandFather->_color = RED;
						RotateLeft(grandFather);
					}
				}
			}
		}
		++_size;
		pRoot->_color = BLACK;//保证根节点的颜色为黑色
		//更新红黑树的最大最小节点的指向情况
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return make_pair(iterator(pNewNode),true);//插入成功
	}

	Node* LeftMost(){
		Node* pRoot = GetRoot();
		if (nullptr == pRoot){
			return _pHead;
		}
		Node* pCur = pRoot;
		while (pCur->_pLeft){
			pCur = pCur->_pLeft;
			//往左查找最左面的节点
		}
		return pCur;
	}

	Node* RightMost(){
		Node* pRoot = GetRoot();
		if (nullptr == pRoot){
			return _pHead;
		}
		Node* pCur = pRoot;
		while (pCur->_pRight){
			pCur = pCur->_pRight;
			//查找最右侧的节点
		}
		return pCur;
	}

	void RotateLeft(Node* pParent){
		//左单旋,pParent的右子树高度较高导致
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL){
			pSubRL->_pParent = pParent;
		}
		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = pPParent;
		if (pPParent == _pHead)
			GetRoot() = pSubR;
		else{
			if (pPParent->_pLeft == pParent){
				pPParent->_pLeft = pSubR;
			}
			else{
				pPParent->_pRight = pSubR;
			}
		}
	}

	void RotateRight(Node* pParent){
		//右单旋
		Node *pSubL = pParent->_pLeft;
		Node *pSubLR = pSubL->_pRight;
		pParent->_pLeft = pSubLR;
		if (pSubLR){
			pSubLR->_pParent = pParent;
		}
		pSubL->_pRight = pParent;

		//原先的pParent可能还有双亲节点,所以需要将其
		//双亲节点保存一下
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;
		//pPParent 是根节点的时候
		if (pPParent == _pHead){
			GetRoot() = pSubL;
		}
		else{
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}
	}
	//先序遍历
	void PreOrder(){
		_PreOrder(GetRoot());
	}

	//中序遍历
	void InOrder(){
		_InOrder(GetRoot());
	}

	//后序遍历
	void TailOrder(){
		_TailOrder(GetRoot());
	}

	bool IsValidRBTree(){
		Node *pRoot = GetRoot();
		if (nullptr == pRoot){
			return true;
		}
		if (pRoot->_color != BLACK){
			std::cout << "违反了性质一:根节点必须为黑色" << std::endl;
			return false;
		}
		//获取一条路径中节点的个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur){
			if (pCur->_color == BLACK)
				blackCount++;
			pCur = pCur->_pLeft;
		}
		size_t pathBlack = 0;
		return _IsValidRBTree(pRoot, blackCount, pathBlack);
	}

	bool Empty()const{
		//判断该树是否为空
		return _pHead->_pParent == nullptr;
	}
	size_t Size()const{
		return _size; //返回节点的个数
	}
private:
	Node* _pHead;
	size_t _size;//记录红黑树中有效节点的个数
	Node* &GetRoot(){
		return _pHead->_pParent;
	}
	void _PreOrder(Node *pRoot){
		if (pRoot){

			std::cout << pRoot->_data << " ";
			_PreOrder(pRoot->_pLeft);
			_PreOrder(pRoot->_pRight);
		}

	}
	void _InOrder(Node* pRoot){
		if (pRoot){

			//判断树是否存在
			_InOrder(pRoot->_pLeft);
			std::cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}

	}

	void _TailOrder(Node *pRoot){
		if (pRoot){

			_TailOrder(pRoot->_pLeft);
			_TailOrder(pRoot->_pRight);
			std::cout << pRoot->_data << " ";
		}

	}
	bool _IsValidRBTree(Node *pRoot, size_t blackCount, size_t pathBlack){
		if (nullptr == pRoot)
			return true;
		if (pRoot->_color == BLACK)
			pathBlack++;

		//性质三的监测
		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead&&pParent->_color == RED&&pRoot->_color == RED){
			std::cout << "违反了性质三:不能有连在一起的红色节点" << std::endl;
			return false;
		}
		//一条路径到了叶子节点
		if (pRoot->_pLeft == nullptr&&pRoot->_pRight == nullptr){
			if (blackCount != pathBlack){
				std::cout << "违反性质4:每条路径中黑色节点的个数必须相同:" << std::endl;
				return false;
			}
		}
		return _IsValidRBTree(pRoot->_pLeft, blackCount, pathBlack) &&
			_IsValidRBTree(pRoot->_pRight, blackCount, pathBlack);
	}
};