/*
Input
输入数据有多组，每组占一行，由4个实数组成，分别表示x1,y1,x2,y2,数据之间用空格隔开。 

Output
对于每组输入数据，输出一行，结果保留两位小数。 

Sample Input
0 0 0 1
0 1 1 0 

Sample Output
1.00
1.41 
*/
#include<stdio.h>
#include<math.h>
int main()
{
	double x1, y1, x2, y2;
	while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2) == 4)
	{
		printf("%.2lf\n",sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
	}
	return 0;
}
