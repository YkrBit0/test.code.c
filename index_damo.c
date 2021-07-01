#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



char* my_strcpy3(char* dest, const char* src)  //const  防止dest和src输入相反  const修饰的数值不能改
{
	char* ret = dest;        //保存起始地址
	assert(dest != NULL);  //断言
	assert(src != NULL);

	while (*dest++ = *src++)
	{
		;
	}
	return ret;



}

/*
int main()
{
	char arr1[] = "#######";
	char arr2[] = "bit";
	printf("%s\n",my_strcpy3(arr1, arr2));
	return 0;
}

*/



//实现strlen


my_strlen(char* str)
{
	int count = 0;
	assert(str != NULL);
	while (*str != '\0') 
	{
		count++;
		str++;

	}
	return count;
}

int main()
{
	char arr[] = "abcdefg";
	int len = my_strlen(arr);
	printf("%d", len);

	return 0;
}








































