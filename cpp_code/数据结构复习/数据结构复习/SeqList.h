#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#pragma once

//typedef struct SeqList{ 
//	//��̬˳�����
//	int array[100];    // �ܴ� 100 �����ľ�̬˳���
//	int size;          //��ǰ˳����д�ŵ�����
//	                   //˳���Ϊ��size=0˳���ʾ�˼���������±�
//}   Seqlist;

typedef int SDataType;
typedef struct SeqList{
	//��̬˳�����
	SDataType  *array;
	int size;          
	int capacity;    //����
}   SeqList;


//˳���ĳ�ʼ��/����
//seqlist ��һ�������ĵ�ַ
//capacity��˳���ĳ�ʼ����
void SeqListInit(SeqList *seqlist, int capacity);


void SeqListDestroy(SeqList *seqlist);


//��ɾ�Ĳ�

//1.��

//β��
void SeqListPushBack(SeqList *seqlist, SDataType value);


//ͷ��
//1.�Ӻ���ǰ�ᣬ���⸲��
//2.дѭ��
//       ��ȷ��ѭ���ı߽�
//       i �ռ��±�[size,0)
//       i �����±�[size-1,0]
//3. ����  
//    i��Ӧ�ռ��±꣺    array[i]=array[i-1];
//    i��Ӧ�����±꣺    array[i+1]=array[i];
void SeqListPushFront(SeqList *seqlist,SDataType value);


//�м����,��pos���ڵ��±����value
//1.�Ӻ���ǰ
//       [size-1,pos] i ����
//       array[i+1]=array[i];
void SeqListInsert(SeqList *seqlist,int pos,SDataType value);


//ɾ

//1.βɾ
void SeqListPopBack(SeqList* seqlist);
//2.ͷɾ
//1.�Ӻ���ǰ�ᣬ���⸲��
//2.дѭ��
//       ��ȷ��ѭ���ı߽�
//       i �ռ��±�   [0,size-2]
//       i �����±�   [1,size-1]
//3. ����  
//    i��Ӧ�ռ��±꣺    array[i]=array[i+1];
//    i��Ӧ�����±꣺    array[i-1]=array[i];
void SeqListPopFront(SeqList* seqlist);

//ɾ�� pos ���ڵ��±�����
void SeqListErase(SeqList *seqlist,int pos);


//��ӡ

void SeqListPrint(const SeqList *seqlist);


//�޸�pos �����±����������Ϊ value
void SeqListModify(SeqList *seqlist,int pos, SDataType value);
//����
int SeqListFind(const SeqList *seqlist,SDataType value);
//�ҵ���ɾ����һ�������� value
void  SeqListRemove(SeqList *seqlist,SDataType value);

//�ж�˳����Ƿ�Ϊ�գ�
bool SeqListEmpty(const SeqList *seqlist);
//�������ݸ���
int SeqListSize(const SeqList *seqlist);

//ð������

void SeqListBubbleSort(SeqList * seqlist);

//���ֲ���

int SeqListBinarySort(SeqList *seqlist,SDataType value);