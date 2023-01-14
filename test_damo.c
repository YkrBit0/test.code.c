
/*
#include "List.h"

//头删
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != NULL);
	LTNode* tail = phead->next->next;
	free(phead->next);
	phead->next = tail;
	tail->prev = phead;
}

LTNode* ListFind(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


//pos位置前插入
void ListInsert(LTNode* pos, LTDateType x)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* newnode = BuyListNode(x);
	posPrev->next = newnode;
	newnode->prev = posPrev;
	pos->prev = newnode;
	newnode->next = pos;
}


//删除pos位置
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
}

*/




