#define _CRT_SECURE_NO_WARNINGS 1 
#include"stdio.h"
#include"math.h"


/*
int cinvertBinarytoDecimal(long n)
{
	int decimalNumber = 0, i = 0, remainder;
	while (n != 0)
	{
		remainder = n % 10;	
		n = n /10;
		decimalNumber += remainder * pow(2, i);
		++i;
	}  
	return decimalNumber;
}
*/

/*
int cout(long n)
{
	int i = 0;
	int count = 0;
	int din = 0;
	for (i = 31; i>=0; i--)
	{
		int k = 0;

		k = ((n >> i) & 1);
		
		din += k*(pow(2,count));

		count++;

		printf("%d", k);

	}
	return din;
	
}
*/



/*
long convertDecimalToBinary(int n)
{
	long binaryNumber = 0;
	int remainder, i = 1, step = 1;

	while (n != 0)
	{
		remainder = n % 2;
		printf("Step %d;%d/2,���� = %d,�� = %d\n", step++, n, remainder, n / 2);
		n /= 2;
		binaryNumber += remainder * i;
		i *= 10;
	}

	return binaryNumber;
}


#define _CRT_SECURE_NO_WARNINGS 1 
#include"stdio.h"
#include"math.h"

int coubtit(long n)
{
	int num = 0;
	int bit = 0;
	int count = 0;
	int kit = 0;
	while (n)
	{
		num = n % 10;
		n = n / 10;
		count++;
		kit += num * pow(2, count-1);
	}
	
	return kit;
}

int count3_bit_one(int n)
{
	int i = 0;
	int count = 0;
	for (i = 31; i >=0; i--)
	{
		int j = 0;
		j = ((n >> i) & 1);
		printf("%d", j);
	}

}

int main()
{
	//int cmm, n;
	int cmm = 0;
	int n = 0;

	long m;
	printf("******������תʮ�������Ļ���ת��******\n");
	printf("��ѡ����:[������תʮ��������1]|[ʮ����ת����������2]|[�˳�����3]");
	while (cmm != 3)
	{
		printf("�����빦�ܰ���");
		scanf("%d", &cmm);
		switch (cmm)
		{
		case 1:
			printf("\n����һ����������:");
			scanf("%ld", &n);
			printf("��������%dת��Ϊʮ����λ:",n);
			int k = coubtit(n);
			printf("%d",k);
			break;
		case 2:
			printf("\n����һ��ʮ������:");
			scanf("%d", &n);
			printf("ʮ������%dת��Ϊ������λ",n);
			count3_bit_one(n);
			break;
		}
	}

	return 0;

}
*/



