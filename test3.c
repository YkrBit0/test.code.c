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
	printf("�����룺");
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
	struct Animal dog = {"mjj",2,"W","����" };
	//printf("%s\n", dog.name);
	printf("%s\n", dog.type);
}
*/

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
	while (n<0 ||(n>6))
	{
		printf("����������������룺");
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

