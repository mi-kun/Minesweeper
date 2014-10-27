#include <stdio.h>
#include <stdlib.h>

enum BLOCK_TYPE {MINE=-1,SAFE=0};
#define FIELD_SIZE 12

int getrandom(int min , int max);
void space(int height , int width);
void output(int bord[FIELD_SIZE][FIELD_SIZE] , int bord2[FIELD_SIZE][FIELD_SIZE]);

int main(void)
{
	int i;
	int j;
	int k;
	int a , b;
	int level;
	int fin;
	int bord[FIELD_SIZE][FIELD_SIZE];
	int bord2[FIELD_SIZE][FIELD_SIZE];

	for(i = 1; i < FIELD_SIZE - 1; i++)
	{
		for(j = 1; j < FIELD_SIZE - 1; j++)
		{
			bord[i][j] = SAFE;
			bord2[i][j] = SAFE;
		}
	}

	fin = 100;
	printf("レベルを入力してください");
	scanf("%d", &level);

	fin -= level * 4;

	while(i <= level * 4)
	{
		a = getrandom(1 , 10);
		b = getrandom(1 , 10);

		if(bord[a][b] == SAFE)
		{
			i++;
			bord[a][b] = MINE;
			for(j = a - 1; j <= a + 1; j++)
			{
				for(k = b - 1; k <= b + 1; k++)
				{
					if(bord[j][k] != -1)
					{
						bord[j][k]++;
					}
				}
			}
		}
	}
	
	while(1)
	{
		scanf("%d %d", &i , &j);

		if(bord[i][j] == MINE)
		{
			printf("gameover\n");
			break;
		}

		if(bord[i][j] > SAFE)
		{
			bord2[i][j] = 1;
			fin--;
		}

		if(bord[i][j] == SAFE)
		{
			space(i,j);
		}

		if(fin == 0)
		{
			printf("クリア\n");
		}

		output(int bord[FIELD_SIZE][FIELD_SIZE], int bord2[FIELD_SIZE][FIELD_SIZE]);
	}
}

int getrandom(int min , int max)
{
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

void space(int height , int width)
{
	int i;
	int h[] = { 1 ,  1 ,  0 , -1 , -1 , -1 ,  0 ,  1};
	int w[] = { 0 ,  1 ,  1 ,  1 ,  0 , -1 , -1 , -1};

	for (i = 0; i < 8; ++i)
	{
		if ((height + h[i]) < 11 && (height + h[i]) > 0 && (width + w[i]) < 11 && (width + w[i]) > 0)
		{
			if (bord2[height + h[i]][width + w[i]] == 0 && bord[height+h[i]][width+w[i]] != -1)
			{
				bord2[height + h[i]][width + w[i]] = 1;
				fin--;
				space(height + h[i] , width + w[i]);
			}
		}
	}

	return ;
}

void output(int bord[FIELD_SIZE][FIELD_SIZE], int bord2[FIELD_SIZE][FIELD_SIZE])
{
	int i;
	int j;
	for(i=1;i<11;i++)
	{
		for(j=1;j<11;j++)
		{
			if(bord2[i][j]==0)
			{
				if(bord[i][j]==SAFE)
				{
					printf("   ");
				}
				else
				{
					printf(" %d ",bord[i][j]);
				}
			}
			else
			{
				printf("   ");
			}
		}
		puts("");
	}
	puts("");
	return ;
}
