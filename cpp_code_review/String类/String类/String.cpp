

#include<iostream>
#include<string>
using namespace std;
#if 0
int main(){
	string s;
	string s1("hello bit!");
	string s2(10,'$');
	string s3(s1);
	cout << s3<< endl;
	cout << s2 << endl;
	cout << s1.size() << endl;
	//����ַ�������Ч����
	cout << s1.length() << endl;
	//����Ч��һ��
	cout << s1.capacity() << endl;
	//���s1���������
	s1.clear();
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	//clear()�ӿ�ֻ�ǽ������е�������ղ�δ�ı�������

	cout << s1.empty() << endl;
	//�ж��ַ����Ƿ�Ϊ�գ����Ϊ����ֵ(1/0)
	string s4("hellow bit!");
	cout << s4[0] << endl;
	//s4[n]���s4�ĵ�n���ַ�
	s4[0] = 'H';
	//s[n]='x' ��д�ַ����ĵ�n���ַ�,���n�����������ͻ����쳣
	//������assert���
	cout << s4 << endl;


	return 0;
}
#endif

#if 0
int main(){
	string s;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << hex << (int)s.c_str() << endl;
	s.resize(10, '&');
	cout << s.size() << endl;
	//���㲢���s�ַ�������Ч�ַ�����
	cout << s << endl;

	s.resize(20, '5');
	//��s���������ݣ������ദ�Ŀռ��ʼ��Ϊ'5'
	//s.size(size_t n,char 'c')
	//�˴���n�е��������
	//1.n<size  size���n��capacity��С����
	//2.size<n<capacity size���n,capacity����
	//3.n>capacity   size���n��capacity����[size~n]
	//�����Χ�е�ֵ���ó�'c'
	//s.size(size_t n)  
	//1.n<size  size���n��capacity��С����
	//2.size<n<capacity size���n,capacity����
	//�����Χ�е�ֵ���ó�'\0'
	//3.n>capacity   size���n��capacity����[size~n]
	//�����Χ�е�ֵ���ó�'\0'
	cout << s.size() << endl;
	//���㲢���s�ַ�������Ч�ַ�����
	cout << s << endl;

	cout << s.c_str() << endl;
	//c���Եķ�������c �ĸ�ʽ��ȡ.��������ַ���������
	cout << hex << (int)s.c_str() << endl;
	//����ַ������׵�ַ
	s.resize(5);
	//�ı�ָ���ַ����Ŀռ�
	//������ռ��ʱ�����ַ���ܸı�
	//�ڼ�С�ռ��С��ʱ���ַ����ı�
	return 0;
}
#endif



#if 0
int main(){
	string s="hello bit!";
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity()<< endl;
	cout << hex << (int)s.c_str() << endl;
	s.reserve(20);
	//��sԤ���ռ䣬����ı���ЧԪ�ظ���
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << hex << (int)s.c_str() << endl;


	s.reserve(5);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << hex << (int)s.c_str() << endl;

	s += " haha";
	s += '!';
	string s1("hehe!");
	s += s1;
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	
	return 0;
	//void reserve(size_t n=0):
	//���Ч�ʣ����ٹ���ʱ��
	//reserve�������ݣ����Ч�ʣ��������ݲ���
	//��n>capacityʱ���������ݣ����ı�size�Ĵ�С
}
#endif



#if 0
void testString2(){
	string s;
	s.reserve(200);
	size_t sz = s.capacity();
	cout << sz << endl;
	cout << "capacity change:" << endl;
	for (int i = 0; i <200;i++){
		s.push_back(i);
		//���ݹ���
		//��һ�ΰ��������ݣ�������1.5������
		if (sz!=s.capacity())
		{
			sz = s.capacity();
			cout << sz << endl;
		}
		
	}
	cout << sz << endl;
	cout << s.size() << endl;
	cout << s.capacity()<<endl;
	
}

int main(){
	testString2();
	return 0;
}

#endif

#if 0

void testString(){
	string s;
	s.push_back('w');
	s += 'w';
	//����ַ�
	s.append("ang");
	s += " shi xian";
	//����ַ���
	cout << s << endl;

	string s1;
	s1.assign(s);
	cout << s1 << endl;
	//������s�����ݣ���ӡ�������ݺ�s��һ��

	s1.assign(s,0,3);
	//��s�дӵ�0��λ������3���ַ���s1;
	cout << s1 << endl;


	s1.assign(10,'a');
	//s.assign(size_t n,'x');��s1�е����ݸĳ�n��'x'
	cout << s1 << endl;

	s1.assign(s.begin(), s.end());
	//���������ַ���s
	cout << s1 << endl;
}

int main(){
	testString();
	return 0;
}

#endif


#if 0
//insert
int main(){
	string s;
	s.insert(0, "hello");
	cout << s << endl;
	s.insert(0, "bit!");
	cout << s << endl;
	//s.insert(size_t pos,const string& str)
	//��ĳ��λ�ÿ�ʼ����ͷ��
	string s1;
	s1.insert(0,s,3,5);
	//��s1�в���s�е����ݣ������0��λ�ÿ�ʼ����3��5��Ԫ��
	cout << s1 << endl;
	return 0;
}
#endif



#if 0
//ɾ��(erase)
int main(){
	string s("hello bit!");
	s.erase(0,4);
	//string& erase(size_t pos,size_t len);
	//ɾ���ӵ�0��λ�ÿ�ʼ��4���ַ�
	//��������length�����ַ������ȣ�ȡʵ�ʳ��Ⱥ�length�Ĵ�С�е� ��С��
	//�Ƚ����е��ַ�ɾ�����Ϳ���
	cout << s << endl;
	return 0;
}
#endif


