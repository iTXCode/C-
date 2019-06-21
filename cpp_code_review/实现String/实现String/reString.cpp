
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
	//���鲻ʹ�ó�ʼ���б�
	String(char *str="")
		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size+1])
	{
		strcpy(_str, str); //�´��'\0'
	}

	
	//��������
	~String()
	{
		if (_str){

			delete[] _str;//�ͷŶ�����Ŀռ�
			_str = nullptr;
		}
	}

	//���ȼ��capacity�������������������������
	void pushBack(const char c){
		if (_size == _capacity){
			size_t newc = (_capacity == 0?15:_capacity*2);
			Reserve(newc);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}
	//����:ֻ���ݣ����������������ı�size
	void Reserve(size_t n){
		if (n > _capacity){
			//����
			char *tmp = new char[n + 1];
			//����thisָ��ָ�����Ч����
			strcpy(tmp, _str);
			delete[] _str;//�ͷ�ԭ�пռ�
			_str = tmp; //ָ��ԭ�пռ�
			//��������ֵ
			_capacity = n;
		}
	}

	iterator begin(){
		return _str;
		//���ص�һ��Ԫ�ص�λ��(��ַ)
	}
	iterator end(){
		//�������һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}

	const_iterator begin()const{
		return _str;
		//���ص�һ��Ԫ�ص�λ��(��ַ)
	}
	const_iterator end()const{
		//�������һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}


	//�ɶ���д�ӿ�
	char& operator[](size_t pos)
	{
		//��ֹ����Խ��
		assert(pos<_size);
		return _str[pos];
	}

	//ֻ���ӿ�,�������޸ģ�����const ����
	const char& operator[](size_t pos) const 
	{
		//��ֹ����Խ��
		assert(pos<_size);
		return _str[pos];
	}
	//βɾ
	void popBack(){
		assert(_size > 0);//ȷ������һ����Ч�ַ�
		_str[--_size ] = '\0';
	}

	//���������졿:��ͳд��
	/*String(const String& s)
		:_str(new char[strlen(s._str)+1])
		{
		strcpy(_str, s._str);
		}*/
	//�ִ�д��
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
		//�����õ�Ŀ�ı��⴫ֵʱ���ÿ�������
		//�Ӷ��������޵ݹ�
		swap(_str, tmp._str);
		swap(_size, tmp._size);
		swap(_capacity, tmp._capacity);
	}
	//��const�����const���󶼿��Ե���const��Ա����
	size_t Size()const{
		return _size;
	}
	

	//����ֵ��������ء�[��ͳд��]
	/*String &operator=(const String&s){
		if (this != &s){
		delete[] _str;
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
		}
		return *this;
		}
		*/
	//[�ִ�д��]
	//Ŀ�����ڽ�������ָ��ָ��Ŀռ�
	String& operator=(String s){
		Swap(s);//Swap(this,s);
		return *this;
	}
	char *c_str(){
		return _str;
	}
private:
	char* _str;
	size_t _size; //��Ч�ַ���,����'\0' 
	size_t _capacity;
	//����:ʵ���ܴ�ŵ�����ַ���������'\0'��ʵ�������
	//�ռ�Сһ���ֽ�
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

//���ڷ�Χ��forѭ��,�����ڵ�����
void PrintStringFor(const String&s){
	for (auto &e:s){
		cout <<e << " ";
	}
	cout << endl;
}


//������ �ķ�ʽ����
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