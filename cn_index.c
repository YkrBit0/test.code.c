#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>

#define num 10

//����ṹ��1
struct Per
{
	char name[20];
	short age;
	char sex[5];

};



//����ṹ��2
typedef struct Stu
{
	char name[20];
	short age;
	char tele[20];
	char sex[5];

}Stu;

typedef struct Shol
{
	char name[20];
	char address[10];
	int tele;
	Stu tu[10];
}Shol;

Shol sl[num];

//���뺯��
void input()
{
	int i = 0;
	system("cls");
	printf("������ѧУ��:");
	scanf("%s\n", &sl[num].name);
	printf("������ѧУ��ַ��");
	scanf("%s\n", &sl[num].address);
	printf("������ѧУ���룺");
	scanf("%d\n", &sl[num].tele);
	for (i = 0; i < 10; i++)
	{
		printf("������ѧ��������");
		scanf("%s\n", &sl[num].tu->name);
		printf("������ѧ�����䣺");
		scanf("%d\n", &sl[num].tu->age);
		printf("������ѧ�����룺");
		scanf("%s\n", &sl[num].tu->tele);
		printf("������ѧ���Ա�");
		scanf("%s\n", &sl[num].tu->sex);
	}
	printf("¼�����\n");
	system("puse");
}

/*
void input1()
{
	printf("������ѧУ��:");
	scanf("%s\n", &sl[num].name);
	printf("������ѧУ��ַ��");
	scanf("%s\n", &sl[num].address);
	printf("������ѧУ���룺");
	scanf("%d", &sl[num].tele);

}
*/


void find_stu()
{
	int i = 0;
	int j = 0;
	char n[20];
	char ne[20];
	int flag = 0;
	printf("������ѧУ����");
	scanf("%s\n",&n);
	printf("������ѧ��������");
	scanf("%s\n", &ne);
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((n == sl[i].name)&&(ne==sl[i].tu->name))
			{
				flag = 1;
				break;
				
			}
			else if((n == sl[i].name)&&(ne!=sl[i].tu->name))
			{
				flag = 2;
				break;

			}
			else if((n != sl[i].name) && (ne == sl[i].tu->name))
			{
				flag = 3;
				break;
			}

		if ((flag == 1)||(flag==2)||(flag==3))
		{
			break;

		}


		}

	}
	if (flag == 1)
	{
		printf("ѧУ����%s\n", sl[i].name);
		printf("ѧ������%s\n", sl[i].tu->age);
		printf("ѧ������:%d\n", sl[i].tu->age);
		printf("ѧ������:%s\n", sl[i].tu->tele);
		printf("ѧ���Ա�:%s\n", sl[i].tu->sex);
	}
	else if(flag == 2)
	{
		printf("���ѧУû�����ѧ��\n");
	}
	else if(flag == 3)
	{
		printf("û�����ѧУ\n");
	}
	else
	{
		printf("û�����ѧУ��ѧ��\n");
	}

}

int menu()
{
	int i = 0;
	while (i)
	{
		system("cls");
		printf("��ѡ��>>:");
		printf("0:�˳�\n");
		printf("1:¼��ѧ����Ϣ\n");
		printf("2����ѯѧ����Ϣ\n");
		printf("3:��ѯѧУ��Ϣ\n");
		printf("4:¼��ѧУ��Ϣ\n");
		printf("0:�˳�\n"); 
		scanf("%d", &i);
		while (i < 0 || i>5)
		{
			ptintf("�������,����������:");
			scanf("%d", &i);
		}


	}
	
	
}


















void stu_print1(Stu tmp)
{
	printf("name:%s\n", tmp.name);
	printf("age:%d\n", tmp.age);
	printf("tele:%d\n", tmp.tele);
	printf("sex:%s\n", tmp.sex);
}


void stu_print(Stu* pc)
{

	printf("name:%s\n", pc->name);
	printf("age:%d\n", pc->age);
	printf("tele:%d\n", pc->tele);
	printf("sex:%s\n", pc->sex);
}

/*
void input()
{
	printf("������ѧ��������");
	scanf("%s", &t.name);
	printf("������ѧ�����䣺");
	scanf("%d", &s.age);
	printf("������ѧ�����룺");
	scanf("%s", &s.tele);
	printf("������ѧ���Ա�");
	scanf("%s", &s.sex);
}
*/


int main()
{
	struct Per p = { "lkij",22,"FM" };
	printf("%s\n", p.name);
	printf("%d\n", p.age);
	Stu s = { "lijn",21,"1234567789","FM" };
	stu_print(&s);
	stu_print1(s);
	Shol l = { "����ѧ","�Ϻ�",1234001,s };

	return 0;
}