#include<stdio.h>
#include<string.h>
#define MAXN 100000	
char t[MAXN];
int main()
{
	int n = 0,m = 0,len;
	while(scanf("%s",t) != EOF)
	{
		len = strlen(t);
		m += len;
		n++;
	}
	printf("average = %.2lf\n",(double)m/n);
	
	return 0;
}
