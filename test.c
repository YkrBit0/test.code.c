
#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"
#include "string.h"
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "add.h"









/*
int main()
{
	int a = 10;
	int b = 20;
	int sum = Add(a, b);
	printf("%d\n", sum);
	return 0;
}
*/



// 结构体
/*
struct Book
{
	char name[20];  //放入C语言程序设计
	short price; //5
};
int main()
{
	struct Book b1 = { "C语言程序设计",55 };
	printf("书名:%s\n", b1.name);
	printf("价格:%d\n", b1.price);
	b1.price = 15;
	strcpy(b1.name, "C++");
	printf("书名:%s\n", b1.name);
	printf("价格:%d\n", b1.price);
	struct Book* pb = &b1;
	printf("%s\n", (*pb).name);
	printf("%d\n", (*pb).price);
	return 0;
}
*/

/*
struct Book
{
	char name[20];
	short pice;
};
int main()
{
	struct Book b1 = { "C语言",20 };
	printf("%s", b1.name);
	return 0;
}*/


/*
int main()
{
	char arr1[] = "welcome to bit!!!!!!!";
	char arr2[] = "##################!!!";
	int left = 0;
	int right = strlen(arr1) - 1;
	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s", arr2);
		left++;
		right--;
		Sleep(1000);
		system("cls");
		//printf("%s\n", arr2);
	}
	printf("%s", arr2);
	return 0;
}


int main()
{
	char arr1[] = "welcome to it!!!!";
	char arr2[] = "##############!!!";
	int left = 0;
	int right = strlen(arr1) - 1;
	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s", arr2);
		left++;
		right--;
		Sleep(1000);
		system("cls");

	}
	printf("%s", arr2);
	return 0;
}
*/



/*
int main()
{
	char arr[] = "hello,world";
	memset(arr, "*", 5);
	printf("%s\n", arr);
	return 0;
}

int main()
{
	char arr1[] = "bit";
	char arr2[20] = "#########";
	//strcpy---- 复制字符串---交换内容
	strcpy(arr2, arr1);
	printf("%s\n", arr2);
	return 0;
}
*/







