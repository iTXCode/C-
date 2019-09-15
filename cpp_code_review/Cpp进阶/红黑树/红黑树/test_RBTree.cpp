#if 0
#include<iostream>
#include"RBTree.h"

using namespace std;


void Test(){
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	RBTree<int> t;
	for (auto e : array)
		t.Insert(e);
	cout << "�������:";
	t.PreOrder();
	cout << endl;
	cout << "�������:";
	t.InOrder();
	cout << endl;
	cout << "�������:";
	t.TailOrder();
	cout << endl;
	if(t.IsValidRBTree()){
		cout<<"t ��һ�κ����"<<endl;
	}else{
		cout<<"t ����һ�ź����"<<endl;
	}

	RBTree<int>::iterator it = t.begin();
	while (it != t.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main(){
	Test();
	return 0;
}

#endif
