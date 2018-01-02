//delete the repeated element from the list
#include<stdio.h>
#include<stdlib.h>
typedef struct s{
	int id;
	struct s *next;
}Student;

Student *head = NULL;

void print()
{
	printf("\n--------printing start--------\n");
	if(NULL == head)
		return ;
	Student* p = head;
	while(p)
	{
		printf("%d\n",p->id);
		p = p->next;
	}
	printf("\n--------printing end--------\n");	
}

void delete_repetition()
{
	Student *p, *q, *r;
	if(NULL == head)
		return ;
	p = q = head;
	while(p)
	{
		q = p;//*****
		while(q->next)
		{
			if(q->next->id == p->id)
			{
				r = q->next;
				q->next = r->next;
				free(r);//*****
			}
			else
			{
				q = q->next;
			}				
		}
		p = p->next;
	}
}
int main()
{
	Student *p1, *p2;
	p1 = p2 = (Student*)malloc(sizeof(Student));
	scanf("%d",&p1->id);
	while(p1->id != 0)
	{
		if(NULL == head)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (Student*)malloc(sizeof(Student));
		scanf("%d",&p1->id);
	}
	p2->next = NULL;
	print();
	printf("\n\n--------After delete--------\n\n");
	delete_repetition();
	print();
	return 0;
}

