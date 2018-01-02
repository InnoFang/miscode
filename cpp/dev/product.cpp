#include<stdio.h>
#define MAXN 1000 + 10
char n[MAXN];
int main()
{
	int x,sum = 1,c,k,i,m;
	while(1)
	{
		c = scanf("%d",&x);
		if(c == 0)
		{
			k = getchar();
			if(k == 'A')
				break;
		}
		else
		{
			n[m++] = x;
		}
	}
	for(i = 0 ; i < m ; i++)
	{
		sum *= n[i];
	}
	if(sum <= 999 && sum >= -999)
		printf("%d\n",sum);
	else
		printf("%d\n",sum%1000);
	return 0;
}
//#include <stdio.h>
//int main ()
//{
// int a[50]={0},c,k,b,i=0,sum=1;
// while (1)                       //1、这里为什么要在 while (1) 中循环？
// {
//  c=scanf ("%d",&b);
//  if (c==0)                      //2、为什么要再c==0的情况下讨论字符？
//
//{k=getchar ();
//if (k=='R') 
//
//break;
//}
//  else if (b!=0)                //用b、c分别有什么作用？好处？
//
//{a[i]=b;
//i++;
//}
//  c=0;
// } 
// for (i=0;a[i]!=0;i++)
// {
// sum*=a[i];
// }
//
//if (sum<=999 && sum >= -999)
//printf ("%d",sum);
//else 
//	 printf ("%d",sum%1000);
// return 0;
//}

