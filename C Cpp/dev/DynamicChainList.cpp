
//动态链表
#include<stdio.h>
#include<stdlib.h>
typedef struct s
{
	float num ;
	int score;
	struct s *next;
} Student;
Student *head = NULL;//链表头指针 
Student* creat_list()
{
	Student *p1, *p2;
	p1 = p2 = (Student*) malloc(sizeof(Student));
	scanf("%f%d",&p1->num, &p1->score);
	while(p1->num != 0) 	
	{
		if(head == NULL)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (Student*)malloc(sizeof(Student));
		scanf("%f%d",&p1->num, &p1->score);
	}
	p2->next = NULL;
	return head;
}

//求表长
int len_list(Student *h)
{
	Student *l = h;//l指向头节点
	int n = 0;//因为有头节点，所以计数从0开始
	while(l)
	{printf("%d\n",l->score);
		l = l->next;
		n++;
	}	
	return n;
} 

//查找
Student* get_list(Student *h, int i)
{
	Student *l = h;
	int n = 1;
	while(l && n < i)
	{
		l = l->next;
		n++;
	}
	if(n == i)
		return l;	
	else
		return NULL;
}


int main()
{
	Student *p;
	p = creat_list();
	while(p != NULL)
	{
		printf("%5f%5d\n",p->num, p->score);
		p = p->next;
	}
	printf("This list's length is : %d\n",len_list(head));
	
	Student *q = get_list(head, 2);
	printf("The second student's num is %f and score is %d\n",q->num, q->score);
	return 0;	
} 

