//大数相加 

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 110;
struct bign
{
	int len, s[maxn];
	bign()
	{
		memset(s, 0, sizeof(s));
		len = 1;
	}
	bign bign::operator + (const bign& a,const bign& b) 
	{
	 	int i,max=(a.len>b.len?a.len:b.len),t,c;
	 	bign sum;
	 	sum.len=0;
	 	for(i=0,c=0;c||i<max;i++)
	 	{
	 		t=c;
	 		if(i<a.len)
				t+=a.s[i];
	  		if(i<b.len)
				t+=b.s[i];
	  		sum.s[sum.len++]=t%10;
	  		c=t/10;
	 	}
 		return sum;
	}	
};
//int max(int a, int b)
//{
//	if(a > b)
//		return a;
//	else
//		return b;
//}

int main()
{
	char a[110];
	int t = 100;
	bign start, total;
	while(t--)
	{	scanf("%s",a);
		
		int l = strlen(a);
		bign oper;
		oper.len = l;
		for(int i = 0;i < l; i++)
		{
			oper.s[i] = a[l-1-i];
		}
		total = operator+(total,oper);
		if(strcmp(a,"0") == 0)
		{
			for(int i = l - 1; i >= 0 ; i--)
			{
				printf("%d",total.s[i]);
			}
			printf("\n");
			break;
		}
	}
	return 0;
}
