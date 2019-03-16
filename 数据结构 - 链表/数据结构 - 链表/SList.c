#include"SList.h"

//��ʼ��
void SListInit(SList*list){
	assert(list!= NULL);
	list->first = NULL;
}

//���ٹ���
void SListDestory(SList *list){
	assert(list!=NULL);
	SLNode *cur = list->first;
	SLNode *next=NULL;
	while (cur != NULL){
		next = cur->next;
		free(cur);
		cur = next;
	}
	list->first = NULL;
}
//ͷ��
void SListPushFront(SList *list, SLDataType value){
	assert(list!=NULL);
	SLNode *node = (SLNode*)malloc(sizeof(SLNode));
	assert(node);
	node->value = value;
	node->next = list->first;
	list->first = node;
}
//β��
void SListpushBack(SList *list, SLDataType value){
	assert(list != NULL);
	if (list->first == NULL){
		//������û�н��,����ͷ�巨
		SListPushFront(list,value);
		return;
	}
    //�������нڵ�����
	//�������е����һ���ڵ�
	SLNode *ptr;
	for (ptr = list->first; ptr->next != NULL; ptr = ptr->next){

	}
	//ptr�������һ���ڵ�
	SLNode *new_node = (SLNode*)malloc(sizeof(SLNode));
	ptr->next = new_node;
	new_node->value = value;
	new_node->next = NULL;
}

//ͷɾ
void SListPopFront(SList *list){
	assert(list != NULL);       //��֤�������е�
	assert(list->first!=NULL);   //��֤����Ϊ��
	SLNode *old_first = list->first;  //����ԭ���Ŀռ䣬��ֹ��ʧ��
	list->first = list->first->next;
	free(old_first);//�ͷ��Ͽռ�
}
//βɾ
void SListPopBack(SList *list){
	assert(list != NULL);       //��֤�������е�
	assert(list->first != NULL);   //��֤����Ϊ��
	//�Լ����뷨
	/*SLNode *ret;
	for (ret = list->first; ret->next->next != NULL; ret= ret->next){
	}
	SLNode *cur = ret->next;
	ret->next = NULL;
	free(cur);*/
	//���ֻ��һ���ڽ��
	if (list->first->next == NULL){
		SListPopFront(list);
		return;
	}
	SLNode *ret = list->first;
	while (ret->next->next != NULL){
		ret = ret->next;
	}
	free(ret->next);
	ret->next = NULL;
}

//��ӡ
void SListPrint(SList *list){
	for (SLNode *cur = list->first; cur != NULL; cur = cur->next){
		printf("%d--> ",cur->value);
	}
	printf("NULL\n");
}

