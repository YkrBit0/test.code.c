#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



char* my_strcpy3(char* dest, const char* src)  //const  ��ֹdest��src�����෴  const���ε���ֵ���ܸ�
{
	char* ret = dest;        //������ʼ��ַ
	assert(dest != NULL);  //����
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



//ʵ��strlen


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








































