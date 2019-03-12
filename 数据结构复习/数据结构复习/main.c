#define _CRT_SECURE_NO_WARNINGS 1

//#include"SeqList.h"
//#include<windows.h>
//
//void TestSeqList(){
//	int input = 0;
//	SeqList seqlist;
//	SeqListInit(&seqlist,100);
//	do{
//		printf("��������Ҫִ�еĲ������:");
//		scanf("%d", &input);
//		switch (input){
//		case 1:
//			printf("����˳���!\n");
//			SeqListDestroy(&seqlist);
//			break;
//		case 2:
//			printf("β�巨:\n");
//			printf("������Ҫβ���ֵ��");
//			SDataType value;
//			scanf("%d",&value);
//			SeqListPushBack(&seqlist,value);
//			break;
//		case 3:
//			printf("ͷ�巨:\n");
//			printf("������Ҫͷ���ֵ��");
//			SDataType value1;
//			scanf("%d", &value1);
//			SeqListPushFront(&seqlist, value1);
//			break;
//		case 4:
//			printf("βɾ��:\n");
//			SeqListPopBack(&seqlist);
//			break;
//		case 5:
//			printf("ͷɾ��:\n");
//			SeqListPopFront(&seqlist);
//			break;
//		case 0:
//			printf("�˳�����!\n");
//			break;
//		default:
//			printf("�����������������!\n");
//			break;
//		}
//	} while (input);
//}
//
//
//int main(){
//	
//	TestSeqList();
//	system("pause");
//	return 0;
//}


#include"SeqList.h"
#include<windows.h>

void TestSeqList(){
	SeqList seqlist;
	SeqListInit(&seqlist,100);
	SeqListPushBack(&seqlist,1);
	SeqListPushFront(&seqlist,11);
	SeqListPushBack(&seqlist,2);
	SeqListPushFront(&seqlist,12);
	SeqListPushBack(&seqlist,3);
	SeqListPushFront(&seqlist,13);
	SeqListInsert(&seqlist,4,100);
	SeqListPopBack(&seqlist);
	SeqListPopFront(&seqlist);
	SeqListErase(&seqlist, 3);
	SeqListDestroy(&seqlist);
}


int main(){

	TestSeqList();
	system("pause");
	return 0;
}