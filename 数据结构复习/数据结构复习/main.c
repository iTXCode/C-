#define _CRT_SECURE_NO_WARNINGS 1

//#include"SeqList.h"
//#include<windows.h>
//
//void TestSeqList(){
//	int input = 0;
//	SeqList seqlist;
//	SeqListInit(&seqlist,100);
//	do{
//		printf("请输入您要执行的操作标号:");
//		scanf("%d", &input);
//		switch (input){
//		case 1:
//			printf("销毁顺序表!\n");
//			SeqListDestroy(&seqlist);
//			break;
//		case 2:
//			printf("尾插法:\n");
//			printf("请输入要尾插的值：");
//			SDataType value;
//			scanf("%d",&value);
//			SeqListPushBack(&seqlist,value);
//			break;
//		case 3:
//			printf("头插法:\n");
//			printf("请输入要头插的值：");
//			SDataType value1;
//			scanf("%d", &value1);
//			SeqListPushFront(&seqlist, value1);
//			break;
//		case 4:
//			printf("尾删法:\n");
//			SeqListPopBack(&seqlist);
//			break;
//		case 5:
//			printf("头删法:\n");
//			SeqListPopFront(&seqlist);
//			break;
//		case 0:
//			printf("退出程序!\n");
//			break;
//		default:
//			printf("输入错误，请重新输入!\n");
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