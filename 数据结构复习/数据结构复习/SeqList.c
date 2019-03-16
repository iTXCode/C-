#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"
#include<assert.h>

//����
//���� size=capacity;

static void CheckCapccity(SeqList *seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size <= seqlist->capacity);
	if (seqlist->size < seqlist->capacity){
		return;
	}
	//�ߵ������Ҫ����
	int capacity = 2 * seqlist->capacity;
	SDataType *array = (SDataType *)malloc(sizeof(SDataType)*capacity);
	assert(array);
	//�������ݰ����
	for (int i = 0; i < seqlist->capacity; i++){
		array[i] = seqlist->array[i];
	}
	//�ͷ��Ͽռ�
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
	free(seqlist->array);   //�ص�
}
//β��
void SeqListPushBack(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);


	CheckCapccity(seqlist);
	seqlist->array[seqlist->size] = value;
	seqlist->size++;
}


//ͷ��
void SeqListPushFront(SeqList *seqlist, SDataType value){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	CheckCapccity(seqlist);
		//�����ݵİ��ƣ�i����ռ��±�
	for (int i = seqlist->size ; i > 0; i--){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = value;
	seqlist->size++;
}
//�м����
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

//βɾ
void SeqListPopBack(SeqList*seqlist){
	assert(seqlist!=NULL);
	assert(seqlist->array!=NULL);
	assert(seqlist->size > 0);
	seqlist->size--;
}


//ͷɾ
//1.�Ӻ���ǰ�ᣬ���⸲��
//2.дѭ��
//       ��ȷ��ѭ���ı߽�
//       i �ռ��±�   [0,size-2]
//       i �����±�   [1,size-1]
//3. ����  
//    i��Ӧ�ռ��±꣺    array[i-1]=array[i];
//    i��Ӧ�����±꣺    array[i]=array[i+1];
void SeqListPopFront(SeqList* seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	for (int i = 1; i <seqlist->size ; i++){
		seqlist->array[i - 1] = seqlist->array[i];
	}
	seqlist->size--;
}

//ɾ�� pos ���ڵ��±�����
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

//��ӡ

void SeqListPrint(const SeqList *seqlist){
	for (int i = 0; i < seqlist->size; i++){
		printf("%d ", seqlist->array[i]);
	} 
	printf("\n");
}


//�޸�pos �����±����������Ϊ value
void SeqListModify(SeqList *seqlist, int pos, SDataType value){
	assert(pos>=0&&pos<seqlist->size);
	seqlist->array[pos] = value;
}
//����
//����ҵ������ص�һ���ҵ����±�
//���û�ҵ�����-1
int SeqListFind(const SeqList *seqlist, SDataType value){
	assert(seqlist!=NULL);
	for (int i = 0; i < seqlist->size;i++){
		if (seqlist->array[i] == value)
			return i;
	}
	return -1;
}
//�ҵ���ɾ����һ�������� value
void  SeqListRemove(SeqList *seqlist, SDataType value){
	int pos = SeqListFind(seqlist,value);
	if (pos != -1){
		SeqListErase(seqlist,pos);
	}
}

//�ж�˳����Ƿ�Ϊ�գ�
bool SeqListEmpty(const SeqList *seqlist){
	return seqlist->size == 0;
}
//�������ݸ���
int SeqListSize(const SeqList *seqlist){
	return seqlist->size;
}

//ð������

void Swap(int *ptr1, int *ptr2){
	int swap = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = swap;
}
//ð������
void SeqListBubbleSort(SeqList * seqlist){
	int flag = 1;
	for (int i = 0; i<seqlist->size - 1; i++){
		//һ��ð�ݹ���
		for (int j = 0; j<seqlist->size - 1 - i; j++){
			if (seqlist->array[j]>seqlist->array[j + 1]){
				Swap(seqlist->array[j], seqlist->array[j + 1]);
				flag = 0;
			}
			//һ��ð�ݽ���
			if (flag == 1)
				break;
		}
}

	//���ֲ���
	int SeqListBinarySort(SeqList *seqlist, SDataType value) {
		int left = 0;
		int right = seqlist->size;
		while (left < right){
			//���left<= righ �Ļ������ [3,3)���������
			int mid = (left - right) / 2 + left;
			if (seqlist->array[mid] == value){
				return mid;
			}
			else if (value <seqlist->array[mid]){
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		//û�ҵ�
		return -1;
}
