#include <iostream>

//˫�˶���
using namespace std;

//��������ʵ��
//Ϊ��ʵ�ֵ�������ģ�廰(��ͨ��������const�������Ĵ��븴��)
//һ��ʹ�����������ķ�����ʵ�ָù���
template<class T,class Ref,class Ptr>
class DequeIterator{
public:
	typedef DequeIterator<T, Ref, Ptr> self;
	Ref oparetor*(){
		return *cur;
	}
	self& operator++(){
		cur++;
		if (cur == last){
			node++;
			first = *node;
			last = first + bufferLen;
			cur = first;
		}
		return *this;
	}
private:
	T* frist; //ָ�򻺳����ĵ�һ��λ��
	T* last;  //ָ�򻺳��������һ��λ��
	T* cur;   //�˵�������ָ�� �������е�����Ԫ�أ�����"����"������
	T** node;//ָ���пص�ָ��
};

//++node��ĸ���
//first=*node;
//cur=first;
//last=first+�������ĳ���

template <class T>

class Deque{
public:
	iterator begin(){
		return _start;
	}

	iterator end(){
		return _finish;
	}
private:
	iterator _start;
	iterator _finish;
	T** _map;
};
int main(){

	return 0;
}