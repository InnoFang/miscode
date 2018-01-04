/* 
输入一些学生的成绩，哪个分数出现的次数最多？如果有多个并列，从小到大输出
TASK1：分数均为不超过一百的非负整数
TASK2：分数均为不超过一百的非负实数，但最多保留两位小数 
*/
#include<stdio.h>
#include<string.h>
//#define TASK
#define MAXN 101
int main()
{
	//处理成绩为整数 
	#ifdef TASK 
	int rank[MAXN],n,i,max;
	memset(rank,0,sizeof(rank));
	while(scanf("%d",&n) == 1)
	{
		rank[n]++;
	}
	max = rank[0];
	for(i = 1 ;i < MAXN ;i++)
	{
		if(max < rank[i])
			max = rank[i];
	}
	for(i = 0 ;i < MAXN ;i++)
	{
		if(rank[i] == max)
			printf("%d\n",i);
	}
	#else
	//处理成绩为整数 ，也可以处理实数 
	float score[MAXN],rank[MAXN],list[MAXN],x,t;
	int i,j,flag = 0,m = 0,n = 0,p = 0,max;
	memset(score,0,sizeof(score));
	memset(rank,0,sizeof(rank));
	//对输入的数进行检测，若已经输入过了那么直接计数，不加入数组，否则就加入数组并计数 
	while(scanf("%f",&x) == 1)
	{
		flag = 0;
		for(i = 0 ; i < MAXN ;i++)
		{
			if(x == score[i])
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			rank[i]++;
		}
		else
		{
			score[m++] = x;
			rank[n++]++;
		}			
	}	
	//检测成绩出现的最多次数 
	max = rank[0];
	for(i = 1 ; i < n;i++)
	{	
		if(max < rank[i])
			max = rank[i];
	}
	//将与最大次数相同的成绩放入list数组 
	for(i = 0 ;i < n ; i++)
	{
		if(max == rank[i])
		{
		//			printf("%.2f\n",score[i]);	
			list[p++] = score[i];
		}
	}
	// 对list数组的成绩由小到大排序 
	for(i = 0 ; i < p - 1; i++)
	{
		for(j = 0 ; j <= i ;j++)
		{
			if(list[j] > list[j+1])
			{
				t = list[j];
				list[j] = list[j+1];
				list[j+1] = t;
			}
		}
	}
	for(i = 0 ; i < p ;i++)
	{
		printf("%.2f\n",list[i]);
	}
	#endif
	return 0;
}
