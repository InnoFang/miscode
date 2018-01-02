#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int r1, c1, r2, c2;
int  tips()
{
	int n, m;
	printf("Input the first Matrix's length and width:");
	n = scanf("%d%d",&r1,&c1);
	printf("Input the second Matrix's length and width:");
	m = scanf("%d%d",&r2,&c2);
	if(n == 2 && m == 2 && c1 == r2)
	{
		return 1;
	}
	return 0;
}
void matrixInput(int **m,int r, int c)
{
	int i, j;
	for(i = 0;i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			scanf("%d",((int*)m + r*i + j));
		}
	}
}
void mul(int **m1, int **m2, int **result)
{
	int i, j, k;
	for(i = 0; i < r1; i++)
	{	
		for(j = 0; j < c2; j++)
		{
			for(k = 0; k < (c1||r2); k++)
			{
				*((int*)result + r1*i + j) += *((int*)m1 + r1*i + k) * *((int*)m2 + r2*k + j);
				printf("---%d = %d * %d---\n",*((int*)result + r1*i + j),*((int*)m1 + r1*i + k),*((int*)m2 + r2*k + j));
			}
		}
	}
}
void print(int **m, int r, int c)
{
	int i, j;
	for(i = 0;i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("%d",*((int*)m + r*i + j));
			if(i < r)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
int main()
{
	while(tips())
	{
//		
		int m1[r1][c1], m2[r2][c2], result[r1][c2];
		memset(result,0,sizeof(result));
		matrixInput((int**)m1,r1,c1);
		print((int**)m1,r1,c1);	
		matrixInput((int**)m2,r2,c2);
		print((int**)m2,r2,c2);	
//		mul((int**)m1,(int**)m2,(int**)result);
		int p,q,r;
	    for(p=0;p<r1;p++)
		{
			for(r=0;r<c2;r++)
			{
//				int c;
				for(q=0;q<r2;q++)
				{
	               result[p][r] += m1[p][q] * m2[q][r];
				}
//				 = c;
				printf("%d = %d * %d\n",result[p][r],m1[p][q],m2[q][r]);
			}
		}
		print((int**)result,r1,c2);	
//		int i, j;
//		for(i = 0;i < r1; i++)
//		{
//			for(j = 0; j < c1; j++)
//			{
//				printf("%d ",m1[i][j]);
//			}
//			printf("\n");
//		}
	}
	return 0;
}

/*
1 2
2 3
1 2
1 2 3
4 5 6
*/
