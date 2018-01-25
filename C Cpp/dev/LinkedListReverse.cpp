//linked List reverse
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

void reverse()
{
	Student *p1, *p2;
	p1 = p2 = head;
	head = NULL;
	while(p1)
	{
		p2 = p1;
		p1 = p1->next;
		p2->next = head;
		head = p2;
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
	printf("\n\n--------After reverse--------\n\n");
	reverse();
	print();
	return 0;
}

