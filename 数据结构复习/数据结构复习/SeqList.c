#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"
#include<assert.h>

//扩容
//条件 size=capacity;

static void CheckCapccity(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size <= seqlist->capacity);
	if (seqlist->size < seqlist->capacity){
		return;
	}
	//走到这里，需要扩容
	int capacity = 2 * seqlist->capacity;
	SDataType *array = (SDataType *)malloc(sizeof(SDataType)*capacity);
	assert(array);
	//把老数据搬过来
	for (int i = 0; i < seqlist->capacity; i++){
		array[i] = seqlist->array[i];
	}
	//释放老空间
	free(seqlist->array);
	seqlist->array = array;
}

void SeqListInit(SeqList *seqlist, int capacity){
	assert(seqlist != NULL);
	seqlist->array = (SDataType*)malloc(sizeof(SDataType)*capacity);
	seqlist->size = 0;
	seqlist->capacity = capacity;
}


void SeqListDestroy(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array!=NULL);
	

	seqlist->array = NULL;
	seqlist->size = 0;
	seqlist->capacity = 0;
	free(seqlist->array);   //重点
}
//尾插
void SeqListPushBack(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);


	CheckCapccity(seqlist);
	seqlist->array[seqlist->size] = value;
	seqlist->size++;
}


//头插
void SeqListPushFront(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	CheckCapccity(seqlist);
		//做数据的搬移，i代表空间下标
	for (int i = seqlist->size ; i > 0; i--){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = value;
	seqlist->size++;
}
//中间插入
void SeqListInsert(SeqList *seqlist, int pos, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(pos >= 0 && pos <= seqlist->size);

	CheckCapccity(seqlist);

	for (int i = seqlist->size - 1; i >= pos; i--){
		seqlist->array[i+1] = seqlist->array[i];
	}
	seqlist->array[pos] = value;
	seqlist->size++;
}

//尾删
void SeqListPopBack(SeqList*seqlist){
	assert(seqlist!=NULL);
	assert(seqlist->array!=NULL);
	assert(seqlist->size > 0);
	seqlist->size--;
}


//头删
//1.从后往前搬，避免覆盖
//2.写循环
//       先确定循环的边界
//       i 空间下标   [0,size-2]
//       i 数据下标   [1,size-1]
//3. 搬移  
//    i对应空间下标：    array[i-1]=array[i];
//    i对应数据下标：    array[i]=array[i+1];
void SeqListPopFront(SeqList* seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	for (int i = 1; i <seqlist->size ; i++){
		seqlist->array[i - 1] = seqlist->array[i];
	}
	seqlist->size--;
}

//删除 pos 所在的下标数据
void SeqListErase(SeqList *seqlist, int pos){
	assert(seqlist!=NULL);
	assert(seqlist->array!=NULL);
	assert(seqlist ->size>0);
	assert(pos >= 0 && pos < seqlist->size);
	for (int i = pos; i <seqlist->size; i++){
		seqlist->array[i] = seqlist->array[i+1];
	}
	seqlist->size--;
}

//打印

void SeqListPrint(const SeqList *seqlist){
	for (int i = 0; i < seqlist->size; i++){
		printf("%d ", seqlist->array[i]);
	} 
	printf("\n");
}


//修改pos 所在下标的所在数据为 value
void SeqListModify(SeqList *seqlist, int pos, SDataType value){
	assert(pos>=0&&pos<seqlist->size);
	seqlist->array[pos] = value;
}
//查找
//如果找到，返回第一个找到的下标
//如果没找到返回-1
int SeqListFind(const SeqList *seqlist, SDataType value){
	assert(seqlist!=NULL);
	for (int i - 0; i < seqlist->size;i++){
		if (seqlist->array[i] == value)
			return i;
	}
	return -1;
}
//找到并删除第一个遇到的 value
void  SeqListRemove(SeqList *seqlist, SDataType value){
	int pos = SeqListFind(sqlist,value);
	if (pos != -1){
		SeqListErase(seqlist,pos);
	}
}

//判断顺序表是否为空，
bool SeqListEmpty(const SeqList *seqlist){
	return seqlist->size == 0;
}
//返回数据个数
int SeqListSize(const SeqList *seqlist){
	return seqlist->size;
}