#include<stdio.h>
#include<time.h>
int main()
{
	const int MOD = 1000000;
	int i,j,n,s = 0;
	scanf("%d",&n);
	for(i = 0;i <= n ;++i)
	{
		int factorial = 1;
		for(j = 1 ; j  <= i ; ++j)
			factorial = (factorial * j % MOD);
		s = (s + factorial) % MOD;
	}
	printf("%d\n",s);
	printf("Time used : %lf",(double) clock() / CLOCKS_PER_SEC);
	return 0;
}
