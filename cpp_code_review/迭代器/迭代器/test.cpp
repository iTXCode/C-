#include<iostream>
#include<string>
#include<vector>
#include<list>


using namespace std;

#if 0
//const��������ʹ��
void printString(const string &s){
	string::const_iterator sit = s.begin();
	cout << "NO_2:" << " ";
	while (sit != s.end()){
		cout << *sit ;
		++sit;
	}
	cout << endl;
}

//���������
void printRString(const string &s){
	string::const_reverse_iterator sit = s.rbegin();
	cout << "NO_3:" << " ";
	while (sit != s.rend()){
		cout << *sit;
		++sit;
		//������++,�ڲ���--
	}
	cout << endl;
}
//rbeginָ�����һ��λ��
//rendָ���һ��λ�õ�ǰһ��λ��



//��ͨ������
void testiterator(){
	string s("hello bit!");
	string::iterator sit = s.begin();
	cout << "NO_1:" << " ";
	while (sit != s.end()){
		cout << *sit;
		++sit;
	}
	cout << endl;
	printString(s);
	printRString(s);


	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4); 
	v.push_back(5);

	vector <int>::iterator vit = v.begin();
	while (vit != v.end()){
		cout << *vit;
		++vit;
	}
	cout << endl;
}




int main(){
	testiterator();
	return 0;
}

//��������
//�漰ģʽ:���ʻ���
//���ⲿ������ָ��ʹ�ã��ڲ�ʵ���ϣ���ͬ������ 
//��ͬ��ʵ�ַ�ʽ��һ����ԭ��ָ��
//�����������ࡿ
//1.���������(�ɶ���д)
//2.���������(�ɶ���д)
//3.const������(ֻ��)
//begin:��һ��Ԫ�ص�λ��
//end:���һ��Ԫ�ص���һ��λ��
//rbegin:���һ��Ԫ�ص�λ��
//rend:��һ��Ԫ�ص�ǰһ��λ��

#endif


void testString1(){
	string s("haha");
	//�ɶ���д
	for (int i = 0; i < s.size(); ++i){
		cout <<"NO1:"<< s[i]  << " ";
		cout << "NO2:"<<s.operator[](i) << endl;
	}
	cout << endl;

	for (auto e : s){
		cout <<"NO3:"<< e << endl;
	}
	
}



int main(){
	testString1();
	return 0;
}