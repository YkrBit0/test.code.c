#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>



int get_strlen(char* arr)
{
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;

	}
	return count;
}

//µÝ¹é
void reverse_str(char* arr)
{
	char tmp = arr[0];
	int len = get_strlen(arr);
	arr[0] = arr[len - 1];
	arr[len - 1] = '\0';
	if (get_strlen(arr + 1) >= 2)
		reverse_str(arr + 1);
	arr[len - 1] = tmp;

}

int Digitsum(unsigned int num)
{
	if (num > 9)
	{
		return Digitsum(num / 10) + num % 10;
	}
	else
	{
		return num;
	}

}


void reverse(char arr[])
{
	int len = get_strlen(arr);
	int left = 0;
	int right = len - 1;
	while (right > left)
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		right--;
		left++;
	}

}

double Pow(int n, int k)
{
	if (k < 0)
	{
		return (1 /(Pow(n, -k)));
	}
	else if (k == 0)
	{
		return 1;
	}
	else
	{
		return n * Pow(n, k - 1);
	}
}

int main()
{

	int n = 0;
	int k = 0;
	printf("Ç×ÊäÈë:");
	scanf("%d%d", &n, &k);
	double ret = Pow(n, k);
	printf("%lf\n", ret);
	return 0;
}



/*
int main()
{
	char str[] = "abcde";
	int len = get_strlen(str);
	printf("%d\n", len);
	reverse(str);
	printf("%s\n", str);
	int n = 0;
	printf("ÇëÊäÈë:");
	scanf("%d", &n);
	int ret = Digitsum(n);
	printf("%d\n", ret);
	int a = 0;
	for (a = 0; a < 10; a++)
	{
		printf("%d ", a);
	}

	return 0;
}
*/



