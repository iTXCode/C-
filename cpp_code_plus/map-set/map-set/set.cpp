//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//
//#include<set>
////ʹ��set�ķ���������std�����ռ�
////set������
////1.key��ģ�ͳ������ж��ڲ��ڣ�
////2.����+ȥ��(����������ͬ�����ݽ�ȥ)
//
//void test_set(){
//	set<int> a1;  
//	a1.insert(9);
//	a1.insert(8);
//	a1.insert(7);
//	//2.����+ȥ��(����������ͬ�����ݽ�ȥ)
//	a1.insert(6);
//	a1.insert(6);
//	a1.insert(6);
//	a1.insert(6);
//	//ֻ���һ��6
//	set<int> ::iterator it1 = a1.begin(); 
//	while (it1 != a1.end()){
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//	//��ӡ�����Ľ�����մ�С�����˳���Զ�����������
//	//�ײ����������������������������������
//	//����������۱Ƚϴ�
//
//	
//	
//	//1.key��ģ�ͳ������ж��ڲ��ڣ�
//
//	//����ĳ��Ԫ�ص����
//	int  x = 0;
//	cin >> x;
//	auto ret = a1.find(x);  //����:ʱ�临�Ӷ�СO(logN)
//	//�Ҳ����ͻ᷵�ص�������ĩ��set::end
//	if (ret != a1.end()){
//		cout << x<< "��a1�ļ�����" << endl;
//		a1.erase(ret);
//	}
//	else{
//		cout << x << "����a1�ļ�����" << endl;
//	}
//
//	for (auto e : a1)
//	{
//		cout << e << " ";
//		//�򻯰�
//	}
//	cout << endl;
//}
//
//int main(){
//	test();
//	system("pause");
//	return 0;
//	
//}

//multiset��Ӧ�� 
//#include<iostream>
//#include<windows.h>
//#include<string>
//using namespace std;
//
//#include<set>
//
//void test_multiset(){
//	//multiset�ײ�����������,����ȥ��
//	//�������򣬲�ȥ��
//	multiset<int> s1;
//	s1.insert(10);
//	s1.insert(1);
//	s1.insert(3);
//	s1.insert(5);
//	s1.insert(9);
//	s1.insert(110);
//	s1.insert(120);
//
//	for (auto e : s1){
//		cout << e << " ";
//	}
//	cout << endl;
//
//	multiset <string> names;
//	names.insert("Lining");
//	names.insert("sort");
//	names.insert("fight");
//	multiset<string> ::iterator it = names.begin();
//	while (it != names.end()){
//		cout << it<< endl;
//		it++;
//	}
//	
//}
//
//int main(){
//	test_multiset();
//	system("pause");
//	return 0;
//
//}