#define _CRT_SECURE_NO_WARNINGS 1

#include "game_02.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
		
	}
}


void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <=row; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %d ", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
}

//随机布置雷
void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EAsy_COUNT;
	
	while (count)
	{
		int x = rand()%row+1;
		int y = rand()%col+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}

	} 
}

//'1'-'0' == 1
//'0' - '0' ==0
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	
	return mine[x - 1][y] +
		mine[x - 1][y - 1] + 
		mine[x][y - 1] + 
		mine[x + 1][y - 1] + 
		mine[x + 1][y] +
		mine[x + 1][y + 1] + 
		mine[x][y + 1] + 
		mine[x - 1][y + 1] - 8 * '0';
}

int Findline(char mine[ROWS][COLS], int x, int y)
{
	if (mine[x][y] =='0'&&
		
		mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0' == 0)
	{

	}
	



}

void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col - EAsy_COUNT)
	{
		printf("请输入坐标排查雷>");

		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//踩雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸S了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			//非雷区
			else
			{
				//计算雷个数
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;

			}

		}
		else
		{
			printf("坐标非法,请重新输入\n");
		}
	}

	if (win == row * col - EAsy_COUNT)
	{
		printf("排雷成功\n");
		DisplayBoard(mine, row, col);
	}
}





