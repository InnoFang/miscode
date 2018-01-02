/*判断一个单链表中的各个结点值是否有序*/
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct link_node{
	datatype info;
	struct link_node *next;
} node;

void print_list(node *head)
{
	node *p = head;
	while(p)
	{
		printf("%d\t", p->info);
		p = p->next;
	}
	printf("\n");
}

int isOrder(node *head)
{
	int flag = 1;	/*判断链表是降序还是升序, 1：升序，0：降序*/
	int result;
	node *p = head->next, *q = head;
	while(p)
	{
		/*先判断升序*/
		if(p->info > q->info)
		{
			result = 1;
		}
		else 
		{
			result = 0; 
			break;
		}
		q = p;
		p = p->next;
	}
	if(result == 0)
	{
		node *p = head->next, *q = head;
		while(p)
		{
			/*判断降序*/ 
			if(p->info < q->info)
			{
				result = 1;
			}
			else 
			{
				result = 0; 
				break;
			}
			q = p;
			p = p->next;
		}	
	}
	return result;
}
int main()
{
	node *first = (node*)malloc(sizeof(node));
	node *head = first; 
	node *curr = first;	/*当前结点*/ 
	datatype data;	/*数据获取*/ 
	int flag = 1;	/*判断第一个结点是否有值*/
	while(scanf("%d", &data) != EOF && data != 0)
	{
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
	print_list(head);
	if(isOrder(head))
	{
		printf("有序\n");
	}
	else
	{
		printf("无序\n");
	}
	return 0;	
} 
