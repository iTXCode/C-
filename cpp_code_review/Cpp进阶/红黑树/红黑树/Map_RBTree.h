/*
�ú����ֻ��ʵ��map��set��ԭ��:�ڵ�ֵ�����ظ�
����һ��������+��֤

����ֻ��Բ���:operator*() / operator->()
�ƶ���ǰ����++/ǰ����--
�Ƚϣ�!=/==

map:<key,value>---->�ȽϷ�ʽ:��ֵ���е�key
set:key        ---->�ȽϷ�ʽ:ֱ������Ԫ�رȽ�
*/

//�ú������װMap

#pragma  once

#include"RBTree.h"
#include<iostream>
#include<string>
using namespace std;
namespace bite{
	//ֻ��Ҫ������װһ�������
	template<class K,class V>
	class map{
		typedef pair<K, V> ValueType;
		struct KeyOfValue 
		{
			const K& operator()(const ValueType& data){
				return data.first;
			}
		};
	public:
		typename typedef RBTree<ValueType, KeyOfValue>::iterator iterator;
	public:
		map()
			:_t()
		{}

		iterator begin(){
			return _t.begin();
		}
		iterator end(){
			return _t.end();
		}
		pair<iterator, bool> insert(const value_typ& data){
			return _t.Insert(data);
		}

		size_t size()const{
			return _t.Size;
		}

		bool empty()const {
			return _t.Empty();
		}
		iterator find(const K&key){
			return _t.Find(make_pair(key,V()));
		}
		//�±������
		V& operator[](const K& key){
			return (*((this->insert(make_pair(key, T()))).first));
		}
	private:
		RBTree<ValueType,KeyOfValue> _t;
		
	};
}


void TestMap(){
	bite::map<std::string, std::string> m;
	m.insert(pair<std::string, std::string>("hello", "���"));
	m.insert(make_pair("bit", "����"));
	m["China"] = "�й�";

	std::cout << m.size() << std::endl;

	for (auto e : m){
		std::cout << e.first << "-->" << e.second << std::endl;
	}
	std::cout << std::endl;
}


