#include"SList.h"

void TestSList(){
	SList list;
	SListInit(&list);
	//����ͷ��β��
	/*SListPushFront(&list,1);
	SListPushFront(&list, 2); 
	SListPushFront(&list, 3);
	SListpushBack(&list,11);
	SListpushBack(&list,12);
	SListpushBack(&list,13);*/

	//���û�нڵ�ʱ��β��
	SListpushBack(&list,11);
	SListpushBack(&list,12);
	SListpushBack(&list,13);
	SListPrint(&list);
	//βɾ
	SListPopFront(&list);
	SListPopBack(&list);
	SListPrint(&list);
}

int main(){
	TestSList();
	printf("�������гɹ�!\n");
	system("pause");
	return 0;
}