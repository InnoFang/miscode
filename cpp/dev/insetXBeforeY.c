/*在单链表中值为y的结点前面插入一个值为x的结点*/
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

/*找到值为data的结点的前一个结点*/
node *findTheLast(node *head, datatype data)
{
	node *p = head;
	while(p->next && p->next->info != data)
	{
		p = p->next;
	}
	return p; 
}

/*在值为y的结点前面插入值为x的结点*/
node *insert(node *head, int y, int x)
{
	node *index;
	node *q;	/*要插入的结点*/
	index = findTheLast(head, y);
	if(NULL == index)
	{
		printf("找不到值为%d的结点\n", y);		
	}
	else 
	{
		q = (node*)malloc(sizeof(node));
		q->info = x;
		q->next = index->next;
		index->next = q;
		printf("q = %d\n", q->info);
	}
	return head;
}

int main()
{
	node *first = (node*)malloc(sizeof(node));
	node *head = (node*)malloc(sizeof(node));	/*头结点*/ 
	head->next = first;	
	node *curr = first;	/*当前结点*/ 
	node *a = NULL;	/*保存返回的结点*/
	datatype data;	/*数据获取*/ 
	int flag = 1;	/*判断第一个结点是否有值*/
	int y, x;	
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
	printf("请输入y结点和x结点的值\n"); 
	scanf("%d%d",&y,&x);
	insert(head, y, x);
	print_list(head);
	return 0;
}
