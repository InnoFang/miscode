/**
Input
输入数据有多组，每组占一行，有三个字符组成，之间无空格。 

Output
对于每组输入数据，输出一行，字符中间用一个空格分开。 

Sample Input
qwe
asd
zxc 

Sample Output
e q w
a d s
c x z 
*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int cmp_char(const void* _a, const void* _b)
//{
//	return (*(char*)_a - *(char*)_b);
//}
//int main()
//{
//	char a, b, c;
//	while(scanf("%c%c%c",&a,&b,&c) != EOF)
//	{
//		getchar();
//		char str[3];
//		str[0] = a;
//		str[1] = b;
//		str[2] = c;
//		qsort(str, 3, sizeof(str[0]), cmp_char) ;
//		for(int i = 0; i < strlen(str); i++)
//		{
//			printf("%c",str[i]);
//			if(i < 2)
//			{
//				printf(" ");
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//降序 
//bool cmp(char a, char b)
//{
//	return a > b;
//}
int main()
{
	char a, b, c;
	while(scanf("%c%c%c",&a,&b,&c) != EOF)
	{
		getchar();
		char str[3];
		str[0] = a;
		str[1] = b;
		str[2] = c;
//		sort(str,str+3,cmp);
		sort(str,str+3);
		for(int i = 0; i < strlen(str); i++)
		{
			printf("%c",str[i]);
			if(i < 2)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
