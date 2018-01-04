//���ͼ���  H(n) = 1 + 1/2 + 1/3 + ... + 1/n,������λС��
#include<stdio.h>
int main()
{
	FILE *fout, *fin;
	fin = fopen("harmony.in","rb");
	fout = fopen("harmony.out","wb");
	double n,h = 0,i;
	while(fscanf(fin,"%lf",&n) != EOF)
	{
		for(i = 1 ;i <= n; ++i)
		{
			h += 1 / i;
		}
			fprintf(fout,"%.3lf\r\n",h);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
