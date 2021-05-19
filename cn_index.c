#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>

#define num 10

//定义结构体1
struct Per
{
	char name[20];
	short age;
	char sex[5];

};



//定义结构体2
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

//输入函数
void input()
{
	int i = 0;
	system("cls");
	printf("请输入学校名:");
	scanf("%s\n", &sl[num].name);
	printf("请输入学校地址：");
	scanf("%s\n", &sl[num].address);
	printf("请输入学校编码：");
	scanf("%d\n", &sl[num].tele);
	for (i = 0; i < 10; i++)
	{
		printf("请输入学生姓名：");
		scanf("%s\n", &sl[num].tu->name);
		printf("请输入学生年龄：");
		scanf("%d\n", &sl[num].tu->age);
		printf("请输入学生号码：");
		scanf("%s\n", &sl[num].tu->tele);
		printf("请输入学生性别：");
		scanf("%s\n", &sl[num].tu->sex);
	}
	printf("录入完毕\n");
	system("puse");
}

/*
void input1()
{
	printf("请输入学校名:");
	scanf("%s\n", &sl[num].name);
	printf("请输入学校地址：");
	scanf("%s\n", &sl[num].address);
	printf("请输入学校编码：");
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
	printf("请输入学校名：");
	scanf("%s\n",&n);
	printf("请输入学生姓名：");
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
		printf("学校名：%s\n", sl[i].name);
		printf("学生名：%s\n", sl[i].tu->age);
		printf("学生年龄:%d\n", sl[i].tu->age);
		printf("学生号码:%s\n", sl[i].tu->tele);
		printf("学生性别:%s\n", sl[i].tu->sex);
	}
	else if(flag == 2)
	{
		printf("这个学校没有这个学生\n");
	}
	else if(flag == 3)
	{
		printf("没有这个学校\n");
	}
	else
	{
		printf("没有这个学校和学生\n");
	}

}

int menu()
{
	int i = 0;
	while (i)
	{
		system("cls");
		printf("请选择>>:");
		printf("0:退出\n");
		printf("1:录入学生信息\n");
		printf("2：查询学生信息\n");
		printf("3:查询学校信息\n");
		printf("4:录入学校信息\n");
		printf("0:退出\n"); 
		scanf("%d", &i);
		while (i < 0 || i>5)
		{
			ptintf("输入错误,请重新输入:");
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
	printf("请输入学生姓名：");
	scanf("%s", &t.name);
	printf("请输入学生年龄：");
	scanf("%d", &s.age);
	printf("请输入学生号码：");
	scanf("%s", &s.tele);
	printf("请输入学生性别：");
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
	Shol l = { "理工大学","上海",1234001,s };

	return 0;
}