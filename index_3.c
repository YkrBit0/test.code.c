#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
void my_strcpy1(char* dest, const char* src)  //const  防止dest和src输入相反  const修饰的数值不能改
{
	assert(dest != NULL);  //断言
	assert(src != NULL);

	while (*dest++ = *src++)
	{
		;
	}

}

int main()
{
	char arr1[] = "###";
	char arr2[] = "bit";
	my_strcpy1(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
*/


/*
int main()
{
	char input[20] = {0};

	system("shutdown -s -t 60");

again:
	printf("电脑将在1分钟后关机，请确认no-or-yes\n");
	printf("请输入:");
	scanf("%s",input);
	if (strcmp(input,"no") == 0)
	{ 
		system("shutdown -a");
	}	
	else
	{
		goto again;
	}
	
	return 0;
}
*/


int main()
{
	const int num = 10;  //const 修饰的数值原则上不能改，
	//int* p = &num;
	//*p = 20;             //指针可非法修改
	//const int* p = &num;   //限制p的权限  const 放在指针变量*左边，修饰的是*p，
	//*p = 20;               //报错
	int* const p = &num;
	*p = 20;
	int n = 100;
	//p = &n;
	printf("%d", num);

	return 0;
}







