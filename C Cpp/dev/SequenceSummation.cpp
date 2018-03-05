/*
Description
 ���еĶ������£� 
���еĵ�һ��Ϊn���Ժ����Ϊǰһ���ƽ�����������е�ǰm��ĺ͡� 

Input
���������ж��飬ÿ��ռһ�У�����������n��n<10000����m(m<1000)��ɣ�n��m�ĺ�����ǰ������ 

Output
����ÿ���������ݣ���������еĺͣ�ÿ������ʵ��ռһ�У�Ҫ�󾫶ȱ���2λС���� 

Sample Input
81 4
2 2 

Sample Output
94.73
3.41 
*/
#include<stdio.h>
#include<math.h>
int main()
{
	double n;
	int m;
	while(scanf("%lf%d",&n,&m) == 2)
	{
		double sum = 0;
		for(int i = 0; i < m; i++)
		{
			sum += n;
			n = sqrt(n);
		}
	printf("%.2lf\n",sum);
	}
	return 0;
}
