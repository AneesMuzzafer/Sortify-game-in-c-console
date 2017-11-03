/*
 *  Sortify
 *  How fast can you sort the box?
 *
 *  (c) 2017 Anees Muzzafer
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int r = 3, c = 3;

void clrscr()
{
	system("@cls||clear");
}

void dis(int board[4][4], int no)
{
	int i, j, k;
	clrscr();
	printf("\n\n\t\t\t\t\t\t    'SORTIFY'\n\n");
	printf("\t\t\t\t\t\t   Instructions.");
	printf("\n\n\t\t\t1. You have been tasked to sort the numbers. How fast can you do it?");
	printf("\n\t\t\t2. Use arrow keys to move the numbers around.\n\t\t\t3. Press the x key to exit.");
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t");

	for (i = 0; i < 17; i++)
		printf("-");

	for (i = 0; i < 4; i++)
	{
		printf("\n\t\t\t\t\t\t");

		for (j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
				printf("|   ");
			else if (board[i][j] > 9)
				printf("| %d", board[i][j]);
			else
				printf("| %d ", board[i][j]);
		}

		printf("|\n\t\t\t\t\t\t");

		for (k = 0; k < 17; k++)
			printf("-");
	}
}

int check(int board[4][4])
{
	int i, j, temp = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (board[i][j] != 0)
			{
				if (temp > board[i][j])
					return 0;
				else
					temp = board[i][j];
			}
		}
	}

	return 1;
}

int main()
{
	int board[4][4] = {
		{ 1,4,15,7 } ,
		{ 8,10,2,11 },
		{ 14,3,6,13 },
		{ 12,9,5,0 } };
	
	char z = 'c';
	int flag = 2, no = 1;
	dis(board, no);
	
	while (flag != 1)
	{
		printf("\n\n\n\n\t\t\t\t\t\tMove number %d\n\n\t\t\t\t\t\tEnter choice :", no);
		z = _getch();
		if (z == 'x')
		{
			exit(0);
			return 0;
		}
		if (z == -32)
		{

			switch (z = _getch())
			{
			case 77:
				if (c > 0)
				{
					board[r][c] = board[r][c - 1];
					board[r][c - 1] = 0;
					c--;
				}
				break;
			case 80:
				if (r > 0)
				{
					board[r][c] = board[r - 1][c];
					board[r - 1][c] = 0;
					r--;
				}
				break;
			case 75:
				if (c < 3)
				{
					board[r][c] = board[r][c + 1];
					board[r][c + 1] = 0;
					c++;
				}
				break;
			case 72:
				if (r < 3)
				{
					board[r][c] = board[r + 1][c];
					board[r + 1][c] = 0;
					r++;
				}
				break;
			}
		}
		no++;
		dis(board, no);
		flag = check(board);
	}
	printf("\n\n\n\n\n\t\t\t\tCONGRATULATIONS! YOU COMPLETED THE TASK IN %d MOVES.", no);
	_getch();
	return 0;
}

