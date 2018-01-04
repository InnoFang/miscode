/*
*3-4读入一行恰好包含加号，减号或乘号的表达式，输出它的值，两个运算数均为不超过100的非负整数，运算数可紧挨这，也可以有
一个或多个空格 
*/
//#include<stdio.h>
//#define MAXN 1000+10
//char cal[MAXN];
//int main()
//{
//	char c,ch;
//	int s1 = 0 , s2 = 0 , i ,m = 0 , n = 0 , flag = 1;
//	while(c=getchar())
//	{
//		if(c >= '0' && c <= '9' && flag)
//			cal[m++] = c;
//		else if(c == '+' || c == '-' || c == '*')
//		{
//			ch = c;
//			for(i = 0;i < m;i++)
//			{
//				s1 = s1 * 10 + cal[i] - '0';
//				flag = 0;
//			}
//		}
//		else if(c >= '0' && c <= '9' && !flag)
//			cal[n++] = c;
//		else if(c == '\n' && !flag)
//		{
//			for(i = 0;i < n;i++)
//			{
//				s2 = s2 * 10 + cal[i] - '0';
//			}
//			break;
//		}
//	}
//	switch(ch)
//	{
//		case '+':
//			printf("%d\n",s1+s2);
//			break;
//		case '-':
//			printf("%d\n",s1-s2);
//			break;
//		case '*':
//			printf("%d\n",s1*s2);
//			break;
//		default:
//			break;
//	}
//	return 0;
//}
#include <stdio.h>  
#define N 1000  
  
char str[N];  
  
int  
main(void)  
{  
    char *p = NULL;  
    int op1, op2;  
      
    fgets(str, sizeof(str), stdin);//it will contains '\n';  
      
    for (p = str; *p != '\n'; p++) {  
        if (*p == '+' || *p == '-' || *p == '*')  
            break;  
    }  
    if (*p != '\n'){  
        switch(*p) {  
        case '+':  
            sscanf(str, "%d + %d", &op1, &op2);  
            printf("%d\n", op1+op2);  
            break;  
        case '-':  
            sscanf(str, "%d - %d", &op1, &op2);  
            printf("%d\n", op1-op2);  
            break;  
        case '*':  
            sscanf(str, "%d * %d", &op1, &op2);  
            printf("%d\n", op1*op2);  
            break;  
        }     
    }  
    return 0;  
} 
