#include<iostream>
#include<vector>

using namespace std;
//���ͱ��

//int main(){
//	vector<char> v;
//	//vector�е����ݲ�����'\0'������(string ����)
//	//vector�п��Թ���ͬ���͵�����
//	vector<char> v2(10, 'x');
//	vector<int> v4(10, 2);
//	vector<int>::iterator sit = v4.begin();
//	while (sit != v4.end()){
//		cout << *sit;
//		sit++;
//	}
//	string s("hello bit!");
//	vector<char> v3(s.begin(),s.end());
//	return 0;
//}
////string::iterator: char*
////vector<T>:  T*

//int main(){
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (int i = 0; i < v.size(); i++){
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	//��ͨ��������ʽ����
//	//vector<int>::iterator vit = v.begin();
//	auto vit = v.begin();
//	while (vit!=v.end()){
//		cout << *vit << " ";
//		vit++;
//	}
//	cout << endl;
//
//
//	//����������ķ��ʷ�ʽ
//	auto vit1 = v.rbegin();
//	while (vit1 != v.rend()){
//		cout << *vit1 << " ";
//		vit1++;
//	}
//	cout << endl;
//
//	//��ӡ�����������ݵ�ʱ���ܸı�������
//	vector<int>::const_iterator  cvit = v.begin();
//	while (cvit != v.end()){
//		cout << "const:" << *cvit<<" ";
//		cvit++;
//	}
//	cout << endl;
//
//	//���ڷ�Χ��forѭ��,�ڲ����õ�������begin��end;
//	for (auto &e : v){
//		
//		cout << e << " ";
//		//e++;//�˴���eƥ����ǵ������е�Ԫ��
//		//����++������Ļ��͸ı��˵���������Ҫ���������
//	}
//	cout << endl;
//	return 0;
//}
 

//void printVector(vector<int> &v){
//	//����ֻ�Ǽ򵥴�ӡ�Ŀ��Դ����ã�����������ֵ����
//	//��ϣ���޸ĵ������е����ݣ���������ʱ����Դ�const���ε� ����
//	//���磺const vector<int> &v;
//	auto vit1 = v.begin();
//	while (vit1 != v.end()){
//		cout << *vit1 << " ";
//		vit1++;
//	}
//	cout << endl;
//}
//
//int main(){
//	vector<int> v(10, 1);
//	printVector(v);
//	//max_size();��ʾ�������п��Դ�ŵ����Ԫ������
//	vector<int> v1;
//	vector<char> v2;
//	vector<double> v3;
//	cout << v1.max_size() << endl;  //1G
//	cout << v2.max_size() << endl;  //4G
//	cout << v3.max_size() << endl;  //0.5G
//	return 0;
//}



#if 0
void printVector(vector<int> &v){
	//����ֻ�Ǽ򵥴�ӡ�Ŀ��Դ����ã�����������ֵ����
	//��ϣ���޸ĵ������е����ݣ���������ʱ����Դ�const���ε� ����
	//���磺const vector<int> &v;
	auto vit1 = v.begin();
	while (vit1 != v.end()){
		cout << *vit1 << " ";
		vit1++;
	}
	cout << endl;
}

//insert�ӿڵĲ���
void testVector(){
	vector<int> v;
	//vector������ʼֵΪ0(��������ݵ�ʱ��)
	//֮�����ݵ�ʱ��window����ԭ��������1.5����������
	//Linux����ԭ����2����������
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	
	v.insert(v.begin(), 0);  //ͷ��
	v.insert(v.end(), 6);   //β��
	//�����Ĳ���������λ��,���ǵ�����
	printVector(v);
	v.insert(++v.begin(),10,20);
	//����������++;��Ԫ�ص���һ��Ԫ��

	printVector(v);
}

//���ݵ��Ƿ�ᵼ�µ�����ʧЧ
//�൱��һ��Ұָ��
int main(){
	testVector();
	return 0;
}


#endif

#if 0
void printVector(vector<int> &v){
	//����ֻ�Ǽ򵥴�ӡ�Ŀ��Դ����ã�����������ֵ����
	//��ϣ���޸ĵ������е����ݣ���������ʱ����Դ�const���ε� ����
	//���磺const vector<int> &v;
	auto vit1 = v.begin();
	while (vit1 != v.end()){
		cout << *vit1 << " ";
		vit1++;
	}
	cout << endl;
}

//eraseɾ��λ�õĵ�����

void testErase(){
	vector<int> v(10, 2);
	//ɾ�������Ĳ���,ɾ������һ��Ԫ�صĻ�(ɾ��λ�õĵ�����)
	//ɾ��������������Ԫ�صĻ�(����Ϊ����������)
	//iterator erase(iterator pos)
	//iterator erase(iterator first,iterator last)
	//�ӵ�����first��ʼɾ����������last;
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin(), v.end()-3);
	//���������Խ��мӼ�����
	printVector(v);
}

int main(){
	testErase();
	return 0;
}
#endif



