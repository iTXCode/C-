#if 0
//模板

#include<iostream>

using namespace std;

template <typename T>

void Swap(T &a, T &b){
	T temp = a;
	a = b;
	b=temp;
}

template <typename T>
T Add(T a, T b){
	return a + b;
}

int main(){
	int a = 1, b = 2;
	double c = 1.2, d = 2.3;
	Swap(a, b);
	Swap(c, d);
	//Swap(a, c);
	//编译出错,编译时参数的类型不明确。
	//两个参数的类型必须一致，不一致编不过
	
	//显示实例化
	//Swap<int>(a,c);//不可行，因为传参时形参是引用
	Add<int>(a, c);
	Add(a, (int)c);//这样也可以
	return 0;
}

#endif


#include<iostream>
#include<assert.h>
//类模板
using namespace std;
 
template<class T>
//typedef int DataType;
//typedef char DataType;

class  Vector{
public:

	//构造函数和类名相同 
	Vector(size_t capacity=5)
		:_data(new T[capacity])
		, _size(0)
		, _capacity(capacity){

	}
	~Vector(){
		if (_data){
			delete[] _data;
			_data = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}
	T &operator[](size_t i){
		assert(i < _size);
		return _data[i];
	}
	size_t size(){
		return _size;
	}

	void pushBack(T x){
		_data[_size++] = x;
	}
private:
	T *_data;
	size_t _size;
	size_t _capacity;
};

int main(){
	//类模板
	//类型和类名不同
	//类型：类名<T>
	//类模板必须显示实例化
	Vector <int> v1(5);
	v1.pushBack(1);
	v1.pushBack(2);
	v1.pushBack(3);
	v1.pushBack(4);
	for (int i = 0; i < 4; i++){
		cout << v1[i]<<" " ;
	}
	cout <<  endl;
	Vector <char>v2(5);
	v2.pushBack('a');
	v2.pushBack('b');
	v2.pushBack('c');
	v2.pushBack('d');
	for (int i = 0; i < 4; i++){
		cout << v2[i] << " ";
		//v2[i]+10 输出的是整形数字,既对应字母的ASCII对应的数字
	}
	cout << endl;
	return 0;
}



