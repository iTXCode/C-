
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>
#include<assert.h>

using namespace  std;
const char* Strstr(const  char*s1, const char* s2);
class String{
	friend ostream& operator<<(ostream& _cout,const String &s);
public:
	typedef char*  iterator;
	typedef const char* const_iterator;
	String(char *str="")
		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size+1])
	{
		strcpy(_str,str);
	}
	~String(){
		if (_str){
			delete[] _str;
			_str = nullptr;
		}
	}
	String(const String&s)
		:_size(s._size)
		, _capacity(s._capacity)
		, _str(nullptr)
	{
		String tmp(s._str);
		swap(_str,tmp._str);
	}
	String &operator=(const String&s){
		String tmp(s);
		swap(_str,tmp._str);
		return *this;
	}
	char* c_str(){
		return _str;
	}
	size_t Size()const{
		return _size;
	}

	void PushBack(const char c){
		//����Ƿ���Ҫ����
		if (_size == _capacity){
			size_t newc = (_capacity == 0) ? 15 : (_capacity * 2);
			Reverse(newc);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}

	//���ݵ��߼�
	void Reverse(size_t n){
		if (n > _capacity){
			char* tmp = new char[n + 1];
			strcpy(tmp,_str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	//βɾ
	void PopBack(){
		assert(_size>0);
		_str[--_size] = '\0';
	}
	//β��
	void Append(const char*str){
		size_t sz = strlen(str);
		if (_size+sz> _capacity){
			Reverse(_size+sz);
		}
		strcpy(_str+sz,_str);
		_size += sz;
	}


	//��������
	void Swap(String &tmp){
		swap(_size,tmp._size);
		swap(_capacity, tmp._capacity);
		swap(_str, tmp._str);
	}


	//�ɶ���д�Ľӿ�
	char &operator[](size_t pos){
		assert(_size>pos);
		return _str[pos];
	}

	//ֻ���Ľӿ�

	const char& operator[](size_t pos) const{
		assert(_size > pos);
		return _str[pos];
	}

	//����������ز���
	iterator begin(){
		return _str;
	}
	iterator end(){
		return _str + _size;
	}

	//const��������ʹ��
	const_iterator begin()const{
		return _str;
	}

	const_iterator end()const{
		return _str + _size;
	}

	//insert(�����ַ�)
	//1.���ռ��Ƿ�����(_size��_capacity�Ƿ����),�����������Ҫ����
	//2.�Ƚϲ���λ�õ��±�����Ч�ַ������Ĵ�С��ϵ
	//3.��pos<_size����posλ�ÿ�ʼ��Ԫ�������ƶ�
	//4.����_size,_size++,����'\0'λ��_str[_size]='\0';
	//���ڵڶ���,����Ų������Ϊ�Ӻ���ǰ����Ų���������������ݸ���
	void insert(size_t pos, const char c){
		 assert(_size>=pos);
		if (_size == _capacity){
			size_t newc = (_capacity == 0) ? 15 : (_capacity * 2);
			Reverse(newc);
		}
		size_t end = _size;
		while (end > _size){
			_str[end] = _str[end-1];
			end--;
		}
		_str[pos] = c;
		_str[++_size] = '\0';
	}

	//�����ַ��������
	//1.���ռ��Ƿ��㹻
	//2.��posλ�ÿ�ʼ�������������Ų��len��λ��
	//3.��pos��ʼ����s
	//4.����_size
	void insert(size_t pos, const char* s){
		assert(pos<=_size);
		size_t len = strlen(s);
		if (_size + len > _capacity){
			Reverse(_size + len);
		}
		size_t end = _size+len;
		while ((pos+len-1)<end){
			_str[end] = _str[end-len];
			end--;
		}
		for(int i=0;i<len;i++){
			_str[pos+i] = s[i];
		}
		_size += len;
	}

	//��ĳ���Ϸ���λ��ɾ��n��Ԫ��
	//1.pos+len>_size,
	//�൱�ڴ�posλ�ÿ�ʼ���ַ���Ҫ��ɾ��,����_size=pos,_str[size]='\0';
	//2.pos+len<=_size,
	//��pos+lenλ�ÿ�ʼ��ǰ�ƶ�len��λ��,�Ӻ���ǰŲ��;
	//3.����_size-=len;
	void Erase(size_t pos, size_t len){
		if (pos + len > _size){
			_size = pos;
			_str[_size] = '\0';
		}
		else{
			size_t start = pos + len;
			//�Ӻ���ǰŲ��len��λ��
			while (start < _size){
				_str[pos++] = _str[start];
				start++;
			}
			_size -= len;
			_str[_size] = '\0';
		}
	}


	//�����ַ������
	//s1+=s2 -->�ı�s1
	//s1.operator+=(&s1,s2) -->Append(&s1,s2._str)
	String&operator+=(const String &s){
		Append(s._str);
		return *this;
	}
	//β��һ���ַ�
	String&operator+=(const char c){
		PushBack(c);
		return  *this;
	}
	//β��һ���ַ���
	String& operator+=(const char *str){
		Append(str);
		return *this;
	}
	//��һ���ַ�
	//�ҵ��Ļ�������λ��
	//�Ҳ����Ļ�����npos
	size_t find(const char c){
		for (int i = 0; i < _size; i++){
			if (_str[i] == c)
				return i;
		}
		return npos;
	}


	//��һ���ִ���
	//�ҵ��Ļ��������ִ�����ʼλ��
	//�Ҳ�������npos
	size_t find(size_t pos, const char *str){
		assert(pos < _size);
		const char* start = Strstr(_str,str);
		if (start)
			return start - _str;
		else
			return npos;
	}


private:
	size_t _size;
	size_t _capacity;
	char * _str;

	static const size_t npos;
};

const size_t  String::npos = -1;

//����String��������
String operator+(const String& s1, const String& s2){
	String s3(s1);
	s3 += s2;
	return s3;
}
//String����+һ���ַ���
String operator+(const String& s1, const char* s2){
	String s3(s1);
	s3 += s2;
	return s3;
}
//һ���ַ��� + һ��String����
String operator+(const char* s1, const String& s2){
	String s3(s1);
	s3 += s2;
	return s3;
}

ostream &operator<<(ostream& _cout,const String &s){
	_cout << s._str;
	return _cout;
}
const char* Strstr(const  char*s1,const char* s2){
	while (*s1){
		if (*s1 == *s2){
			const char* str = s1;
			const char* ret = s2;
			while (*str&&*ret){
				if (*str != *ret)
					break;
				str++;
				ret++;
				
			}
			if (*ret == '\0')
				return s1;
		}
		s1++;
	}
	return nullptr;
}


void testInsert(){
	String s = "I am a student!";
	cout << s << endl;
	s.insert(s.Size(), '!');
	cout << s << endl;
	s.insert(s.Size(), "You too!");
	cout << s << endl;
	s.insert(7,"good ");
	cout << s << endl;
}
void testString(){
	String s = "hello world!";
	cout << s << endl;
	s.PushBack('!');
	cout << s << endl;
	String s1 = s;
	cout << s1 << endl;
}

void testFind(){
	String s = "hello my love";
	cout << s<<endl;
	cout<<s.find('o')<<endl;
	cout << s.find(1,"love") << endl;
}
int main(){
	testString();
	testInsert();
	testFind();
	return 0;
}