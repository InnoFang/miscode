/*求一个带头结点的单链表中的结点个数*/
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct link_node{
	datatype info;
	struct link_node *next;
} node;

void print_list(node *head)
{
	node *p = head->next;
	while(p)
	{
		printf("%d\t", p->info);
		p = p->next;
	}
	printf("\n");
}

int node_number(node *head)
{
	int num = 0;
	node *p = head->next;
	while(p)
	{
		num++;
		p = p->next;
	}
	return num;
}

int main()
{
	node *first = (node*)malloc(sizeof(node));
	node *head = (node*)malloc(sizeof(node));	/*头结点*/ 
	head->next = first;
	node *curr = first;	/*当前结点*/ 
	datatype data;	/*数据获取*/ 
	int flag = 1;	/*判断第一个结点是否有值*/
	while(scanf("%d", &data) != EOF && data != 0)
	{
		if(flag)
		{
			first->info = data;	
			first->next = NULL;
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
	print_list(head);
	printf("结点数为%d\n", node_number(head));
	return 0;	
} 
