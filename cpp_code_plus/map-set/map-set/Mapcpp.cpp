//#include<iostream>
//#include<windows.h>
//#include<string>
//
//using namespace std;
//#include<map>
//
//void test_map(){
//	map<string, string> names;
//	names.insert(pair<string, string>("insert", "����"));
//	//����д��names.insert(make_pair("insert", "����"));
//	//make_pairģ�庯��
//	//template<class K,class V>
//	//inline pair<K,V> make_pair(const K& k,const V&v){
//	//return pair<K,V> (k,v);
//    //}
//	names.insert(pair<string, string>("sort", "����"));
//	names.insert(pair<string, string>("find", "����"));
//	names.insert(pair<string, string>("binary", "��"));
//
//	//�޸Ĵ���
//	//No.1
//	auto it = names.find("binary");
//	if (it != names.end()){
//	it->second = "����λ��";
//	}
//	auto ret = names.begin();
//	//map<string, string> ::iterator ret = names.begin();
//	while (ret != names.end()){
//		cout << (*ret).first << ":" << (*ret).second << endl;
//		//cout << ret->first << ":" << ret->second << endl;
//		++ret;
//	}
//
//	//No.2
//	names["binary"] = "����λ";
//
//
//	
//	//c++11
//	for ( const auto& e : names){  //���޸�const
//		cout << e.first << ":" << e.second<<endl;
//	}
//}
//
//int main(){
//	test_map();
//	system("pause");
//	return 0;
//}
//



//
//#include<iostream>
//#include<windows.h>
//#include<string>
//
//using namespace std;
//#include<map>
//
//void test_map(){
//	
//	//ͳ�Ƶ��ʻ����ַ����ֵĴ���
//	string str_array[] = {"sort","love","love","binary","second"};
//	//NO.1 : map<string, int> count_map;
//	//NO.2:
//	typedef std::map<std::string,int> CountMap;
//	typedef std::map<std::string, int>::iterator CountMapIter;
//	CountMap count_map;
//	////No.1����ͳ�ķ�ʽͳ�ƴ���
//	//for (auto e:str_array)
//	//{
//	//	CountMapIter it = count_map.find(e);
//	//	if (it != count_map.end()){
//	//		//(*it).second++;
//	//		it->second++;
//	//	}
//	//	else{
//	//		count_map.insert(make_pair(e,1)); 
//	//		//insert�ڱȽ�ʱֻ��key�ڵ����ݲ���value
//
//	//	}
//	//}
//	////No.2��ʹ��insert�ķ���ͳ�ƴ���
//	//for (const auto& e : str_array){
//	//	auto ret = count_map.insert(make_pair(e, 1));
//	//	//pair<CountMapIter, bool> ret = count_map.insert(make_pair(e,1));
//	//	//Ч����ͬ
//	//	if (ret.second == false){
//	//		//ΪʲôΪfalse�鿴c++�ٷ��ĵ��ӿ�
//	//		ret.first -> second++;
//	//	}
//	
//	//}
//	//�������ݴ���ͬʱʹ�ã������Ľ��Ϊ���ַ��������ĺ�
//
//
//
//	//No.3:operator[]ͳ�ƴ���
//	for (const auto& e:str_array)
//	{
//		count_map[e]++;
//		//���������std::map::operator[]
//		//����ֵΪvalue
//	}
//
//	typedef map<string, string> Dict;
//	Dict dict;
//	dict["sort"] = "����";
//	dict["bug"] = "�۶���";
//	dict["left"] = "���";
//	dict["left"] = "ʣ��";
//	//��[]�е�����(key)��ͬ��ʱ��operator[]���value�����滻
//	//���Կɼ�
//	cout << dict["set"] << endl;
//	//ע����������
//}




#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<time.h>

using namespace std;

#include<set>
void benchmark(){
	size_t n;
	cin >> n;
	vector<int> v;
	v.reserve(n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i){
		v.push_back(rand());
	}

	set<int> s;
	size_t begin1 = clock();
	for (size_t i = 0; i < v.size();i++)
	{
		s.insert(v[i]);
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		s.find(v[i]);
	}
	size_t end1 = clock();
	cout << "set_insert:" << end1 - begin1 << endl;

	
	unordered_set<int> s1;
	size_t begin2 = clock();
	for (size_t i = 0; i < v.size(); i++)
	{
		s1.insert(v[i]);
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		s1.find(v[i]);
	}
	size_t end2 = clock();
	cout << "unoedered_set_insert:" << end2 - begin2 << endl;
}
//multimapû��operator[]
//����������
//������ǰ100����С��

int main(){
	benchmark();
	system("pause");
	return 0;
}


