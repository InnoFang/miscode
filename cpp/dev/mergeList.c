/*求一个单链表中的结点个数*/
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct link_node{
	datatype info;
	struct link_node *next;
} node;

void print(node *head)
{
	node *p = head;
	while(p)
	{
		printf("%d\t", p->info);
		p = p->next;
	}
	printf("\n");
}

node *merge(node *head1, node *head2)
{
	node *p1 = head1, *p2 = head2;
	node *head;
	while(p1 && p2)
	{
		if(p1->info > p2->info)
		{
//			head
		}
	}
}

int main()
{
	node *first = (node*)malloc(sizeof(node));	/*第一个有序单链表*/
	node *second = (node*)malloc(sizeof(node));	/*第二个有序单链表*/
	node *head1 = first, *head2 = second; 
	node *curr = first;	/*当前结点*/ 
	node *head;	/*用于指向合并后的的链表*/
	int i, data;	/*数据获取*/ 
	int flag = 1;	/*判断第一个结点是否有值*/
	for(i = 0; i < 10; i++)
	{
		data = (i * 2) + 1;
		if(flag)
		{
			first->info = data;	
			flag = 0;
		}	
		else 
		{
			node *p = (node*)malloc(sizeof(node));
			if(NULL == p)
				break;
			p->info = data;
			p->next = NULL;
			curr->next = p;
			curr = p;
		}
	}
	curr = second;
	flag = 1;
	for(i = 1; i <= 10; i++)
	{
		data = i * 2;
		if(flag)
		{
			second->info = data;	
			flag = 0;
		}	
		else 
		{
			node *p = (node*)malloc(sizeof(node));
			if(NULL == p)
				break;
			p->info = data;
			p->next = NULL;
			curr->next = p;
			curr = p;
		}
	}
	print(head1);
	print(head2);
	printf("After merge:\n");
	head = merge(head1, head2);
//	print(head);
	return 0;	
} 
