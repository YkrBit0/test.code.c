

#include <stdio.h>

void test()
{
	printf("hehe\n");
}

void test1()
{
	int a = 10; 
	int n = 0;
	float f = 10;
	printf("%d,%lf\n", a, f);
	test();

	n = Fibt(5);
	printf("%d", n);


	
}

//�ݹ�
int Fibt(int n)
{
	if (n <= 2)
		return 1;
	else
		return Fibt(n - 1) + Fibt(n - 2);
}

typedef struct student
{
	char name[20];
	short age;
	char sex[10];
	int num;
	
}Sut;

Sut sut[20];
int num = 10;

//���ݴ洢
void data()
{
	FILE* fp;
	int i = 0;
	if ((fp = open("data.txt", "wb")) == NULL)
	{
		printf("�ļ���ʧ��\n");
		system("pause");
	}

	else
	{
		printf("�ļ��򿪳ɹ�\n");

	}
	for (i = 0; i < num; i++)
	{
		fwrite(&sut[i], sizeof(struct student), 1, fp);
	}
}
/*
void Save_File()
{
	FILE* fp;
	int i;
	if ((fp = fopen("dormitory.txt", "wb")) == NULL)
	{
		printf("�ļ���ʧ��!");
		system("pause");
		return;
	}
	for (i = 0; i < NUM; i++)
	{
		fwrite(&dorm[i], sizeof(struct dormitory), 1, fp);
	}
	fclose(fp);
}


void Open_File()
{
	int i = 0;
	FILE* fp;
	if ((fp = fopen("dormitory.txt", "rb")) == NULL)
	{
		;
	}
	else
	{
		while (fread(&dorm[i], sizeof(struct dormitory), 1, fp))
		{
			i++;
			NUM++;
		}
		fclose(fp);
		printf("�ļ����ݶ�ȡ�ɹ���\n");
		system("pause");
	}
}

*/










