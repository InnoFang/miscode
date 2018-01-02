#include<stdio.h>
#include<string.h>
char list[51][51];
char word[21];
void match(int r , int c)
{
	int wordLen = strlen(word);
	int i,j,k,x,y;
	for(i = 0 ; i < r ; ++i)
	{
		for(j = 0 ; j < c ; ++j)
		{
			if(word[0] == list[i][j])
			{
				x = i , y = j , k = 1;
				while(y > 0 && list[x][y-1] == word[k])
				{
					y--;
					k++;
				}
				if(k == wordLen)
				{
					printf("%d %d\n",i+1,j+1);
					return ;
				}					
				x = i , y = j , k = 1;
				while(y < c - 1 && list[x][y+1] == word[k])
				{
					k++;
					y++;
				}
				if(k == wordLen)
				{
					printf("%d %d\n",i+1,j+1);
					return ;
				}			
				x = i , y = j , k = 1;
				while(x < r - 1  && list[x+1][y] == word[k])
				{
					k++;
					x++;
				}
				if(k == wordLen)
				{
					printf("%d %d\n",i+1,j+1);
					return ;
				}
				x = i , y = j , k = 1;
				while(x > 0 && list[x-1][y] == word[k])
				{
					k++;
					x--;
				}
				if(k == wordLen)
				{
					printf("%d %d\n",i+1,j+1);
					return ;
				}
				x = i , y = j , k = 1;
				while(y < c - 1 && x >= 0 && list[x-1][y+1] == word[k])
				{
					k++;
					x--;
					y++;
				}
				if(k == wordLen)
				{
					printf("%d %d\n",i+1,j+1);
					return ;
				}
				x = i , y = j , k = 1;
				while(y < c - 1 && x < r - 1&& list[x+1][y+1] == word[k])
				{
					k++;
					x++;
					y++;
				}
				if(k == wordLen)
				{
					printf("%d %d\n",i+1,j+1);
					return ;
				}
				x = i , y = j , k = 1;
				while(y > 0 && x >= 0 && list[x+1][y+1] == word[k])
				{
					k++;
					x++;
					y++;
				}
				if(k == wordLen)
				{
					printf("%d %d\n",i+1,j+1);
					return ;
				}
				x = i , y = j , k = 1;				
				while(y > 0 && x < r - 1&& list[x+1][y-1] == word[k])
				{
					k++;
					x++;
					y--;
				}
				if(k == wordLen)
				{
					printf("%d %d\n",i+1,j+1);
					return ;
				}
			}
		}
	}
}
int main()
{
	int caseNum,rows,columns,i,j,wordNum,wordLen;
	while(scanf("%d",&caseNum) != EOF)
	{
		while(caseNum--)
		{
			scanf("%d%d",&rows,&columns);
			for(i = 0 ; i < rows ; i++)
			{
				scanf("%s",&list[i]);
			}
			for(i = 0;i < rows ; i++)
			{
				for(j = 0 ;j < columns ; j++)
				{
					if(list[i][j] >= 'A' && list[i][j] <= 'Z')
						list[i][j] = list[i][j] - 'A' + 'a';
				}
			}			
			scanf("%d",&wordNum);	
			while(wordNum--)
			{
				scanf("%s",&word);	
				wordLen = strlen(word);
				for(i = 0 ;i < wordLen; i++)
				{
					if(word[i] >= 'A' && word[i] <= 'Z')
						word[i] = word[i] - 'A' + 'a';
				}
				match(rows,columns);
			}
			if(caseNum)
				printf("\n");		
		}
	}
	return 0;
}
