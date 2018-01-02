/*将一个结点值为自然数的单链表拆分为两个单链表，原表中保留值为偶数
的结点，而值为奇数的结点按它们在原表中的相对次序组成一个新的单链表*/
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct link_node{
	datatype info;
	struct link_node *next;
} node;

void print(node *head)
{
	node *p = head->next;
	while(p)
	{
		printf("%d\t", p->info);
		p = p->next;
	}
	printf("\n");
}

void divide(node *head, node *odd)
{
	node *p = head->next;
	node *pre = head;	
	node *q;
	int flag = 1; /*判断结点是否是奇数链表head的指向*/
	while(p)
	{
		if(p->info % 2)
		{
			p = p->next;
			if(flag)
			{
				odd->next = pre->next;
				pre->next = pre->next->next;
				odd->next->next = NULL;
				q = odd->next;
				flag = 0;
			}
			else
			{
				q->next = pre->next;
				pre->next = pre->next->next;
			 	q->next->next = NULL;
				q = q->next;
			}
		}
		pre = p; 
		p = p->next; 
	}
}

int main()
{
	node *head = (node*)malloc(sizeof(node));
	node *odd = (node*)malloc(sizeof(node));
	node *p = (node*)malloc(sizeof(node));
	node *curr = p, *q;
	head->next = p;
	p->info = 1;
	int i;
	for(i = 2; i <= 20; i++)
	{
		q = (node*)malloc(sizeof(node));
		q->info = i;
		q->next = NULL;
		curr->next = q;
		curr = q;
	}
	print(head);
	divide(head, odd);
	printf("even number :\n");
	print(head);
	printf("odd number :\n");
	print(odd);
	return 0;	
} 
