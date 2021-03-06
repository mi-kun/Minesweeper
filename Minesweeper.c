#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum BLOCK_TYPE {MINE=-1,SAFE=0};
#define FIELD_SIZE 12

int board[FIELD_SIZE][FIELD_SIZE];
int board2[FIELD_SIZE][FIELD_SIZE];
int fin;
int h[] = { -1 , -1 ,  0 ,  1 ,  1 ,  1 ,  0 , -1 };
int w[] = {  0 ,  1 ,  1 ,  1 ,  0 , -1 , -1 , -1 };

int getrandom(int min , int max);
void space(int height , int width);
void output(void);

int main(void)
{
	int i=0;
	int j;
	int k;
	int a , b;
	int level;
	int x , y;
	int n , m;

	srand((unsigned int)time(NULL));

	for(i = 1; i < FIELD_SIZE - 1; i++)
	{
		for(j = 1; j < FIELD_SIZE - 1; j++)
		{
			board[i][j] = SAFE;
			board2[i][j] = 0;
		}
	}

	fin = (FIELD_SIZE - 2) * (FIELD_SIZE - 2);
	printf("This game is 'Minesweeper'.\n Size of the board is 10 * 10.\nNumber of mines is the number of level * 6.\n\n");

	printf("Is level (1-6): ");
	while(1)
	{
		scanf("%d" , &level);

		if(level <= 6 && level >= 1)
		{
			break;
		}

		printf("Please continue.\n");
	}
	
	printf("Is coordinate (horizontal(1-10) vertical(1-10)) : ");
	
	while(1)
	{
		scanf("%d" , &y);
		scanf("%d" , &x);

		if(x < FIELD_SIZE-1 && x > 0 && y < FIELD_SIZE-1 && y > 0)
		{
			break;
		}

		printf("Please continue.\n");
	}
	
	fin -= level * 6;

	i=0;

	while(i < level * 6)
	{
		a = getrandom(1 , 10);
		
		b = getrandom(1 , 10);

		if(board[a][b] != MINE)
		{
			for(n = x-1 ; n <= x+1 ; n++)
			{
				for(m = y-1 ; m <= y+1 ; m++)
				{
					if(a == n && b == m)
					{
						break;
					}
				}
				if(a == n && b == m)
				{
					break;
				}
			}
			
			if(a == n && b == m)
			{
				continue;
			}
			
			i++;
			board[a][b] = MINE;
			for(j = a - 1; j <= a + 1; j++)
			{
				for(k = b - 1; k <= b + 1; k++)
				{
					if(board[j][k] != MINE)
					{
						board[j][k]++;
					}
				}
			}
		}
	}
	
	space(x , y);

	output();

	while(1)
	{
		printf("Is coordinate (horizontal(1-10) vertical(1-10)) : ");
		scanf("%d" , &j);
		scanf("%d" , &i);

		if(board2[i][j]==1 || i < 1 || i > FIELD_SIZE-2 || j < 1 || i > FIELD_SIZE-2)
		{
			printf("Please continue\n");
			continue;
		}
		else
		{
			if(board[i][j] == MINE)
			{
				printf("GAMEOVER\n");
				break;
			}

			if(board[i][j] > SAFE)
			{
				board2[i][j] = 1;
				fin--;
			}

			if(board[i][j] == SAFE)
			{
				space(i,j);
			}

			if(fin == 0)
			{
				printf("CLEAR\n");
				break;
			}
		}

		output();
	}
}

int getrandom(int min , int max)
{
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

void space(int height , int width)
{
	int i;

	board2[height][width]=1;
	fin--;

	for (i = 0; i < 8; ++i)
	{
		if ((height + h[i]) < FIELD_SIZE-1 && (height + h[i]) > 0 && (width + w[i]) < FIELD_SIZE-1 && (width + w[i]) > 0)
		{
			if (board2[height + h[i]][width + w[i]] == 0)
			{
				if(board[height + h[i]][width + w[i]]==SAFE)
				{
					space(height + h[i] , width + w[i]);
				}
				else if(board[height + h[i]][width + w[i]] != MINE)
				{
					board2[height + h[i]][width + w[i]] = 1;
					fin--;
				}
			}
		}
	}

	return ;
}

void output(void)
{
	printf("output\n");

	int i;
	int j;
	
	printf("   1  2  3  4  5  6  7  8  9 10 \n")
	for(i=1;i<11;i++)
	{
		if(i == 10)
		{
			printf("%d " , i);
		}
		else
		{
			printf("%d  " , i);
		}
		for(j=1;j<11;j++)
		{
			if(board2[i][j]==1)
			{
				printf(" %d ",board[i][j]);
			}
			else
			{
				printf(" = ");
			}
		}
		puts("");
	}
	puts("");
	
	return ;
}