//int main(){
//	string s("hello bit");
//	string s1("haha");
//	s.replace(0, 2, s1);
//	//��s1�е� ����������s�д�λ��0��ʼ��2���ַ�
//	cout << s1 << endl;
//	cout << s << endl;
//	return 0;
//}




#if 0
//substr
int  main(){
	string s("hello baby!");
	//substr(size_t pos=0,size_t n);
	//�������ַ���s�е�λ��0��ʼ��n���ַ�
	string s1 = s.substr(2,8);
	cout << s1 << endl;
	size_t pos = s.find('o');
	cout << pos << endl;
	//rfind��β�˿��ǲ��ҵ�һ��'o'
	s1 = s.substr(pos, s.size() - pos);
	cout << s1 << endl;

	string add = "http://www.cplusplus.com/reference/string/string/";
	size_t pos1 = add.find("://");//4
	string a = add.substr(0,pos1);
	cout<<"string a=" << a << endl;

	size_t sz = add.find('/',pos1 + 3);
	//find(char 'x',size_t pos);
	//��ָ����λ���±꿪ʼ����ָ�����ַ�'x'
	string b = add.substr(pos1 + 3, sz - pos1 - 3);
	cout << "string b="<<b << endl;
	return 0;
}
#endif




#if 0
//��ת�ַ���

string reverseString(string s){
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end){
		swap(s[begin], s[end]);
		end--;
		begin++;
	}
	return s;
}


int main(){
	string s("hello bit!");
	cout <<"s="<< s << endl;
	cout << "reverseString(s)=" << reverseString(s) << endl;
	return 0;
}
#endif

#if 0
class Solution{
public:
	int fristUniqChar(string s){
		int hashT[256] = { 0 };
		for (auto& e : s){
			hashT[e]++;
		}
		for (int i = 0; i < s.size(); i++){
			if (hashT[s[i]] == 1)
				return i;
		}
		return -1;
	}
};

int main(){
	string s;
	cin >> s;
	Solution s1;
	cout << s1.fristUniqChar(s) << endl;
	return 0;
}
#endif

#if 0
int main(){
	string s;
	while (cin >> s){
		int hashT[256] = { 0 };
		for (auto& e : s){
			hashT[e]++;
		}
		int i;
		for (i = 0; i < s.size(); i++){
			if (hashT[s[i]] == 1){
				cout << s[i] << endl;
				break;
			}
		}
		if (i >= s.size()){
			cout << -1 << endl;
		}
	}
	
	return 0;
}
#endif

#if  0

int main(){
	string s;
	while(getline(cin, s)){
		size_t pos = s.rfind(' ');
		if (pos == string::npos){
			cout << s.size() << endl;
		}
		else{
			cout << s.size() - pos - 1 << endl;
		}
	}
	return 0;
}
#endif

#if 0
class Solution{
public:
	bool isNumberLetter(char c){
		return (c >= '0'&&c <= '9')
			|| (c >= 'a'&&c <= 'z')
			|| (c >= 'A' <= 'Z');
	}
	
	bool isPalindrome(string s){
		int begin = 0;
		int end = s.size() - 1;
		//���е�Сдת��д
		for (auto&e : s){
			if (e >= 'a'){
				e -= 32;
			}
		}
		while (begin < end){
			while (begin < end){
				//��ǰ����ҵ���һ����ĸ������
				if (isNumberLetter(s[begin]))
					break;
				begin++;
			}
			while (begin < end){
				//��ǰ�����ҵ����һ����ĸ��������
				if (isNumberLetter(s[end]))
					break;
				end--;
			}
			//�Ƚ�begin��endλ�õ��ַ�
			//��Сд��ĸ���32
			if (s[begin] % 32 != s[end] % 32){
				//����ȡģ��ֵ��ȵ����
				//if((s[begin]+32-'a')%32!=(s[end]+32-'a')%32)
				return false;
			}
			if (s[begin] != s[end])
				return false;
				begin++;
			    end--;
		}
		return true;
	}
};

int  main(){
	string s = "H0POPPOP0H";
	Solution s1;
	cout << s1.isPalindrome(s) << endl;
	return 0;
}
#endif


#if 0
class Solution{
public:
	string addStrings(string num1, string num2){
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		int step = 0;//��λ
		int sum = 0;//��ǰλ�ĺ�
		string ret = "";//������
		//��֤������ַ�����β 

		int  capacity = end1 > end2 ? end1 + 1 : end2 + 1;
		ret.reserve(capacity);//��ǰ����ռ䣬��Сʱ�临�Ӷ�
		while (end1 >= 0 || end2 >= 0){
			//��ǰΪ�ĺ�
			sum = 0;//ÿ��Ҫ���㵱ǰλ�ĺ�
			sum +=step;
			if (end1 >= 0){
				sum += num1[end1]-'0';
			}
			if (end2 >= 0){
				sum += num2[end2]-'0';
			}
			//��ȡ��ǰλ��ֵ
			if (sum > 9){
				//������λ���ֵ
				sum -= 10;
				//���½�λ
				step = 1;
			}
			else{
				//�����ν�λ������10,���ܻ������һ�δ���10�Ľ�λ
				step = 0;
			}
			//��ͷ��ķ�ʽ����ǰλ��ֵ���ַ�������ʽ���浽�ַ����С�
			ret.insert(0, 1, sum + '0');
			end1--;
			end2--;
		}
		if (step == 1){
			//�������Ϊ�Ľ�λ
			ret.insert(0,1,'1');
		}
		return ret;
	}
};

int main(){
	string s1 = "123456";
	string s2 = "3456";
	Solution s;
	cout<<s.addStrings(s1, s2)<<endl;
	return 0;
}

#endif

