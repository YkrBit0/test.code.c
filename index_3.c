#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
void my_strcpy1(char* dest, const char* src)  //const  ��ֹdest��src�����෴  const���ε���ֵ���ܸ�
{
	assert(dest != NULL);  //����
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
	printf("���Խ���1���Ӻ�ػ�����ȷ��no-or-yes\n");
	printf("������:");
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
	const int num = 10;  //const ���ε���ֵԭ���ϲ��ܸģ�
	//int* p = &num;
	//*p = 20;             //ָ��ɷǷ��޸�
	//const int* p = &num;   //����p��Ȩ��  const ����ָ�����*��ߣ����ε���*p��
	//*p = 20;               //����
	int* const p = &num;
	*p = 20;
	int n = 100;
	//p = &n;
	printf("%d", num);

	return 0;
}







