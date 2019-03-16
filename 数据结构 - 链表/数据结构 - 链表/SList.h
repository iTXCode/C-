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

//初始化
void SListInit(SList*list);

//销毁过程
void SListDestory(SList *list);

//增
//头插
void SListPushFront(SList *list,SLDataType value);
//尾插
void SListpushBack(SList *list, SLDataType value);




//删
//头删
void SListPopFront(SList *list);
//尾删
void SListPopBack(SList *list);


//打印
void SListPrint(SList *list);