
#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
#include<string>
#include<assert.h>

using namespace std;
class String{
	friend ostream& operator<<(ostream &_cout, const String &s);
	
public:
	typedef char*  iterator;
	typedef const char* const_iterator;
	//建议不使用初始化列表
	String(char *str="")
		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size+1])
	{
		strcpy(_str, str); //会拷贝'\0'
	}

	
	//析构函数
	~String()
	{
		if (_str){

			delete[] _str;//释放堆上面的空间
			_str = nullptr;
		}
	}

	//首先检查capacity够不够，如果容量已满则扩容
	void pushBack(const char c){
		if (_size == _capacity){
			size_t newc = (_capacity == 0?15:_capacity*2);
			Reserve(newc);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}
	//增容:只增容，不减少容量，不改变size
	void Reserve(size_t n){
		if (n > _capacity){
			//增容
			char *tmp = new char[n + 1];
			//拷贝this指针指向的有效内容
			strcpy(tmp, _str);
			delete[] _str;//释放原有空间
			_str = tmp; //指向原有空间
			//更新容量值
			_capacity = n;
		}
	}

	iterator begin(){
		return _str;
		//返回第一个元素的位置(地址)
	}
	iterator end(){
		//返回最后一个元素的下一个位置
		return _str + _size;
	}

	const_iterator begin()const{
		return _str;
		//返回第一个元素的位置(地址)
	}
	const_iterator end()const{
		//返回最后一个元素的下一个位置
		return _str + _size;
	}


	//可读可写接口
	char& operator[](size_t pos)
	{
		//防止访问越界
		assert(pos<_size);
		return _str[pos];
	}

	//只读接口,不允许被修改，返回const 引用
	const char& operator[](size_t pos) const 
	{
		//防止访问越界
		assert(pos<_size);
		return _str[pos];
	}
	//尾删
	void popBack(){
		assert(_size > 0);//确保含有一个有效字符
		_str[--_size ] = '\0';
	}

	//【拷贝构造】:传统写法
	/*String(const String& s)
		:_str(new char[strlen(s._str)+1])
		{
		strcpy(_str, s._str);
		}*/
	//现代写法
	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
		//Swap(this,tmp);
	}

	void Swap( String& tmp){
		//传引用的目的避免传值时调用拷贝构造
		//从而引发无限递归
		swap(_str, tmp._str);
		swap(_size, tmp._size);
		swap(_capacity, tmp._capacity);
	}
	//非const对象和const对象都可以调用const成员函数
	size_t Size()const{
		return _size;
	}
	

	//【赋值运算符重载】[传统写法]
	/*String &operator=(const String&s){
		if (this != &s){
		delete[] _str;
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
		}
		return *this;
		}
		*/
	//[现代写法]
	//目的在于交换两个指针指向的空间
	String& operator=(String s){
		Swap(s);//Swap(this,s);
		return *this;
	}
	char *c_str(){
		return _str;
	}
private:
	char* _str;
	size_t _size; //有效字符串,不含'\0' 
	size_t _capacity;
	//容量:实际能存放的最大字符数，不含'\0'比实际申请的
	//空间小一个字节
};
ostream& operator<<(ostream &_cout, const String &s){
	_cout << s._str;
	return _cout;
}

void PrintString(const String&s){
	for (int i = 0; i < s.Size(); i++){
		cout << s[i] << " ";
	}
	cout << endl;
}

//基于范围的for循环,依赖于迭代器
void PrintStringFor(const String&s){
	for (auto &e:s){
		cout <<e << " ";
	}
	cout << endl;
}


//迭代器 的方式遍历
void PrintStringIterator(const String&s){
	String::const_iterator sit = s.begin();
	while (sit != s.end()){
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
}

int main(){
	String s("hello world!");
	s.pushBack('a');
	s.pushBack('a');
	s.pushBack('a'); 
	PrintString(s);
	s.popBack(); 
	s.popBack();
	PrintString(s);
	s.popBack();
	return 0;
}
#endif