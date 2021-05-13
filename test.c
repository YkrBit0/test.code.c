#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#define Row 3
#define Col 3
int main()
{
	char arr[Row][Col] = {0};
	int i = 0;
	int j = 0;
	int k = 0;
	//初始化数组
	for (i = 0; i < Row; i++)
	{
		for (j = 0; j < Col;j++)
		{
			arr[i][j] = '0';
		}
	}
	/*
	for (i = 0; i < Row; i++)
	{
		for (j = 0; j < Col; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	*/

	//Disarr(arr, Row, Col);

	//打印
	for (i = 0; i < Row; i++)
	{
		for (j = 0; j < Col; j++)
		{
			printf(" %c ",arr[i][j]);
			if (j < Col - 1)
				printf("|");
		}
		printf("\n");
		
		if(i <Row-1 )
		{
			for (k = 0; k < Col; k++)
			{
				printf("---");
				if (k < Col - 1)
					printf("|");
			}
			
		}
		printf("\n");
	}

	return 0;
}

/*
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");

		}
		printf("\n");

		if (i < row - 1)
		{
			for (k = 0; k < col; k++)
			{
				printf("---");
				if (k < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

*/

//打印
/*
void Disarr(char arr[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ",arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		if (i < row - 1)
		{
			for (k = 0; k < col; k++)
			{
				printf("---");
				if (k < col - 1)
					printf("|");
			}

		}

	}

}
*/









