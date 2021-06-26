#define _CRT_SECURE_NO_WARNINGS 1 .
#include <stdio.h>
#include <assert.h>

void my_strcpy(char* dest, char* src)
{
	assert(dest != NULL);  //╤оят
	assert(src != NULL);

	while (*dest++ = *src++)
	{
		;
	}

}


int main()
{

	char arr1[] = "#############";
	char arr2[] = "bit0";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);


	int a = 10;
	int* p = NULL;
	p = &a;
	printf("%p\n", p);
	printf("%d\n", *p);

	//char a = '#';
	//char* p = &a;
	//printf("%p\n", p);
	//printf("%c\n", *p);
	//printf("%s\n", a);
	return 0;
}


/*
int main() 
{
	int a = 2;
	int b = 3;
	int c = a ^ b;
	printf("%d", c);

	return 0; 
}
*/




