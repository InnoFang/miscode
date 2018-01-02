/*
输入一个字典（用******结尾），然后在输入若干单词，为输入一个单词w，都需要在字典中找到可以用w的字母重排后得到的
单词，并按照字典序从小到大的顺序在一行中输出（如果不存在，就输出:(）。输入单词之间用空格或空行隔开，且所有输入单词
都有不超过6个小写字母组成。字典中的单词不一定按字典序排列 
*/
#define LOCAL
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char dic[2000][10], re[2000][10];
int n = 0;

int cmp_char(const void* a, const void* b)
{
	return (*(char*)a - *(char*)b);
}

int cmp_string(const void* a, const void* b)
{
	return strcmp((char*)a, (char*)b);
}

int main()
{
	#ifdef LOCAL
	freopen("LetterRearrangement.in","r",stdin);
	freopen("LetterRearrangement.out","w",stdout);
	#endif
	while(1)
	{
		scanf("%s",dic[n]);
		if(dic[n][0] == '*')
		{
			break;
		}
		n++;
	}
	qsort(dic, n, sizeof(dic[0]), cmp_string); // 对字典的单词排序 
//	for(int i = 0; i < n; i++)
//	{
//		printf("%s ",dic[i]);
//	}
//	printf("\n");
	for(int i = 0; i < n; i++)
	{
		strcpy(re[i], dic[i]);
		qsort(re[i], strlen(re[i]), sizeof(re[i][0]), cmp_char);//对每个单词的字母进行排序 
	}
//	for(int i = 0; i < n; i++)
//	{
//		printf("%s ",re[i]);
//	}
	char word[10];
	while(scanf("%s",word) == 1)
	{
		int found = 0, i;
		qsort(word, strlen(word), sizeof(word[0]), cmp_char);
		for( i = 0; i < n; i++)
		{
			if(strcmp(word,re[i]) == 0)
			{
				found = 1;
				printf("%s ",dic[i]);	
			} 
		}
		if(!found)
		{
			printf(":(");
		}
		printf("\n");
	}
	return 0;
}
