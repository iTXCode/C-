
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
		
		//����insert�����ﵽβ���Ŀ��
		insert(_size,c);
	}

	void PopBack(){
		assert(_size > 0);
		_str[--_size] = '\0';
	}

	//���ݵ��߼�
	void Reverse(size_t newsize){
		if (newsize > _capacity){
			char* tmp = new char[newsize + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = newsize;
		}
	}


	//β��
	void Append(const char*str){
		size_t sz = strlen(str);
		if (_size + sz > _capacity){
			Reverse(_size + sz);
		}
		strcpy(_str+_size,str);
		_size += sz;
	}

	
	//��������
	void Swap(String &tmp){
		swap(_str,tmp._str);
		swap(_size,tmp._size);
		swap(_capacity,tmp._capacity);
	}
	

	//�ɶ���д�Ľӿ�
	char &operator[](size_t pos){
		assert(_size>pos);//��ֹ������Чֵ֮�������
		return _str[pos];
	}

	//ֻ���Ľӿ�

	const char& operator[](size_t pos) const{
		assert(_size>pos);
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
	void insert(size_t pos,const char c){
		assert(pos<=_size);
	//����Ƿ���Ҫ����
		if (_size == _capacity){
			size_t newc = (_capacity == 0) ? 15 : (_capacity * 2);
			Reverse(newc);
		}
		size_t end = _size;
		//Ϊ�����ݵİ�ȫ,��ò���_size��ֱ�ӵ���Ų����λ��
		//�������Ԫ��λ���Ƿ�С����Ч�ַ�����
		while(end > pos){
			//��Ҫ�����ƶ�Ԫ��
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = c;
		_str[++_size] = '\0';
	}

	//�����ַ��������
	//1.���ռ��Ƿ��㹻
	//2.��posλ�ÿ�ʼ�������������Ų��len��λ��
	//3.��pos��ʼ����s
	//4.����_size
	void insert(size_t pos,const char* s){
		assert(pos <= _size);
		//����Ƿ���Ҫ����
		size_t len = strlen(s);
		if (_size+ len > _capacity){
			Reverse(_size+len);
		}
		 //��ʼŲ������
		size_t end = _size + len;
		while ((pos+len-1) < end){
			//��һ��Ų����Ϊ'\0'
			_str[end] = _str[end-len];
			end--;
		}

		//��posλ�ÿ�ʼ����s
		for (int i = 0; i < len;i++){
			_str[i + pos] = s[i];
		}
		_size += len;
	}

	//��ĳ���Ϸ���λ��ɾ��n��Ԫ��
	//1.pos+len>_size,
	//�൱�ڴ�posλ�ÿ�ʼ���ַ���Ҫ��ɾ��,����_size=pos,_str[size]='\0';
	//2.pos+len<=_size,
	//��pos+lenλ�ÿ�ʼ��ǰ�ƶ�len��λ��,�Ӻ���ǰŲ��;
	//3.����_size-=len;
	void Erase(size_t pos,size_t len){
		assert(pos<_size);
		//��pos��ʼ�����ַ�ȫ��ɾ��
		if (pos + len>_size){
			_size = pos;
			_str[_size] = '\0';
		}
		else{
			size_t start = pos + len;
			//�Ӻ���ǰŲ��len��λ��
			while (start<_size){
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
	String&operator+=(const char c) {
		PushBack(c);
		return *this;
	}
	//
	String& operator+=(const char *str){
		Append(str);
		return *this;
	}
	//��һ���ַ�
	//�ҵ��Ļ�������λ��
	//�Ҳ����Ļ�����npos
	size_t find(const char c){
		for (int i = 0; i < _size; i++){
			if (_str[i] == c){
				return i;
			}
		}
		return npos;
	}


	//��һ���ִ���
	//�ҵ��Ļ��������ִ�����ʼλ��
	//�Ҳ�������npos
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
		//�����жϵ�һ���ַ��Ƿ����
		if (*s1 == *s2){
			const char *ptr1 = s1;
			const char *ptr2 = s2;
			//�ж�s2�е�ÿһ��Ԫ��
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

const size_t String::npos = -1;
//�޷������͵����ֵ


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
	//���߶Ա�
	cout << s1.Size() << endl;
	String s2 = "hello world";

	cout << s2 << endl;
	cout << s2.Size() << endl;
}


//����������
//������ʵ��Ϊ"ָ��"
void testString1(){
	String s = "today";
	String::iterator sit = s.begin();
	while (sit != s.end()){
		cout << *sit ;
		sit++;
	}
	cout << endl;
}
//������
void testInsert(){
	String s = "hello love";
	//ͷ��
	s.insert(0, '\"');//ת����ŵ�ʹ��
	//�м��
	s.insert(6, ' ');

	//β��
	s.insert(s.Size(), '\"');
	cout << s << endl;
	s.insert(s.Size()-2, ' ');
	cout << s << endl;
	//�����ַ���
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


//����+=
void testString2(){
	String s;
	s += 'I';
	s += " love";
	cout << s<< endl;
	String s2(" you!");
	s += s2;
	cout << s << endl;
}


//���Բ���
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