//combine list A an list B,The premise is that the two list is in ascending order
#include<stdio.h>
#include<stdlib.h>
typedef struct s{
	int id;
	struct s *next;
}Linklist;

Linklist *HA = NULL;
Linklist *HB = NULL;

Linklist* create_A()
{
	Linklist *p1, *p2;
	p1 = p2 = (Linklist*)malloc(sizeof(Linklist));
	scanf("%d",&p1->id);
	while(p1->id != 0)
	{
		if(HA == NULL)
			HA = p1;
		else	
			p2->next = p1;
		p2 = p1;
		p1 = (Linklist*)malloc(sizeof(Linklist));
		scanf("%d",&p1->id);
	}
	p2->next = NULL;
	return HA;
}

Linklist* create_B()
{
	Linklist *p1, *p2;
	p1 = p2 = (Linklist*)malloc(sizeof(Linklist));
	scanf("%d",&p1->id);
	while(p1->id != 0)
	{
		if(NULL == HB)
			HB = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (Linklist*)malloc(sizeof(Linklist));
		scanf("%d",&p1->id);
	}
	p2->next = NULL;
	return HB;
}

void combine()
{
	void print(Linklist *H);
	Linklist *C, *p1, *p2, *s;
	p1 = HA, p2 = HB;
	C->next = NULL;
	while(p1&&p2)
	{
		if(p1->id < p2->id)
		{
			s = p1;
			p1 = p1->next;
		}	
		else
		{
			s = p2;
			p2 = p2->next;
		}		
		s->next = C->next;
		C->next = s;
	}
	if(NULL == p1)
		p1 = p2;
	while(p1)
	{
		s = p1;
		p1 = p1->next;
		s->next = C->next;
		C->next = s;
	}
	print(C->next);
}
void print(Linklist *H)
{
	printf("\n--------printing start--------\n");
	if(NULL == H)
		return ;
	Linklist *p = H;
	while(p)
	{
		printf("%d\n",p->id);
		p = p->next;
	}
	printf("\n--------printing end--------\n");	
}

int main()
{
	printf("input A\n");
	create_A();
	printf("input B\n");
	create_B();
	printf("print A\n");
	print(HA);
	printf("print B\n");
	print(HB);
	printf("\n\n--------After combine A and B--------\n\n");
	combine();
	return 0;
}
//1 3 5 7 9 0
//2 4 6 8 10 0
