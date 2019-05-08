//#include<iostream>
//#include<windows.h>
//#include<deque>
//using namespace std;
//
//template <class T,class container = deque<T>>
//
//class Queue{
//public:
//	void Push(const T& x){
//		_con.push_back(x);
//	}
//	void Pop(){
//		_con.pop_front();
//	}
//	T& Front(){
//		return _con.front();
//	}
//	size_t size(){
//		return _con.size();
//	}
//	bool Empty(){
//		return _con.empty();
//	}
//	T& Back(){
//		return _con.back();
//	}
//private:
//	container _con;
//};
//
//
//int main(){
//	Queue<int> q;
//	q.Push(1);
//	q.Push(2);
//	q.Push(3);
//	q.Push(4);
//	q.Push(5);
//	while (!q.Empty()){
//		cout << q.Front() << " ";
//		q.Pop();
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<windows.h>
#include<deque>
using namespace std;

template <class T, class container = deque<T>>

class Queue{
public:
	void Push(const T& x){
		_con.push_back(x);
	}
	void Pop(){
		_con.pop_front();
	}
	T& Front(){
		return _con.front();
	}
	size_t size(){
		return _con.size();
	}
	bool Empty(){
		return _con.empty();
	}
	T& Back(){
		return _con.back();
	}
private:
	container _con;
};


int main(){
	
}