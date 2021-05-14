#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>

//打印函数
void Print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void Reverse(int arr[], int sz)
{
	int right = sz - 1;
	int left = 0;
	while (right>left)
	{
		int item = 0;
		item = arr[left];
		arr[left] = arr[right];
		arr[right] = item;
		right--;
		left++;

	}

}
// 数据交换
void swap(int arr1[],int arr2[],int sz)
{
	int item = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int swp = 0;
		swp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = swp;

	}

}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//打印
	Print(arr,sz);
	//到序
	Reverse(arr, sz);

	Print(arr, sz);

	int a[5] = { 1,2,3,4,5 };

	int b[5] = { 6,7,8,9,10 };

	int k = sizeof(a) / sizeof(a[0]);

	swap(a, b, k);

	Print(b, k);

	return 0;
}





