#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef char STDateType;
typedef struct Stack
{
	STDateType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDateType x);
void StackPop(ST* ps);
STDateType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);

//��ʼ��
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}



void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}


//��ջ
void StackPush(ST* ps, STDateType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newCapcaity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDateType* tmp = realloc(ps->a, sizeof(STDateType) * newCapcaity);
		if (tmp == NULL)
		{
			printf("reallooc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapcaity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}


//ɾ��ջ����ֵ
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}


//ȡջ��ֵ
STDateType StackTop(ST* ps)
{
	assert(ps);
	//assert(ps->top != 0);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}


//ջ������һ��ֵ
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;

}



//�ж��Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}



bool isValid(char* s) {
	ST st;
	StackInit(&st);
	while (*s)
	{
		if (*s == '('
			|| *s == '{'
			|| *s == '[')
		{
			StackPush(&st, *s);
			++s;
		}
		else
		{
			if (StackEmpty(&st))
			{
				STDateType top = StackTop(&st);
				StackPop(&st);

				if ((*s == '}' && top != '{')
					|| (*s == ']' && top != '[')
					|| (*s == ')' && top != '('))
				{
					StackDestroy(&st);
					return false;
				}

				else
				{
					++s;
				}
			}


		}
	}
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}