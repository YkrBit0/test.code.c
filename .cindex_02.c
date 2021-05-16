#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>

int i;
void siz(int i)
{
	i--;
	if (i > sizeof(i)) //sizeof计算变量、类型所占内存的大小>=0无符号数
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
	//强制类型装换
	short* p = (short*)arr; //short*的指针访问两个字节
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
	char* pc = (char*)&a; //访问两个字节

	*pc = 0;
	printf("%x\n", a);
	//siz(i);
	return 0;

}
*/

//算法1
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

//算法2
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

//算法3
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




//求二进制中不同位的个数
int get_diff_bit(int n, int m)
{
	int tmp = m ^ n;   //按位与
	return count1_bit_one3(tmp);
}

//求二进制中的奇数位和偶数位

void get_rint(int n)
{
	int i = 0;
	printf("奇数位\n");
	for (i = 30; i >= 0; i -= 2)
	{
		
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	printf("偶数位\n");
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
	
	//按位异或----两个操作数相同结果为0，不同则为1
	int c = a ^ b;
	printf("c = %d\n", c);
	

	//按位与---两个操作数都为1，结果才为1
	int e = a & b;
	printf("e = %d\n", e);
	//按位或------两个操作数为0才为0
	int i = a | b;
	printf("i = %d\n", i);
	return 0;
}

/*
int main()
{
	
	int n = 0;
	int m = 0;
	printf("输入两个整数:");
	scanf("%d%d", &n,&m);
	int count = get_diff_bit(n,m);
	printf("输入两个整数:");
	printf("count = %d\n", count);
	
	int count = 0;
	int n = 0;
	printf("输入两个整数:");
	scanf("%d", &n);

	get_rint(n);
	
	return 0;

}
*/


/*
int main()
{
	int a = 0;
	printf("输入一个整数:");
	scanf("%d", &a);

	//写一个函数求二进制（补码）表示中的1的个数
	int count = count_bit_one(a);
	//13
	//00000000000000000000000000001101 ---源码
	// 
	//-1
	//10000000000000000000000000000001 ---源码
	//11111111111111111111111111111110 ---反码+1
	//11111111111111111111111111111111 ---补码
	printf("count == %d\n", count);

	int count1 = count1_bit_one(a);
	printf("count1 == %d\n", count1);

	int count3 = count1_bit_one3(a);
	printf("count3 == %d\n", count3);

	//system("pause"）;//system -- 库函数-执行命令pause(暂停)
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








