#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#pragma once

//typedef struct SeqList{ 
//	//静态顺序表定义
//	int array[100];    // 能存 100 个数的静态顺序表
//	int size;          //当前顺序表中存放的数，
//	                   //顺序表为空size=0顺便表示了即将插入的下标
//}   Seqlist;

typedef int SDataType;
typedef struct SeqList{
	//动态顺序表定义
	SDataType  *array;
	int size;          
	int capacity;    //容量
}   SeqList;


//顺序表的初始化/销毁
//seqlist 是一个变量的地址
//capacity是顺序表的初始容量
void SeqListInit(SeqList *seqlist, int capacity);


void SeqListDestroy(SeqList *seqlist);


//增删改查

//1.增

//尾插
void SeqListPushBack(SeqList *seqlist, SDataType value);


//头插
//1.从后往前搬，避免覆盖
//2.写循环
//       先确定循环的边界
//       i 空间下标[size,0)
//       i 数据下标[size-1,0]
//3. 搬移  
//    i对应空间下标：    array[i]=array[i-1];
//    i对应数据下标：    array[i+1]=array[i];
void SeqListPushFront(SeqList *seqlist,SDataType value);


//中间插入,往pos所在的下标插入value
//1.从后往前
//       [size-1,pos] i 数据
//       array[i+1]=array[i];
void SeqListInsert(SeqList *seqlist,int pos,SDataType value);


//删

//1.尾删
void SeqListPopBack(SeqList* seqlist);
//2.头删
//1.从后往前搬，避免覆盖
//2.写循环
//       先确定循环的边界
//       i 空间下标   [0,size-2]
//       i 数据下标   [1,size-1]
//3. 搬移  
//    i对应空间下标：    array[i]=array[i+1];
//    i对应数据下标：    array[i-1]=array[i];
void SeqListPopFront(SeqList* seqlist);

//删除 pos 所在的下标数据
void SeqListErase(SeqList *seqlist,int pos);


//打印

void SeqListPrint(const SeqList *seqlist);


//修改pos 所在下标的所在数据为 value
void SeqListModify(SeqList *seqlist,int pos, SDataType value);
//查找
int SeqListFind(const SeqList *seqlist,SDataType value);
//找到并删除第一个遇到的 value
void  SeqListRemove(SeqList *seqlist,SDataType value);

//判断顺序表是否为空，
bool SeqListEmpty(const SeqList *seqlist);
//返回数据个数
int SeqListSize(const SeqList *seqlist);

//冒泡排序

void SeqListBubbleSort(SeqList * seqlist);

//二分查找

int SeqListBinarySort(SeqList *seqlist,SDataType value);