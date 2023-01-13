#include "List.h"
//³õÊ¼»¯
LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//´òÓ¡
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;

	}
	printf("\n");
}

//Î²²å
void ListPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));

	newnode->data = x;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

//Î²É¾
void ListPopBack(LTNode* phead)
{
	assert(phead);
	/*LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	tailprev->next = phead;
	phead->prev = tailprev;
	free(tail);*/
	LTNode* newtail = phead->prev->prev;
	free(phead->prev);
	newtail->next = phead;
	phead->prev = newtail;
	

}