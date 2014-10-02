#include <stdio.h>
#include <stdlib.h>

int getrandom(int min,int max);

int main(void)
{
	int bord[10][10],bord2[10][10],i,j,k,level,a,b,fin=100;//bord:そのマスがどのようなマスかの情報　bord2:そのマスが公開されてるかどうかの情報　fin:終了条件

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			bord[i][j]=0;
			bord2[i][j]=0;
		}
	}

	while(1)
	{
		fin=100;
		printf("レベルを入力してください");
		scanf("%d",&level);
		
		fin-=level*4;

		for(i=1;i<=level*4;) //地雷の位置
		{
			a=getrondom(0,9);
			b=getrondom(0,9);

			if(bord[a][b]==0)
			{
				i++;
				bord[a][b]=-1;
				for(j=)
			}
		}

		scanf("%d %d",&i,&j); //どのマスを選んだか
		if(bord[i][j]==-1)
		{
			printf("gameover\n");
			continue;
		}
		if(bord[i][j]==0)
		{
			
		}
	}
}

int getrandom(int min,int max)
{
	return min+(int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
