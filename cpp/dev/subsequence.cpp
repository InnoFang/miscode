#include<stdio.h>
double fun(double x)
{
	return x*x;
}
int main()
{
	FILE *fin, *fout;
	fin = fopen("subsequence.in","rb");
	fout = fopen("subsequence.out","wb");
	double n,m,t,i,sum = 0;
	while(fscanf(fin,"%lf%lf",&n,&m) != EOF)
	{
		sum = 0;
		if(n > m)
		{
			t = n;
			n = m;
			m = t;
		}
		while(n <= m)
		{
			sum += 1/fun(n);
			n++;
		}
		fprintf(fout,"%.5lf\r\n",sum);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
