
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class String{
	friend ostream &operator<<(ostream &_cout, const String& s);
public:
	String(char *str="")
		:_size(strlen(str))
		, _capacity(_size*2)
		, _str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}
	~String(){
		if (_str){
			delete[] _str;
			_str = nullptr;
		}
	}

	String(const String& s)
	{
		String tmp(s._str);
		swap(_str,tmp._str);
	}
	String &operator=(const String& s){
		String tmp(s);
		swap(_str, tmp._str);
		return *this;
	}

	char* c_str(){
		return _str;
	}
	size_t Size(){
		return _size;
	}

	void PushBack(const char c){
		if (_size == _capacity){
			size_t newcapacity = (_capacity == 0) ? 15 : 2 * _capacity;
			Reverse(newcapacity);
		}
		_str[++_size] = c;
		_str[_size] = '\0';
	}

	//增容的逻辑
	void Reverse(size_t newsize){
		if (newsize > _capacity){
			char* tmp = new char[newsize + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = newsize;
		}
	}

private:
	size_t _size;
	size_t _capacity;
	char* _str;
};


ostream &operator<<(ostream &_cout, const String& s){
	_cout << s._str;
	return _cout;
}

void testString(){
	
}
int main(){
	//testString();
	String s("hello bit!");
	cout << s.Size() << endl;
	String s1 = s;
	//两者对比
	cout << s1.Size() << endl;
	
	return 0;
}