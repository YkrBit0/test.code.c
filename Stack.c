#include "Stack.h"


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
		STDateType* tmp = realloc(ps->a, sizeof(STDateType)*newCapcaity);
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
	/*
	if (ps->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return ps->top == 0;
}

