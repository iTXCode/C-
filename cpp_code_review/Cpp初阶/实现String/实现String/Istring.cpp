
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
#include<string.h>
using namespace std;

const char* Strstr(const char*s1, const char*s2);
class String{
	friend ostream &operator<<(ostream &_cout, const String& s);
	friend String operator+(const String& s1, const String& s2);
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	String(const char *str="")
		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size+1])
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
		:_str(nullptr)    
		,_size(s._size)
		, _capacity(s._capacity)
		
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
	size_t Size()const{
		return _size;
	}

	void PushBack(const char c){
		/*if (_size == _capacity){
			size_t newcapacity = (_capacity == 0) ? 15 : _capacity*2;
			Reverse(newcapacity);
			}
			_str[_size++] = c;
			_str[_size] = '\0';*/
		
		//调用insert函数达到尾插的目的
		insert(_size,c);
	}

	void PopBack(){
		assert(_size > 0);
		_str[--_size] = '\0';
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


	//尾插
	void Append(const char*str){
		size_t sz = strlen(str);
		if (_size + sz > _capacity){
			Reverse(_size + sz);
		}
		strcpy(_str+_size,str);
		_size += sz;
	}

	
	//交换函数
	void Swap(String &tmp){
		swap(_str,tmp._str);
		swap(_size,tmp._size);
		swap(_capacity,tmp._capacity);
	}
	

	//可读可写的接口
	char &operator[](size_t pos){
		assert(_size>pos);//防止访问有效值之外的内容
		return _str[pos];
	}

	//只读的接口

	const char& operator[](size_t pos) const{
		assert(_size>pos);
		return _str[pos];
	}

	//迭代器的相关操作
	iterator begin(){
		return _str;
	}
	iterator end(){
		return _str + _size;
	}

	//const迭代器的使用
	const_iterator begin()const{
		return _str;
	}

	const_iterator end()const{
		return _str + _size;
	}

	//insert(插入字符)
	//1.检查空间是否已满(_size与_capacity是否相等),如果已满则需要增容
	//2.比较插入位置的下标与有效字符个数的大小关系
	//3.若pos<_size，则将pos位置开始的元素往后移动
	//4.更新_size,_size++,更新'\0'位置_str[_size]='\0';
	//对于第二步,数据挪动方向为从后往前依次挪动，否则或造成数据覆盖
	void insert(size_t pos,const char c){
		assert(pos<=_size);
	//检查是否需要扩容
		if (_size == _capacity){
			size_t newc = (_capacity == 0) ? 15 : (_capacity * 2);
			Reverse(newc);
		}
		size_t end = _size;
		//为了数据的安全,最好不拿_size来直接当作挪动的位置
		//检查插入的元素位置是否小于有效字符个数
		while(end > pos){
			//需要往后移动元素
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = c;
		_str[++_size] = '\0';
	}

	//插入字符串的情况
	//1.检查空间是否足够
	//2.从pos位置开始的数据依次向后挪动len个位置
	//3.从pos开始拷贝s
	//4.更新_size
	void insert(size_t pos,const char* s){
		assert(pos <= _size);
		//检查是否需要扩容
		size_t len = strlen(s);
		if (_size+ len > _capacity){
			Reverse(_size+len);
		}
		 //开始挪动数据
		size_t end = _size + len;
		while ((pos+len-1) < end){
			//第一个挪动的为'\0'
			_str[end] = _str[end-len];
			end--;
		}

		//从pos位置开始拷贝s
		for (int i = 0; i < len;i++){
			_str[i + pos] = s[i];
		}
		_size += len;
	}

	//从某个合法的位置删除n个元素
	//1.pos+len>_size,
	//相当于从pos位置开始的字符都要被删除,更新_size=pos,_str[size]='\0';
	//2.pos+len<=_size,
	//从pos+len位置开始向前移动len个位置,从后向前挪动;
	//3.更新_size-=len;
	void Erase(size_t pos,size_t len){
		assert(pos<_size);
		//从pos开始向后的字符全部删除
		if (pos + len>_size){
			_size = pos;
			_str[_size] = '\0';
		}
		else{
			size_t start = pos + len;
			//从后向前挪动len个位置
			while (start<_size){
				_str[pos++] = _str[start];
				start++;
			}
			_size -= len;
			_str[_size] = '\0';
		}
	}


	//两个字符串相加
	//s1+=s2 -->改变s1
	//s1.operator+=(&s1,s2) -->Append(&s1,s2._str)
	String&operator+=(const String &s){
		Append(s._str);
		return *this;  
	}
	//尾插一个字符
	String&operator+=(const char c) {
		PushBack(c);
		return *this;
	}
	//
	String& operator+=(const char *str){
		Append(str);
		return *this;
	}
	//找一个字符
	//找到的话返回其位置
	//找不到的话返回npos
	size_t find(const char c){
		for (int i = 0; i < _size; i++){
			if (_str[i] == c){
				return i;
			}
		}
		return npos;
	}


	//找一个字串，
	//找到的话，返回字串的起始位置
	//找不到返回npos
	size_t find(size_t pos, const char *str){
		assert(pos < _size);
		const char *start = Strstr(_str, str);
		if (start)
			return start - _str;
		else
			return npos;
	}

	
 
private:
	size_t _size;
	size_t _capacity;
	char* _str;
	static const size_t npos;
};




const char* Strstr(const char*s1, const char*s2){
	while (*s1){
		//首先判断第一个字符是否相等
		if (*s1 == *s2){
			const char *ptr1 = s1;
			const char *ptr2 = s2;
			//判断s2中的每一个元素
			while (*ptr1&&*ptr2){
				if (*ptr1 != *ptr2)
					break;
				ptr1++;
				ptr2++;
			}
			if (*ptr2 == '\0')
				return s1;
		}
		s1++;
	}
	return nullptr;
}

//两个String类对象相加
String operator+(const String& s1, const String& s2){
	String s3(s1);
	s3 += s2;
	return s3;
}
//String对象+一个字符串
String operator+(const String& s1, const char* s2){
	String s3(s1);
	s3 += s2;
	return s3;
}
//一个字符串 + 一个String对象
String operator+(const char* s1, const String& s2){
	String s3(s1);
	s3 += s2;
	return s3;
}

const size_t String::npos = -1;
//无符号类型的最大值


ostream &operator<<(ostream &_cout, const String& s){
	_cout << s._str;
	return _cout;
}

void testString(){
	String s("hello bit!");
	cout << s.Size() << endl;
	cout << s << endl;
	s.PushBack('!');
	s.PushBack('!');
	s.PushBack('!');
	s.PushBack('!');
	s.PushBack('!');
	s.PopBack();
	s[1] = 'f';
	cout << "s[0]:" << s[0] << endl;
	cout << s << endl;
	cout << s.Size() << endl;
	String s1 = s;
	//两者对比
	cout << s1.Size() << endl;
	String s2 = "hello world";

	cout << s2 << endl;
	cout << s2.Size() << endl;
}


//迭代器测试
//迭代器实质为"指针"
void testString1(){
	String s = "today";
	String::iterator sit = s.begin();
	while (sit != s.end()){
		cout << *sit ;
		sit++;
	}
	cout << endl;
}
//插入检测
void testInsert(){
	String s = "hello love";
	//头插
	s.insert(0, '\"');//转义符号的使用
	//中间插
	s.insert(6, ' ');

	//尾插
	s.insert(s.Size(), '\"');
	cout << s << endl;
	s.insert(s.Size()-2, ' ');
	cout << s << endl;
	//插入字符串
	s.insert(s.Size()-2, "world");
	cout << s << endl;
	cout << s.Size() << endl;
}

void testErase(){
	String s("I love you!");
	cout << s << endl;
	s.Erase(2, 5);
	cout << s << endl;
	s.Append("love");
	cout << s << endl;
}


//测试+=
void testString2(){
	String s;
	s += 'I';
	s += " love";
	cout << s<< endl;
	String s2(" you!");
	s += s2;
	cout << s << endl;
}


//测试查找
void testFind(){
	String s("I love you!");
	cout<<s.find('i')<<endl;
	cout << s.find('y') << endl;
	cout<<s.find(0,"love")<<endl;

}
int main(){
	//testString();
	//testString1();
	//testInsert();
	testErase();
	testString2();
	testFind();
	return 0;
}