#if 0
//������ʧЧ:������ָ���λ����Ч/Խ��
//1.insert(iterator it,T x);
//������ܵ������ݣ����ͷ�ԭ�еĿռ䣬�����µĿռ䣬����ԭ�е�����
//����֮ǰ�ĵ�����λ�ÿ����Ѿ����ͷţ�����ΪҰָ��
//������insert�ӿ�,���»�ȡ����������ֹ������ʧЧ
//2.����erase(iterator it);
//����Խ��,
//������erase�ӿ�,��ȡerase�ӿڵķ���ֵ����ֹ������ʧЧ
void printVector(vector<int> &v){
	//����ֻ�Ǽ򵥴�ӡ�Ŀ��Դ����ã�����������ֵ����
	//��ϣ���޸ĵ������е����ݣ���������ʱ����Դ�const���ε� ����
	//���磺const vector<int> &v;
	auto vit1 = v.begin();
	while (vit1 != v.end()){
		cout << *vit1 << " ";
		vit1++;
	}
	cout << endl;
}

void testErase(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	auto vit = v.begin();
	while (vit != v.end()){
		if (*vit % 2 == 0)
			vit=v.erase(vit);
		//������erase�ӿ�,��ȡerase�ӿڵķ���ֵ����ֹ������ʧЧ
		//������vitȥ������ӿڷ���ֵ�Ļ����ͷ�һ�κ������
		//������ֵ��Ŀ���Ƿ�ֹ������ָ���λ����һ����Ч��λ�á�
		//��ȡerase�ӿڵķ���ֵ(����ֵΪ������)

		else
			vit++;
	}
	printVector(v);
}
int main(){
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	testErase();
	//auto vit = v1.begin();
	//v1.insert(vit,10);  
	//�ڲ����ʱ����������ݲ������ù��������¿����˿ռ�
	//����ԭ���Ŀռ�ʧЧ(������ʧЧ),

	auto vit = v1.begin();
	v1.insert(vit, 10);
	vit = v1.begin();
	//������insert�ӿ�,���»�ȡ����������ֹ������ʧЧ
	*vit = 20; //���ʣ�Ұָ��(ָ���Ѿ��ͷŵĿռ�)
	v1.push_back(3);
	v1.push_back(4);
	printVector(v1);
	return 0;
}

//@@@@@@@@
//�ܲ����Լ�ʵ�ֵ�ʱ��insert������Ƴ���ԭ���ĵ�ַ�������ݣ�
//@@@@@@@@

#endif

#if 0
void printVector(const vector<int> &v){
	for (auto& e : v){
		cout << e << " ";
	}
	cout << endl;
}
//ȫ�ֺ���swap�ͳ�Ա����swap
//��������������
//������û������
//string��swap����
//ȫ�ֺ�����swap(s1,s2)-->{s1.swap(s2)}//�������ڲ����õ�Ϊstring�ĳ�Ա����
//��Ա������swap(s2)-->s1.swap(s2);
//ȫ�ֵ�swapֻ�ǶԳ�Ա��swap���������˷�װ
//ͨ��ȫ�ֱ���:swap(T& s1,T& s2)-->{T temp=s1;s1=s2;s2=temp;} //�����˿���
//vector��swap����
//ȫ�ֺ�����swap(s1,s2)-->{s1.swap(s2)}//�������ڲ����õ�Ϊvector�ĳ�Ա����
//��Ա������swap(s2)-->s1.swap(s2);
//ȫ�ֵ�swapֻ�ǶԳ�Ա��swap���������˷�װ
int main(){
	vector<int> v1(3, 2);
	vector<int> v2(3, 4);
	printVector(v1);
	printVector(v2);
	//ȫ�ֵĽ�������
	swap(v1, v2);
	cout << "ȫ�ֺ���������:" << endl;
	printVector(v1);
	printVector(v2);
	//��Ա����
	v1.swap(v2);
	cout << "��Ա����������:" << endl;
	printVector(v1);
	printVector(v2);
	
	return 0;
}
#endif


#if 0
//�ֶ��ͷ�vector���ڴ�ռ�
//1.��һ���ֲ����ж���һ���յ�vector
//2.����vector swap��������ɿռ�Ľ���
//3.���˾ֲ��򣬱������Զ����þֲ����ж���ľֲ�������������������ɿռ���ͷ�
//{vector<T> tmp; tmp.swap(v);}
int main(){
	vector<int> v(90, 1);
	cout << v.capacity() << endl;
	//No1:
	{
		vector<int> v1;
		//�����ʱ��û�г�ʼ��,���ڲ�û����������Ϊ0
		v1.swap(v);
	}//����{}���Ὣvԭ���Ŀռ��ͷŵ�
	//(����{}���ڳ��������ʱ��������������ͷžֲ�����v1)
	cout << "No1:"<<v.capacity() << endl;
	//No2:

	vector<int> v1(90, 1);
	cout << v1.capacity() << endl;
	v1.resize(0);//�ı�v1����Ч�ַ���
	v1.shrink_to_fit();
	//
	cout << "No2:" << v1.capacity() << endl;
	return 0;
}
#endif

