#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define max_num 6
#define max_room 100
typedef struct Student
{
	int num;//ѧ��
	int class_num;//�༶
	char name[20];//����
	char depart[20];//ϵ

}Stu;
typedef struct room
{
	int num;//�����
	int room;//�����
	int count;//����
	Stu sut[max_num];
}Su;

Su arr[max_room]; //�ṹ������
int num = 0;  //��¼���������

//������Ϣ¼��
Su add_new_room()
{
	int i = 0;
	system("cls");
	printf("�������¼ӵ������\n");
	scanf("%d", &arr[max_room].num);
	printf("�������¼ӵķ����\n");
	scanf("%d", &arr[max_room].room);
	printf("�������¼��������סѧ������\n");
	scanf("%d", &arr[max_room].count);
	while (arr[max_room].count<0 || arr[max_room].count>max_num)
	{
		printf("���������������������\n");
		scanf("%d", &arr[max_room].count);
	}

	for (i = 1; i <= arr[max_room].count; i++)
	{
		printf("�������%d��ѧ����ѧ��\n",i);
		scanf("%d", &arr[max_room].sut[i].num);
		printf("�������%d��ѧ���İ༶\n",i);
		scanf("%d", &arr[max_room].sut[i].class_num);
		printf("�������%d��ѧ��������\n",i);
		scanf("%s", &arr[max_room].sut[i].name);
		printf("�������%d��ѧ�������ڵ���\n",i);
		scanf("%s", &arr[max_room].sut[i].depart);
	}
	printf("����������Ϣ�ɹ�\n");
	num++;
	//system("pause");
	return arr[max_room];
}

//����Ų���ѧ����Ϣ
int find_room(Su*p)
{
	int i = 0;
	int j = 0;
	int flag = 1;
	int n = 0;
	system("cls");
	printf("������Ҫ���ҵ������\n");
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
		printf("û���ҵ������\n");
	}
	else
	{
		printf("�����:%d  �����:%d ��ס����%d\n", arr[n].num, arr[n].room, arr[n].count);
		for (j = 0; j < arr[n].count; j++)
		{
			printf("ѧ�ţ�%d,�༶:%d,����:%s,��:%d\n", arr[n].sut[j].num, arr[n].sut[j].class_num, arr[n].sut[j].name, arr[n].sut[j].depart);
		}

	}
	system("cls");

}

int menu()
{
	int n = 0;
	system("cls");
	printf("1:������Ϣ¼��\n");
	printf("2:������Ϣ��ѯ\n");
	printf("3:������Ϣ��ʾ\n");
	printf("4:������Ϣ�޸�\n");
	printf("5:������Ϣɾ��\n");
	printf("6:������Ϣ����\n");
	printf("0:�˳�\n");
	printf("��������Ҫִ�е����ݣ�");
	scanf("%d",&n);
	while (n < 0 || n>6)
	{
		printf("����������������룺");
		scanf("%d",&n);
	}
	return n;

}


//system("pause")----ֹͣ����


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

