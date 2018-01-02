#include<stdio.h>
int main()
{
	FILE *fin ,*fout;
	fin = fopen("triangle.in","r");
	fout = fopen("triangle.out","w");
	int x , i , j , k;
	while(fscanf(fin,"%d",&x) == 1)
	{
		for(i = x ; i >= 0 ;i--)
		{
			for(j = x ; j > i ; j--)
				fprintf(fout," ");
			for(k = 2 * i ; k >= 0 ;k--)
				fprintf(fout,"#");
		fprintf(fout,"\n");
		}
		
	}
	fclose(fout);
	fclose(fin);
	return 0;
}
