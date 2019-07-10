#include <iostream>

//双端队列
using namespace std;

//迭代器的实现
//为了实现迭代器的模板话(普通迭代器和const迭代器的代码复用)
//一般使用三个参数的方法来实现该功能
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
	T* frist; //指向缓冲区的第一个位置
	T* last;  //指向缓冲区的最后一个位置
	T* cur;   //此迭代器所指的 缓冲区中的现行元素，用于"遍历"缓冲区
	T** node;//指向中控的指针
};

//++node后的更新
//first=*node;
//cur=first;
//last=first+缓冲区的长度

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