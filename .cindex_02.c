#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>

int i;
void siz(int i)
{
	i--;
	if (i > sizeof(i)) //sizeof���������������ռ�ڴ�Ĵ�С>=0�޷�����
	{
		printf(">\n");
	}
	else 
	{
		printf("<\n");

	}
	
}

/*
int main()
{
	int arr[] = { 1,2,3,4,5 };
	//ǿ������װ��
	short* p = (short*)arr; //short*��ָ����������ֽ�
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		*(p + i) = 0;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}

	int a = 0x11223344;
	char* pc = (char*)&a; //���������ֽ�

	*pc = 0;
	printf("%x\n", a);
	//siz(i);
	return 0;

}
*/

//�㷨1
int count_bit_one(unsigned int n)
{
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n = n / 2;
	}
	return count;

}

//�㷨2
int count1_bit_one(int n)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if (((n >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}
//n = n&(n-1)
//n 13
//1101 n
//1100 n-1
//1100

//�㷨3
int count1_bit_one3(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}




//��������в�ͬλ�ĸ���
int get_diff_bit(int n, int m)
{
	int tmp = m ^ n;   //��λ��
	return count1_bit_one3(tmp);
}

//��������е�����λ��ż��λ

void get_rint(int n)
{
	int i = 0;
	printf("����λ\n");
	for (i = 30; i >= 0; i -= 2)
	{
		
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	printf("ż��λ\n");
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
}


int main()
{
	int a = 3;
	int b = 5;
	
	//��λ���----������������ͬ���Ϊ0����ͬ��Ϊ1
	int c = a ^ b;
	printf("c = %d\n", c);
	

	//��λ��---������������Ϊ1�������Ϊ1
	int e = a & b;
	printf("e = %d\n", e);
	//��λ��------����������Ϊ0��Ϊ0
	int i = a | b;
	printf("i = %d\n", i);
	return 0;
}

/*
int main()
{
	
	int n = 0;
	int m = 0;
	printf("������������:");
	scanf("%d%d", &n,&m);
	int count = get_diff_bit(n,m);
	printf("������������:");
	printf("count = %d\n", count);
	
	int count = 0;
	int n = 0;
	printf("������������:");
	scanf("%d", &n);

	get_rint(n);
	
	return 0;

}
*/


/*
int main()
{
	int a = 0;
	printf("����һ������:");
	scanf("%d", &a);

	//дһ������������ƣ����룩��ʾ�е�1�ĸ���
	int count = count_bit_one(a);
	//13
	//00000000000000000000000000001101 ---Դ��
	// 
	//-1
	//10000000000000000000000000000001 ---Դ��
	//11111111111111111111111111111110 ---����+1
	//11111111111111111111111111111111 ---����
	printf("count == %d\n", count);

	int count1 = count1_bit_one(a);
	printf("count1 == %d\n", count1);

	int count3 = count1_bit_one3(a);
	printf("count3 == %d\n", count3);

	//system("pause"��;//system -- �⺯��-ִ������pause(��ͣ)
	return 0;

}
*/


/*
int count1_bit_one3(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return 0;
}
*/



int index(int i, int j)
{
	int re = 0;
	re = i & j;
	printf("%d\n", re);

}








