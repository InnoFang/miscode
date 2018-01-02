/*
*Êä³öÂÝÐýÊý×é£¬n<=8 
*/
#include<stdio.h>
#include<string.h>
#define MAXN 10
int arr[MAXN][MAXN];
int main()
{
	int n , x , y , m;	
	while(scanf("%d",&n) == 1)
	{
		m = 1;
		x = 0 , y = n - 1;
		memset(arr,0,sizeof(arr));
		arr[x][y] = m;
		while(m < n*n)
		{
			while(x + 1 < n && !arr[x+1][y])
				arr[++x][y] = ++m;
			while(y - 1>= 0 && !arr[x][y-1])
				arr[x][--y] = ++m;
			while(x - 1 >= 0 && !arr[x-1][y])
				arr[--x][y] = ++m;
			while(y + 1 < n && !arr[x][y+1])
				arr[x][++y] = ++m;
		}
		for(x = 0 ; x < n ; x++)
		{
			for(y = 0 ; y < n ; y++)
			{
				printf("%3d",arr[x][y]);
			}
			printf("\n");
		}
	}
	return 0;
}
