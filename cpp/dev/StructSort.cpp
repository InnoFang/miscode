#define LOCAL
#include<stdio.h>
#include<string.h>
#define MAXN 100000+10		
typedef struct
{
	char id[10];
	char name[10];
	int score;
} Student;
Student s[MAXN];
void sortId(Student stu[], int n)
{
	int i, j, k;
	Student temp;
	for(i = 1; i < n ; i++)
    {
        if(strcmp(stu[i].id, stu[i-1].id) < 0)
        {
            temp = stu[i];  
            for(j = i - 1 ; j >= 0 && strcmp(stu[j].id, temp.id) > 0;j--) 
            {
                stu[j+1] = stu[j];    
            }
            stu[j+1] = temp; 
        }
    }
}
void sortName(Student stu[], int n)
{
	int i, j, k;
	Student temp;
	for(i = 1; i < n ; i++)
    {
        if(strcmp(stu[i].name, stu[i-1].name) < 0)
        {
            temp = stu[i];  
            for(j = i - 1 ; j >= 0 && strcmp(stu[j].name, temp.name) > 0;j--) 
            {
                stu[j+1] = stu[j];    
            }
            stu[j+1] = temp; 
        }
    }
	for(i = 0;i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(strcmp(stu[i].name, stu[j].name) == 0)
			{
				if(strcmp(stu[i].id, stu[j].id) > 0)
				{
					Student temp = stu[i];
               	 	stu[i] = stu[j];
               		stu[j] = temp;
				}
			}
		}
	}
}
void sortScore(Student stu[], int n)
{ 
    int i, j, k;
	Student temp;
	for(i = 1; i < n ; i++)
    {
        if(stu[i].score < stu[i-1].score)
        {
            temp = stu[i];  
            for(j = i - 1 ; j >= 0 && stu[j].score > temp.score;j--) 
            {
                stu[j+1] = stu[j];    
            }
            stu[j+1] = temp; 
        }
    }
	for(i = 0;i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			
			if(stu[i].score == stu[j].score)
			{
				if(strcmp(stu[i].id, stu[j].id) > 0)
				{
					Student temp = stu[i];
               	 	stu[i] = stu[j];
               		stu[j] = temp;
				}
			}
		}
	}
}
int main()
{
	#ifdef LOCAL
	freopen("StructSort.in","r",stdin);
	freopen("StructSort.out","w",stdout);
	#endif
	int n, c, Case = 0, i;
	while(scanf("%d%d",&n,&c) != EOF)
	{
		Case++;			
		if(!n)
		{
			break;
		}
		for(i = 0; i < n; i++)
		{
			scanf("%s%s%d",&s[i].id,&s[i].name,&s[i].score);
		}	
		printf("Case %d:\n",Case);
		switch(c)
		{
			case 1:
				sortId(s,n);
    			for (int i = 0; i < n; i++) 
				{
        			printf("%s %s %d\n", s[i].id, s[i].name, s[i].score);
    			}
				break;
			case 2:
				sortName(s,n);
    			for (int i = 0; i < n; i++) 
				{
        			printf("%s %s %d\n", s[i].id, s[i].name, s[i].score);
    			}
				break;
			case 3:
				sortScore(s,n);
    			for (int i = 0; i < n; i++) 
				{
        			printf("%s %s %d\n", s[i].id, s[i].name, s[i].score);
    			}
				break;
			default:
				break;
		}
	}
	return 0;
}
