#include<stdio.h>
int main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	int x,n = 0,i;
	while(scanf("%d",&x) == 1)
	{
		while(x)
		{
			n++;
			x /= 10;
		}
	}
	printf("%d\n",n);
	return 0;
}
