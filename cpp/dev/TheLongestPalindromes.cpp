/*
*输入一个字符串，求出其中最长的回文子串 
*思路：
*	1.用fgets获取文件中的每一行的字符串
*	2.用isalpha函数判断是否为字母，并将字母用toupper函数同一变为大写，并用p[]数组保存每个字符下标 
*	3.枚举回文串的中间位置，并分为回文串长度为偶数和奇数的两种情况，并且在每一种情况内获取回文串长度最大的情况，并
记录回文串开始和结束的位置 

Ps:若是有字符串需要从中间进行处理，应该考虑到字符串长度为偶数和奇数的两种情况，并做出相应的处理办法 
*/
#define LOCAL 
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAXN 5000 + 10
char  buf[MAXN], s[MAXN] , p[MAXN];//buf为原生字符串，s为经过预处理的字符串，p用来保存每个原生字符串每个字符的下标 
int main()
{
#ifdef LOCAL
	freopen("TheLongestPalindromes.in","r",stdin);
	freopen("TheLongestPalindromes.out","w",stdout);
#endif
	int i,j,m = 0,max = 0,len,x,y;
	//在保证不会越界的情况下可以用gets标准输入 
	fgets(buf,sizeof(s),stdin);//获取文件内的每一行的字符串 
	len = strlen(buf);
	for(i = 0 ; i < len ; i++)
	{
		if(isalpha(buf[i]))
		{
			p[m] = i;
			s[m++] = toupper(buf[i]);//对原生字符串预处理 
		}				
	}
	for(i = 0 ;i < m ; i++)
	{
		//回文串长度为奇数的情况下 
		for(j = 0 ; i - j >= 0 && i + j < m ; j++)
		{
			if(s[i-j] != s[i + j])
				break;
			if(2 * j + 1 >= max)
			{
				max = 2 * j + 1;		
				x = p[i - j];
				y = p[i + j];		
			}

		}
		//回文串为偶数的情况下 
		for(j = 0 ; i - j >= 0 && i + j + 1 < m ; j++)
		{
			if(s[i - j] != s[i + j + 1])
				break;
			if(2 * j + 2 > max)
			{
				max = 2 * j + 2;	
				x = p[i - j];
				y = p[i + j + 1];			
			}
		}
	}
	for(i = x ; i <= y ;i++)
	{
		printf("%c",buf[i]);
	}
	printf("\n");
	return 0;
}
