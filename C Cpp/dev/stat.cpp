#include<stdio.h>
#include<stdlib.h>
int main()
{
	freopen("stat.in","r",stdin);
	freopen("stat.out","w",stdout);
	int x,*s,t,i,m,n;//x表示要输入数的个数,s为动态内存分配的整形数组, t为输入的数，i用于循环，m表示判断标准，n用于记录小于标准得到个数 
	while(scanf("%d",&x) == 1)
	{
		n = 0;
		s = (int*) malloc(x);
		for(i = 0 ; i < x ; i++)
		{
			scanf("%d",&t);
			s[i] = t;
		}
		scanf("%d",&m);
		for(i = 0 ; i < x ; i++)
		{
			if(s[i] < m)
				n++;
		}
		
		printf("%d\n",n);
		free(s);
	}
}
