/*
用红黑树只能实现map和set的原因:节点值不能重复
增加一个迭代器+验证

具有只针对操作:operator*() / operator->()
移动：前后置++/前后置--
比较：!=/==

map:<key,value>---->比较方式:键值对中的key
set:key        ---->比较方式:直接用其元素比较
*/

//用红黑树封装Map

#pragma  once

#include"RBTree.h"
#include<iostream>
#include<string>
using namespace std;
namespace bite{
	//只需要给他封装一个红黑树
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
		//下表运算符
		V& operator[](const K& key){
			return (*((this->insert(make_pair(key, T()))).first));
		}
	private:
		RBTree<ValueType,KeyOfValue> _t;
		
	};
}


void TestMap(){
	bite::map<std::string, std::string> m;
	m.insert(pair<std::string, std::string>("hello", "你好"));
	m.insert(make_pair("bit", "比特"));
	m["China"] = "中国";

	std::cout << m.size() << std::endl;

	for (auto e : m){
		std::cout << e.first << "-->" << e.second << std::endl;
	}
	std::cout << std::endl;
}


