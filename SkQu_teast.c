#include "Stack.h"

void Test()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	while (!StackEmpty(&st))
	{
		printf("%d  ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");
}


//int main()
//{
//	Test();
//	return 0;
//}