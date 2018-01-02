/*
*有n盏灯，编号1~n。第一个人把所有灯打开，第二个人按下所有编号为2的倍数的开关(这些灯将被关掉)，第3个人按下所有编号
*3的倍数的开关(开关关掉的将被打开，开着的灯将被关闭)，依次类推。一共有k个人，问最后有那些灯开着？输入n和k，输出
*开着的灯编号。k<=n<=1000
*sample input
*7 3
sample output
*1 5 6 7   
*/#include<stdio.h>
#include<string.h>
#define MAXN 1000 + 10
int arr[MAXN];
int main()
{
	int n , k , i , j;
	while(scanf("%d%d",&n,&k) == 2)
	{
		memset(arr,0,sizeof(arr));	
		for(i = 1 ; i <= k ; i++)
		{
			for(j = 1 ; j <= n ; j++)
			{
//				if(i % (j - 1) == 0)
//				{
//					if(arr[j - 1] == 0)
//						arr[j - 1] = 1;
//					else
//						arr[j - 1] = 0;
//				}
				if(j % i == 0)
					arr[j] = !arr[j];
			}
		}
		for(i = 1 ; i <= n ; i++)
		{
			if(arr[i] == 1)
				printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}
