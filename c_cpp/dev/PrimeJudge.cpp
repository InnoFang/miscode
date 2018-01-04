/*
Description
 对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。 
 
Input
输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。 

Output
对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。 

Sample Input
0 1
0 0 

Sample Output
OK 
*/
#include<stdio.h>
int is_prime(int n)
{
	for(int i = 2; i < n/2; i++)
	{
		if(n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int x, y;
	while(scanf("%d%d",&x,&y) == 2)
	{
		if(!x && !y)
		{
			break;
		}
		int ok = 1;
		for(int n = x; n <= y; ++n)
		{
			if(!is_prime(n*n + n + 41))
			{
				ok = 0;
			}
		}
		if(ok)
		{
			printf("OK\n");
		}
		else
		{
			printf("Sorry\n");
		}
	} 
	return 0;
}
