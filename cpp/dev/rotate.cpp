/*
*输入一个n*n字符矩阵，把它左转90°后输出 
*/
#include<stdio.h>
#define MAXN 5000 + 10
char a[MAXN][MAXN];
char t[MAXN];
int main()
{
	int i,j,n;
	while(scanf("%d",&n) == 1)
	{
		getchar();
		for(i = 0 ; i < n ; i++)
		{
			for(j = 0 ; j < n ; j++)
			{
				scanf("%c",&a[i][j]);	
				getchar();			
			}
//			getchar();
		}
//		for(i = 0 ; i < n ; i++)
//		{
//			for(j = 0 ; j < n ;j++)
//			{
//				printf("%c",a[i][j]);
//			}
//			printf("\n");
//		}
		printf("\n");
		for(j = n -1 ; j >= 0 ; j--)
		{
			for(i = 0 ;i < n ;i++)
			{
				printf("%c ",a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
} 
