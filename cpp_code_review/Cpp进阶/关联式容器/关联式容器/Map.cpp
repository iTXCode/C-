#if 0

#include<iostream>
#include<map>
#include<string>
#include <functional>
using namespace std;

//void test(){
//	map<string, string> dictMap;
//	dictMap.insert(make_pair("�й�", "China"));
//	dictMap.insert(make_pair("�ձ�", "Japanese"));
//	//ע��map�����Ĳ��뷽ʽ
//	dictMap["����"] = "xi,an";
//	auto dit = dictMap.begin();
//	while (dit != dictMap.end()){
//		cout << dit->first << " " << dit->second << endl;
//		++dit;
//	}
//}
void testMap(){
	map<int,string, greater<int>> testMap;
	testMap[8] = "�й�";
	testMap[2] = "����";
	testMap[1] = "����";
	testMap[3] = "������";
	testMap[10] = "������";
	testMap[9] = "����";
	testMap.insert(make_pair(11,"Ӣ��"));
	for (const auto& e : testMap){
		cout << e.first << " " << e.second << endl;
	}
	int key;
	/*while (cin >> key){
		if (testMap.count(key))
		cout << key<<"-->" << testMap[key] << endl;
		else
		cout << "not dind key:" << key << endl;
		}*/
	cin >> key;
	//find�ĵ�������ʹ��
	if (testMap.find(key) != testMap.end()){
		cout << testMap[key] << endl;
	}
	
}
int main(){
	testMap();
	return 0;
}

#endif

#if 0
//map��������ʹ��
#include<iostream>
#include <string>
#include <map>

using namespace std;

void TestMap()
{
	map<string, string> m{ { "apple", "ƻ��" },
	{ "banan", "�㽶" },
	{ "orange", "����" },
	{ "peach", "����" },
	{ "waterme", "ˮ����" } };
	cout << endl;
	for (auto it = m.begin(); it != m.end(); ++it)
		cout<< (*it).first << "--->" << it->second << endl;
	cout<< endl;
	
}

int main(){
	TestMap();
	return 0;
}

#endif


#if 0
#include<iostream>
#include <string>
#include <map>

using namespace std;
void TestMap()
{
	// ����һ���յ�map����ʱm��һ��Ԫ�ض�û��
	map<string, string> m;
	/*
	operator[]��ԭ���ǣ�
	��<key, T()>����һ����ֵ�ԣ�Ȼ�����insert()�������ü�ֵ�Բ��뵽map��
	���key�Ѿ����ڣ�����ʧ�ܣ�insert�������ظ�key����λ�õĵ�����
	���key�����ڣ�����ɹ���insert���������²���Ԫ������λ�õĵ�����
	operator[]�������insert����ֵ��ֵ���е�value����
	*/
	// ��<"apple", "">����map�У�����ɹ�������value�����ã�����ƻ������ֵ�������ý����
	// ���޸���"apple"��Ӧ��value""Ϊ"ƻ��"
	m["apple"] = "ƻ��";
	// ��<"apple", "">����map�У�����ʧ�ܣ���<"apple", "ƻ��">�е�"ƻ��"����
	cout << m["apple"] << endl;
	cout << m.size() << endl;
	// ��banan����map�У��ú������쳣��
	m.at("banan");
}

int  main(){
	TestMap();
	return 0;
}
#endif
//������multimap��

#include<iostream>
#include<map>
#include<string>
#include <functional>
using namespace std;

void testMap(){
	
		multimap<int, string, greater<int>> testMap;
		//multimap�����ṩ[]������key��Ψһ
		//��ֵ�����ظ�
		/*testMap[8] = "�й�";
		testMap[2] = "����";
		testMap[1] = "����";
		testMap[3] = "������";
		testMap[10] = "������";*/

		testMap.insert(make_pair(1, "�й�"));
		testMap.insert(make_pair(2, "����"));
		testMap.insert(make_pair(3, "Ӣ��"));
		testMap.insert(make_pair(7, "����"));
		testMap.insert(make_pair(8, "�¹�"));
		testMap.insert(make_pair(9, "��������"));
		cout << testMap.count(1) << endl;
		for ( const auto& e : testMap){
			cout << e.first << "-->" << e.second << endl;
		}

		//ѡ���ֵ���ڵ��ڸ������ֵ�ֵ
		auto mit = testMap.lower_bound(3);
		cout << mit->first<<"-->"<<mit->second << endl;
		//ѡ���ֵС�ڸ������ֵ�ֵ
		mit = testMap.upper_bound(3);
		cout << mit->first << "-->" << mit->second << endl;
	}

int main(){
	testMap();
	return 0;
}



#if 0
#include<iostream>
#include<set>
#include<string>
#include <functional>
using namespace std;

void testset(){

	set<int> testSet;
	testSet.insert(1);
	testSet.insert(2);
	testSet.insert(4);
	testSet.insert(6);
	testSet.insert(5);
	testSet.insert(9);
	for (const auto& e : testSet){
		cout << e << endl;
	}
//�Զ�����(�Ӵ�С)���Զ�ȥ�� 
}

int main(){
	testset();
	return 0;
}
#endif


#if  0
#include<iostream>
#include<set>
#include<string>
#include <functional>
using namespace std;

void testset(){

	multiset<int> testSet;
	testSet.insert(1);
	testSet.insert(1);
	testSet.insert(1);
	testSet.insert(2);
	testSet.insert(4);
	testSet.insert(6);
	testSet.insert(5);
	testSet.insert(9);
	for (const auto& e : testSet){
		cout << e << endl;
	}
	//�Զ�����(��С����),�����ظ� 
}

int main(){
	testset();
	return 0;
}
#endif

