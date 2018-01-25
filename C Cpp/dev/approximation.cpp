//求π的近似解 
#include<stdio.h>
int main()
{
	freopen("approximation.out","w",stdout);
	float sum = 0 , i = 1;
	int flag = -1;
	while(1/i >= 1e-6)
	{
		flag *= -1;
		sum += flag*(1/i);
		i += 2;
	}
	sum *= 4;
	printf("%10.9f\n",sum);
	return 0;	
} 
