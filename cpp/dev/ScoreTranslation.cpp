/*
Description
输入一个百分制的成绩t，将其转换成对应的等级，具体转换规则如下： 
90~ 100为A; 
 80~ 89为B; 
 70~ 79为C; 
 60~ 69为D; 
 0~ 59为E; 

Input
输入数据有多组，每组占一行，由一个整数组成。 

Output
对于每组输入数据，输出一行。如果输入数据不在0~ 100范围内，请输出一行：“Score is error!”。 

Sample Input
56
67
100
123 

Sample Output
E
D
A
Score is error!

*/
#include<stdio.h>
int main()
{
	int t;
	while(scanf("%d",&t) == 1)
	{
		if(t < 0 || t > 100)
		{
			printf("Score is error!\n");
		}
		else
		{
			int s = t / 10;
			switch(s)
			{
				case 10:
				case 9: printf("A\n"); break;
				case 8: printf("B\n"); break;
				case 7: printf("C\n"); break;
				case 6: printf("D\n"); break;
				default: printf("E\n"); break;	 
			}
		}
	}
	return 0;
}
