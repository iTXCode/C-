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

	//����ָ�����
	T& operator*(){
		return _pNode->_data;
	}

	T& operator->(){
		return &(operator*());
		//һ�㲻ֱ��ȡ,ͨ�������õķ�ʽ��ȡ��ַ
	}

	//�����������ƶ�
	//ǰ��++
	Self& operator++(){
		Increament();
		return *this;
	}
	//����++
	Self operator++(int){
		Self temp(*this);
		Increament();
		return temp;
	}

	//ǰ��--
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
			//��_pNode���Ԫ�ؿ�������˫����
			Node* pParent = _pNode->_pParent;
			while (_pNode == pParent->_pRight){
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			//���ڵ�û��������,���ҵ����������ڸ��ڵ��λ��
			if (_pNode->_pRight!=pParent)
			_pNode = pParent;
		}
	}

	void DeIncreament(){
		//end--�ܹ��ߵ����ڵ��λ��

		if (_pNode->_pParent->_pParent == _pNode&& RED==_pNode->_color){
			_pNode = _pNode->_pRight;
		}
		else if (_pNode->_pLeft){
			//�������������,���������������Ľڵ�
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight){
				_pNode = _pNode->_pRight;
			}
		}
		else{
			//������������������,�ʹӸýڵ㿪ʼ������
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
	//������ʹ�õĽӿ�ʵ��
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
			return end();//û�ҵ�
		}
	}
