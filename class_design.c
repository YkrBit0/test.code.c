#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define max_num 6
#define max_room 100
typedef struct Student
{
	int num;//学号
	int class_num;//班级
	char name[20];//姓名
	char depart[20];//系

}Stu;
typedef struct room
{
	int num;//宿舍号
	int room;//房间号
	int count;//人数
	Stu sut[max_num];
}Su;

Su arr[max_room]; //结构体数组
int num = 0;  //已录入的宿舍数

//宿舍信息录入
Su add_new_room()
{
	int i = 0;
	system("cls");
	printf("请输入新加的宿舍号\n");
	scanf("%d", &arr[max_room].num);
	printf("请输入新加的房间号\n");
	scanf("%d", &arr[max_room].room);
	printf("请输入新加宿舍的入住学生人数\n");
	scanf("%d", &arr[max_room].count);
	while (arr[max_room].count<0 || arr[max_room].count>max_num)
	{
		printf("数据输入错误请重新输入\n");
		scanf("%d", &arr[max_room].count);
	}

	for (i = 1; i <= arr[max_room].count; i++)
	{
		printf("请输入第%d个学生的学号\n",i);
		scanf("%d", &arr[max_room].sut[i].num);
		printf("请输入第%d个学生的班级\n",i);
		scanf("%d", &arr[max_room].sut[i].class_num);
		printf("请输入第%d个学生的姓名\n",i);
		scanf("%s", &arr[max_room].sut[i].name);
		printf("请输入第%d个学生的所在的糸\n",i);
		scanf("%s", &arr[max_room].sut[i].depart);
	}
	printf("新增宿舍信息成功\n");
	num++;
	//system("pause");
	return arr[max_room];
}

//宿舍号查找学生信息
int find_room(Su*p)
{
	int i = 0;
	int j = 0;
	int flag = 1;
	int n = 0;
	system("cls");
	printf("请输入要查找的宿舍号\n");
	scanf("%d", &n);
	for (i = 0; i < num; i++)
	{
		if (n == arr[max_room].num)
		{
			flag = 0;
			break;
		}

	}
	if (flag)
	{
		printf("没有找到宿舍号\n");
	}
	else
	{
		printf("宿舍号:%d  房间号:%d 入住人数%d\n", arr[n].num, arr[n].room, arr[n].count);
		for (j = 0; j < arr[n].count; j++)
		{
			printf("学号：%d,班级:%d,姓名:%s,糸:%d\n", arr[n].sut[j].num, arr[n].sut[j].class_num, arr[n].sut[j].name, arr[n].sut[j].depart);
		}

	}
	system("cls");

}

int menu()
{
	int n = 0;
	system("cls");
	printf("1:宿舍信息录入\n");
	printf("2:宿舍信息查询\n");
	printf("3:宿舍信息显示\n");
	printf("4:宿舍信息修改\n");
	printf("5:宿舍信息删除\n");
	printf("6:宿舍信息分析\n");
	printf("0:退出\n");
	printf("请输入你要执行的内容：");
	scanf("%d",&n);
	while (n < 0 || n>6)
	{
		printf("输入错误，请重新输入：");
		scanf("%d",&n);
	}
	return n;

}


//system("pause")----停止代码


int main()
{
	int n;
	n = menu();
	switch(n)
	{
		case 1: add_new_room();
		case 2:find_room(add_new_room);
			break;
	}
	return 0;
}

