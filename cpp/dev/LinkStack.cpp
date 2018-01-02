/*ÊµÀý£º½øÖÆ×ª»»*/
#include<stdio.h>
#include<stdlib.h>
//Á´Õ» 
typedef struct node{
	int data;
	struct node *next;
} LinkStack;

//ÖÆ¿ÕÕ» 
LinkStack* init_stack()
{
	return NULL;
}

//ÅÐ¿ÕÕ»
int is_empty(LinkStack* top)
{
	if(top == NULL)
	{
		return 1;
	}
	return 0;
}

//ÈëÕ»
LinkStack* push_stack(LinkStack* top, int data)
{
	LinkStack* s;
//	if(is_empty(top))
//	{
//		init_stack();
//	}
	s = (LinkStack*)malloc(sizeof(LinkStack));
	if(NULL == s)
	{
		printf("It's fail to push!");
		return NULL;
	}
	s->data = data;
	s->next = top;
	top = s;
	return top;
}

//³öÕ» 
LinkStack* pop_stack(LinkStack* top, int *data)
{
	LinkStack* p;
//	if(is_empty(top))
//	{
//		return NULL;
//	}
	*data = top->data;
	p = top;
	top = top->next;
	free(p);
	return top;
}

int main()
{
	LinkStack* s;
	int n, m;
	while(scanf("%d%d",&n,&m) == 2)
	{
		s = init_stack(); 
		LinkStack* top = NULL;
		while(n)
		{
			top = push_stack(top, n%m);
			n /= m;
		}
		int x;
		while(top != NULL)
		{
			top = pop_stack(top,&x);
			printf("%d",x);
		}
		printf("\n");
	}
	return 0;	
}
/* ERROR*/
	//Ë³ÐòÕ» 
//#define maxn  1024
//typedef struct{
//	int data[maxn];
//	int top;
//}SeqStack;
//
////ÖÆ¿ÕÕ»
//SeqStack* init_stack()
//{	
//	SeqStack *s;
//	s = (SeqStack*)malloc(sizeof(SeqStack));
//	s->top = -1;	
//	return s;
//} 
//
////ÅÐ¿ÕÕ»
//int is_empty(SeqStack *s)
//{
//	if(s->top == -1)
//	{
//		return 1;	
//	}	
//	
//	return 0;
//} 
//
////ÈëÕ»
//int push_stack(SeqStack* s,int data)
//{
//	if(s->top == maxn - 1)
//	{
//		printf("It is full!");
//		return 0;
//	}
//	else
//	{
//		s = (SeqStack*)malloc(sizeof(SeqStack));
//		if(NULL == s)
//		{
//			printf("It is fail to push!");
//			return 0;
//		}
//		s->data[s->top++] = data;
//		return 1;
//	}		
//} 
//
////³öÕ»
//int pop_stack(SeqStack* s, int *data)
//{
//	if(is_empty(s))	
//	{
//		printf("Stack is empty!");
//		return 0;
//	}
//	*data = s->data[s->top];
//	s->top--;
//	return 1;
//} 
//
////È¡Õ»¶¥ÔªËØ
//int top_stack(SeqStack* s)
//{
//	if(is_empty(s))
//	{
//		printf("Stack is empty!");
//		return 0;		
//	}	
//	return s->data[s->top];
//} 
//
//int main()
//{
//	int n, m;
//	while(scanf("%d%d",&n,&m) == 2)
//	{
//		SeqStack *s;
//		s = init_stack();
//		while(n)
//		{
//			push_stack(s, n%m);
//			n /= m;
//		}
//		int x;
//		while(s->top != -1)
//		{
//			pop_stack(s, &x);
//			printf("%d",x);
//		}
//		printf("\n");
//	}
//	return 0;
//}
