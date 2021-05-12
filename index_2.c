#include <stdio.h>
#include <math.h>

/*
int main()
{
	int arr[10] = { 0 };
	int* p = &arr;
	int i = 0;
	int j = 0;
	for (i = 0; i <9; i++)
	{
		*(p + i) = 1;
	}

	for (j = 0; j < 9; j++)
	{
		printf("%d\n", arr[j]);
	}

	return 0;
}
*/

/*
int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			int c = i * j;
			printf("%d * %d = %2d  " , j, i, c);
		}
		printf("\n");
	}

}
*/

/*
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int* p = arr;
	for (i = 0; i <= 9; i++)
	{
		*p++ = i;
	}

	int j = 0;
	for(j = 0;j <= 9;j++)
	{
		printf("%d\n", arr[j]);
	}

	return 0;

}
*/

int* my_strlen(char* ch)
{
	char* chr = ch;
	char* end = ch;
	while (*end != '\0')
	{
		end++;
	}
	return end - chr;
}
/*
int main()
{
	int arr[10] = { 1,2,3,5,6,7,8,9,10 };
	int a = &arr[9] - &arr[0];
	printf("%d\n", a);
	char ch[] = "bit";
	int b = my_strlen(ch);
	printf("%d\n", b);
}
*/

/*
int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	int j = 0;
	for (j = 0; j < 10; j++)
	{
		printf("%d\n", arr[j]);
	}

	return 0;
}
*/

//Ã°ÅİÅÅĞò---½µĞò
/*
int main()
{
	int arr[10] = { 1,5,6,78,9,5,3,6,12,8 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int item = 0;
				item = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = item;

			}
		}

	}

	int k = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (k = 0; k < sz; k++)
	{
		printf("%d\n", arr[k]);
	}

	return 0;

}
*/


//Ã°ÅİÅÅĞò--- ½µĞò

void set_rank(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int item = 0;
				item = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = item;

			}
		}

	}
}

//Ã°ÅİÅÅĞò---ÉıĞò
void set_sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{

			if (arr[j] < arr[j + 1])
			{
				int item = 0;
				item = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = item;
			}
		}

	}

}

int main()
{
	int arr[10] = { 1,5,3,2,6,4,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", sz);
	set_sort(arr, sz);
	//set_rank(arr, sz);
	int k = 0;
	for (k = 0; k < sz; k++)
	{
		printf("%d\n", arr[k]);
	}
	return 0;
}






/*
int main()
{
	int arr[10] = { 1,5,6,47,8,9,5,6,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	test(arr, sz);
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		printf("%d\n", arr[i]);

	}

	return 0;
}

int test(int arr[], int sz)
{
	int a = 0;
	for (a = 0; a < sz; a++)
	{
		printf("%d\n", arr[a]);
	}
}
*/
