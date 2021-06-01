#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"




/*
int Fac(int n)
{
	if (n == 1)
		return 1;
	else
		return n * Fac(n - 1);
}

int Fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}
*/
/*
int main()
{
	int ret = 0;
	int ib = 0;
	int n = 0;
	printf("请输入：");
	scanf("%d", &n);
	ret = Fac(n);
	ib = Fib(n);

	printf("%d\n", ret);
	printf("%d\n", ib);

}
*/

/*
struct Animal
{
	char name[20];
	short age;
	char sex[20];
	char type[20];
};

int main()
{
	struct Animal dog = {"mjj",2,"W","二哈" };
	//printf("%s\n", dog.name);
	printf("%s\n", dog.type);
}
*/

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
	while (n<0 ||(n>6))
	{
		printf("输入错误，请重新输入：");
		scanf("%d",&n);
	}
	return n;

}


int main()
{
	int ret = 0;
	ret = menu();
	printf("%d", ret);
	return 0;
}

