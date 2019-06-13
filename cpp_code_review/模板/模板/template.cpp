
#if 0
//模板函数
#include<iostream>

using namespace std;
template <typename T>

void Swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>

T Add(T a, T b){
	return a + b;
}

int main(){
	int a = 10, b = 20;
	double c = 10.0;
	//隐式实例化:让编译器根据实参推演模板参数的实际类型
	Swap(a, b);
	//交换函数
	cout << Add<int>(a, c) << endl;
	//显式实例化：在函数名后的<>中指定模板参数的实际类型
	//指定输出格式为int类型
	//只有形参不是引用类型的话,才可以使用这种方法(Add<int>())
	//但是当形参类型为引用类型的话这样使用会报错
	cout << Add(a, (int)c) << endl;
	//通过这种方式也可以达到类型转换的目的
	cout << a << endl;
	cout << b << endl;
	cout << Add(a, b) << endl;
	return 0;
}

#endif

//模板类

#include<iostream>
#include<assert.h>

using namespace std;

template <class T>

class Vector{
public:
	Vector(size_t capacity=5)
		:_data(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{
		
	}
	~Vector(){
		if (_data){
			delete[] _data;
			_data = nullptr;
			_size= 0;
			_capacity = 0;
		}
	}

	T& operator[](size_t i){
		assert(i < _size);
		return _data[i];
	}
	size_t size(){
		return _size;
	}
	void pushBack(T x){
		 _data[_size++] = x;
	}

	void pop(){
		_size--;
	}
private:
	T* _data;
	size_t _size;
	size_t _capacity;
};

// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
//template <class T>
//Vector<T>::~Vector()
//{
//	if (_pData)
//	{
//		delete[] _pData;
//	}
//}
int main(){
	Vector<int>  v1(10);
	v1.pushBack(1);
	v1.pushBack(2);
	v1.pushBack(3);
	v1.pushBack(4);
	v1.pushBack(5);
	v1.pop();
	cout << v1.size() << endl;
	for (int i = 0; i < v1.size(); i++){
		cout << v1[i] << " ";
	}
	cout << endl;
	Vector<char> v2(10);
	v2.pushBack('a');
	v2.pushBack('b');
	v2.pushBack('c');
	v2.pushBack('d');
	v2.pushBack('e');
	for (int j = 0; j < v2.size(); j++){
		cout << v2[j] << " ";
	}
	cout << endl;
	return 0;
	// Vector类名，Vector<int>才是类型
}
