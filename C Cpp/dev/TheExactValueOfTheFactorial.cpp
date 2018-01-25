#include<stdio.h>
#include<string.h>
const int  maxn = 3000;
int f[maxn];
int main()
{
	int i, j, n;
	scanf("%d",&n);
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for(i = 2; i <= n; i++)
	{
		int c = 0;//保存进位 
		//模拟乘法 
		for(j = 0; j < maxn; j++)
		{
			int s = f[j] * i + c;//获得各个位与因数i的乘积 
			f[j] = s % 10;//将得到的积取余，即为两数相乘后该位上的数 
			c = s / 10;//若两数的乘积大于9，就进位 
		}
	}
	for(j = maxn - 1; j >= 0; j--)
	{
		if(f[j])
			break;
	}
	for(i = j; i >= 0; i--)
	{
		printf("%d",f[i]);
	}
	printf("\n");
	return 0;
}
