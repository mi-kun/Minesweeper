#include <stdio.h>
#include <stdlib.h>

int getrandom(int min,int max);

int main(void)
{
	int bord[12][12],bord2[12][12],i,j,k,level,a,b,fin=100;//bord:そのマスがどのようなマスかの情報　bord2:そのマスが公開されてるかどうかの情報　fin:終了条件

	for(i=1;i<11;i++)
	{
		for(j=1;j<11;j++)
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
			a=getrondom(1,10);
			b=getrondom(1,10);
			
			if(bord[a][b]==0)
			{
				i++;
				bord[a][b]=-1;
				for(j=a-1;j<=a+1;j++)
				{
					for(k=b-1;k<=b+1;k++)
					{
						if(bord[j][k]!=-1)
						{
							bord[j][k]++;
						}
					}
				}
			}
		}
	
		scanf("%d %d",&i,&j); //どのマスを選んだか
		if(bord[i][j]==-1)
		{
			printf("gameover\n");
			continue;
		}
		if(bord[i][j]>0)
		{
			bord2[i][j]=1;
		}
		if(bord[i][j]==0)
		{
			bord
		}
	}
}

int getrandom(int min,int max)
{
	return min+(int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
