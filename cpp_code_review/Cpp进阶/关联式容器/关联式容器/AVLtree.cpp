

//ƽ�����Ľ���

#include<iostream>

using namespace std;

template<class T>
struct AVLNode
{
	AVLNode(const T& val = T())
	:_data(val)
	, _pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _bf(0)
	{}
	T _data;
	AVLNode<T>* _pLeft;
	AVLNode<T>* _pRight;
	AVLNode<T>* _pParent;
	//ƽ������
	int _bf;
};

template <class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	typedef Node* pNode;

	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data > val)
			{
				cur = cur->_pLeft;
			}
			else if (cur->_data < val)
			{
				cur = cur->_pRight;
			}
			else
				return false;
		}

		pNode newNode = new Node(val);
		if (parent->_data > val)
			parent->_pLeft = newNode;
		else
			parent->_pRight = newNode;
		newNode->_pParent = parent;

		//��������֤ƽ��
		while (parent)
		{
			//���µ�ǰ�ڵ��ƽ������
			if (parent->_data > val)
				--parent->_bf;
			else
				++parent->_bf;
			//���ƽ�����ӣ�_bf ==0, �߶�û�з����仯��ֹͣ����
			if (parent->_bf == 0)
				break;
			//�߶ȼ�1�����´�·���ϵ����Ƚڵ��ƽ������
			if (parent->_bf == 1 || parent->_bf = -1)
				parent = parent->_pParent;
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//��ƽ�⣬��Ҫ����
				//����
				if (parent->_bf == 2 && parent->_pRight->_bf == 1)
				{
					RotateL(parent);
				}
				else if (.....)

					//��ת�������Ѿ�ƽ�⣬��������
					break;
			}

		}

	}

	void RotateL(pNode parent)
	{
		pNode subR = parent->_pRight;
		pNode subRL = subR->_pLeft;
		//��ת
		subR->_pLeft = parent;
		parent->_pRight = subRL;

		//����������
		//����subRL ��parent
		if (subRL)
			subRL->_pParent = parent;

		//����subR �� parent->_pParent
		if (parent != _root)
		{
			pNode gParent = parent->_pParent;
			//�ж�parent֮ǰ��parent->_pParent����һ�ߵĽڵ�
			//��subR���ӵ���Ӧ�ı�
			if (gParent->_pLeft = parent)
				gParent->_pLeft = subR;
			else
				gParent->_pRight = subR;
			//����subR��pParent
			subR->_pParent = gParent;
		}
		else
		{
			//���parent�Ǹ���subR����µĸ�
			subR->_pParent = nullptr;
			_root = subR;
		}

		//����subR �� parent
		parent->_pParent = subR;

		//����ƽ������
		subR->_bf = parent->_bf = 0;
	}

private:
	pNode _root = nullptr;
};
int main(){

	return 0;
}