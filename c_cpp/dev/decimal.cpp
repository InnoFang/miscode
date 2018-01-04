/**
*输入正整数a,b,c,输出a/b的小数形式，精确到小数点后c位，a,b<=10e6 , c<=100
*例如a=1,b=6,c=4时应输出0.1667 
*/
#include<stdio.h>
int main()
{
	freopen("decimal.in","r",stdin);
	freopen("decimal.out","w",stdout);
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c) != EOF)
	{
		printf("%.*lf\n",c,(double)a/b);
	}
	return 0;
}
