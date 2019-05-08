#include"SList.h"

void TestSList(){
	SList list;
	SListInit(&list);
	//检验头插尾插
	/*SListPushFront(&list,1);
	SListPushFront(&list, 2); 
	SListPushFront(&list, 3);
	SListpushBack(&list,11);
	SListpushBack(&list,12);
	SListpushBack(&list,13);*/

	//检测没有节点时的尾插
	SListpushBack(&list,11);
	SListpushBack(&list,12);
	SListpushBack(&list,13);
	SListPrint(&list);
	//尾删
	SListPopFront(&list);
	SListPopBack(&list);
	SListPrint(&list);
}

int main(){
	TestSList();
	printf("程序运行成功!\n");
	system("pause");
	return 0;
}