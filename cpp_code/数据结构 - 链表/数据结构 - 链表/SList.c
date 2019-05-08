#include"SList.h"

//初始化
void SListInit(SList*list){
	assert(list!= NULL);
	list->first = NULL;
}

//销毁过程
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
//头插
void SListPushFront(SList *list, SLDataType value){
	assert(list!=NULL);
	SLNode *node = (SLNode*)malloc(sizeof(SLNode));
	assert(node);
	node->value = value;
	node->next = list->first;
	list->first = node;
}
//尾插
void SListpushBack(SList *list, SLDataType value){
	assert(list != NULL);
	if (list->first == NULL){
		//链表中没有结点,调用头插法
		SListPushFront(list,value);
		return;
	}
    //链表中有节点的情况
	//找链表中的最后一个节点
	SLNode *ptr;
	for (ptr = list->first; ptr->next != NULL; ptr = ptr->next){

	}
	//ptr就是最后一个节点
	SLNode *new_node = (SLNode*)malloc(sizeof(SLNode));
	ptr->next = new_node;
	new_node->value = value;
	new_node->next = NULL;
}

//头删
void SListPopFront(SList *list){
	assert(list != NULL);       //保证链表是有的
	assert(list->first!=NULL);   //保证链表不为空
	SLNode *old_first = list->first;  //拷贝原来的空间，防止丢失。
	list->first = list->first->next;
	free(old_first);//释放老空间
}
//尾删
void SListPopBack(SList *list){
	assert(list != NULL);       //保证链表是有的
	assert(list->first != NULL);   //保证链表不为空
	//自己的想法
	/*SLNode *ret;
	for (ret = list->first; ret->next->next != NULL; ret= ret->next){
	}
	SLNode *cur = ret->next;
	ret->next = NULL;
	free(cur);*/
	//如果只有一个节结点
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

//打印
void SListPrint(SList *list){
	for (SLNode *cur = list->first; cur != NULL; cur = cur->next){
		printf("%d--> ",cur->value);
	}
	printf("NULL\n");
}

