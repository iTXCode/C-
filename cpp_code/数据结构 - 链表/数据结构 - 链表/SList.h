#pragma once
#include<stdio.h>
#include<windows.h>
#include<assert.h>


typedef int SLDataType;

typedef struct SLNode{
	SLDataType value;
	struct SLNode *next;
}SLNode;


typedef struct SList{
	SLNode *first;
}SList;

//��ʼ��
void SListInit(SList*list);

//���ٹ���
void SListDestory(SList *list);

//��
//ͷ��
void SListPushFront(SList *list,SLDataType value);
//β��
void SListpushBack(SList *list, SLDataType value);




//ɾ
//ͷɾ
void SListPopFront(SList *list);
//βɾ
void SListPopBack(SList *list);


//��ӡ
void SListPrint(SList *list);