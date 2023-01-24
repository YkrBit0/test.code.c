#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//≥ı ºªØ
LTNode* ListInit();

//¥Ú”°¡¥±Ì
void ListPrint(LTNode* phead);
//Œ≤≤Â
void ListPushBack(LTNode* phead, LTDateType x);

//Œ≤…æ
void ListPopBack(LTNode* phead);

void ListPushFront(LTNode* phead, LTDateType x);

void ListPopFront(LTNode* phead);

LTNode* ListFind(LTNode* phead, LTDateType x);


void ListInsert(LTNode* pos, LTDateType x);

void ListErase(LTNode* pos);

void ListDestroy(LTNode* phead);