public:
	RBTree()
		:_size(0)
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
		//ֻ��һ���ڵ��ʱ��,�ýڵ��ͷ���
		//��������ϵ,������������������
	}

	pair<iterator,bool> Insert(const T&data){
		//�����жϺ�����Ƿ�Ϊ��,�ж�ͷ����˫��ָ�����Ƿ�Ϊ��
		//��Ϊ��,����Ϊ����
		Node*& pRoot = GetRoot();
		Node* pNewNode = nullptr;
		if(nullptr == pRoot){
			//����ֻ��ͷ���,û�и��ڵ�����
			//�����Ĵ���ʽ
			pNewNode =pRoot= new Node(data,BLACK);
			pRoot->_pParent = _pHead;
			
		}
		else{
			//1.���ն��������������ʣ�
			//�ҵ�������ڵ��ٺ�����е�λ��
			Node* pCur = pRoot;
			Node* pParent = nullptr;
			while (pCur){
				pParent = pCur;
				if (KOFV()(data)<KOFV()(pCur->_data))
					//KOFV()()�º�����ʹ�÷�ʽ
					pCur = pCur->_pLeft;
				else if (KOFV()(data)>KOFV()(pCur->_data))
					pCur = pCur->_pRight;
				else
					return make_pair(iterator(pCur),false);
				//�������������ڽڵ�������ͬ�����
			}
			//�����µĽڵ�,��ָ����ɫ��Ϊ��ɫ
			pNewNode = pCur = new Node(data);
			if (KOFV()(data )< KOFV()(pParent->_data))
				pParent->_pLeft = pCur;
			else
				pParent->_pRight = pCur;
			pCur->_pParent = pParent;//���²���ڵ��˫�׽ڵ�

			//���:�½ڵ�����,�Ƿ�������һ��ĺ�ɫ�ڵ�
			while (pParent != _pHead && RED == pParent->_color){
				//�����һ��:Ҫ����λ�õĸ��׽ڵ�Ϊ��ɫ
				//�游Ϊ���ڵ�����,
				//����Ľڵ���Ϊ��ɫ,��·���ϾͶ���һ����ɫ�ڵ�
				//(ֻ��˫�׽ڵ���ɺ�ɫҲ������������)
				//��Ҫ��˫�׽ڵ������ڵ�ͬ�¸��ɺ�ɫ�Ҳ���Ľڵ�Ϊ��ɫ�ڵ�

				//���游�ڵ㲻�Ǹ��ڵ�Ļ�,�����Ķ���ʽ��ʹ������·�����
				//ͬ��λ��·�������һ����ɫ�ڵ�,������Ҫ��������·����һ����ɫ�ڵ�
				//����:���游�ڵ��ɺ�ɫ�Ľڵ�
				//��������游�ڵ��˫�׽ڵ�


				//���������:cur��p�Ǻ�ɫ g�Ǻ�ɫ u:������||����&��ɫ
				//u:������,cur һ��Ϊ�²���Ľڵ�
				//�жϵ�����:���cur�����²���Ľڵ�,��ô������ڵ�����ӵ�һ����
				//
				//u:����&��ɫ curһ�������²���Ľڵ�&��ǰһ��Ϊ��ɫ
				//�ж�����:g��u��Ϊ��ɫ,g���������������ڽڵ�
				//��p��cur��Ϊ��Ļ�,g��������ֻ��һ���ڽڵ�(��������������)
				//����cur��Ȼ�Ǻ�ɫ����������,��ʱ��Ҫ���������������
				//cur����ԭ�����������в������µĽڵ���������
				//(��p֮ǰ�Ǻ�ɫ�Ļ���û��Ҫ���е�����)
				//[����취]:��p�ĳɺ�ɫ,g��ɺ�ɫ,(����g��������������һ����ɫ�ڵ�)
				//��ʱ��Ҫ��gΪ��������� g��g���������ƶ�����ԭ��
				//��p���������ӵ�g����������,�ڽ�g���ڵ��������ƶ���p��������λ��
				// 



				//���������:cur��pΪ��ɫ&cur Ϊp��������,g��u��Ϊ��ɫ
				//������취��:��취�����������,��pΪ���������
				//��cur��߳�p��˫�׽ڵ�,��p���cur������,ʹcur������Ϊp��������
				//��ָ��cur��p��ָ�뽻����λ��
				//Ȼ����ʹ����������д���
				Node *grandFather = pParent->_pParent;
				//���һ:���������Ϊ��
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
						//����ڵ㲻���ڻ���Ϊ��-->��������������
						if (pCur == pParent->_pRight){
							//�����-->�������װ���������
							RotateLeft(pParent);
							std::swap(pParent, pCur);
						}
						//���������
						grandFather->_color = RED;
						pParent->_color = BLACK;
						RotateRight(grandFather);
					}
				}
				else{
					//����ڵ����游�ڵ����� 
					Node* uncle = grandFather->_pLeft;
					if (uncle && RED == uncle->_color){
						//���������Ϊ������
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
		pRoot->_color = BLACK;//��֤���ڵ����ɫΪ��ɫ
		//���º�����������С�ڵ��ָ�����
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return make_pair(iterator(pNewNode),true);//����ɹ�
	}

	Node* LeftMost(){
		Node* pRoot = GetRoot();
		if (nullptr == pRoot){
			return _pHead;
		}
		Node* pCur = pRoot;
		while (pCur->_pLeft){
			pCur = pCur->_pLeft;
			//�������������Ľڵ�
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
			//�������Ҳ�Ľڵ�
		}
		return pCur;
	}

	void RotateLeft(Node* pParent){
		//����,pParent���������߶Ƚϸߵ���
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
		//�ҵ���
		Node *pSubL = pParent->_pLeft;
		Node *pSubLR = pSubL->_pRight;
		pParent->_pLeft = pSubLR;
		if (pSubLR){
			pSubLR->_pParent = pParent;
		}
		pSubL->_pRight = pParent;

		//ԭ�ȵ�pParent���ܻ���˫�׽ڵ�,������Ҫ����
		//˫�׽ڵ㱣��һ��
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;
		//pPParent �Ǹ��ڵ��ʱ��
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
	//�������
	void PreOrder(){
		_PreOrder(GetRoot());
	}

	//�������
	void InOrder(){
		_InOrder(GetRoot());
	}

	//�������
	void TailOrder(){
		_TailOrder(GetRoot());
	}

	bool IsValidRBTree(){
		Node *pRoot = GetRoot();
		if (nullptr == pRoot){
			return true;
		}
		if (pRoot->_color != BLACK){
			std::cout << "Υ��������һ:���ڵ����Ϊ��ɫ" << std::endl;
			return false;
		}
		//��ȡһ��·���нڵ�ĸ���
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
		//�жϸ����Ƿ�Ϊ��
		return _pHead->_pParent == nullptr;
	}
	size_t Size()const{
		return _size; //���ؽڵ�ĸ���
	}
private:
	Node* _pHead;
	size_t _size;//��¼���������Ч�ڵ�ĸ���
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

			//�ж����Ƿ����
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

		//�������ļ��
		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead&&pParent->_color == RED&&pRoot->_color == RED){
			std::cout << "Υ����������:����������һ��ĺ�ɫ�ڵ�" << std::endl;
			return false;
		}
		//һ��·������Ҷ�ӽڵ�
		if (pRoot->_pLeft == nullptr&&pRoot->_pRight == nullptr){
			if (blackCount != pathBlack){
				std::cout << "Υ������4:ÿ��·���к�ɫ�ڵ�ĸ���������ͬ:" << std::endl;
				return false;
			}
		}
		return _IsValidRBTree(pRoot->_pLeft, blackCount, pathBlack) &&
			_IsValidRBTree(pRoot->_pRight, blackCount, pathBlack);
	}
};