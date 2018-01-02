#include<stdio.h>
int main()
{
	freopen("hanxin.in","r",stdin);
	freopen("hanxin.out","w",stdout);
	int x,a,b,c;
	while(scanf("%d%d%d",&a,&b,&c) == 3)
	{
		for(x = 10 ; x <= 100 ;x++)
		{
			if(x % 3 == a && x % 5 == b && x % 7 == c)
			{
				printf("%d\n",x);	
				break;			
			}

		}
		if(x > 100)
			printf("No answer\n");	
	}
	return 0;
}
