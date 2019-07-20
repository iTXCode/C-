
#if 0
//ģ�庯��
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
	//��ʽʵ����:�ñ���������ʵ������ģ�������ʵ������
	Swap(a, b);
	//��������
	cout << Add<int>(a, c) << endl;
	//��ʽʵ�������ں��������<>��ָ��ģ�������ʵ������
	//ָ�������ʽΪint����
	//ֻ���ββ����������͵Ļ�,�ſ���ʹ�����ַ���(Add<int>())
	//���ǵ��β�����Ϊ�������͵Ļ�����ʹ�ûᱨ��
	cout << Add(a, (int)c) << endl;
	//ͨ�����ַ�ʽҲ���Դﵽ����ת����Ŀ��
	cout << a << endl;
	cout << b << endl;
	cout << Add(a, b) << endl;
	return 0;
}

#endif

//ģ����

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

// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
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
	// Vector������Vector<int>��������
}
