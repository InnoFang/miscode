//Ë®ÏÉ»¨Êý 
#include<stdio.h>
int main()
{
	FILE *fout;
	fout = fopen("daffodil.out","wb");
	int x = 100,a,b,c;
	while(x < 1000)
	{
		a = x / 100;
		b = x % 100 / 10;
		c = x % 10;
		if(x == a*a*a + b*b*b + c*c*c)
		{
			printf("%d \n",x);
			fprintf(fout,"%d \n",x);
		}
		x++;
	}
	fclose(fout);
	return 0;
}
