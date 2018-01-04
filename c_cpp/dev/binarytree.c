#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct BiTNode{
	datatype data;
	struct BiTNode *lchild, *rchild;
} bitnode;
/*顺序栈*/
typedef struct sttacl{
	bitnode* data[100];
	int tag[100];
	int top;
} seqstack;

/*进栈*/
void push(seqstack *s, bitnode *t)
{
	s->data[s->top] = t;
	s->top++;
}

/*出栈*/ 
bitnode* pop(seqstack *s)
{
	if(s->top != 0)
	{
		s->top--;
		return (s->data[s->top]);
	}
	else
	{
		return NULL;
	}
}

bitnode *createBiTree()
{
	bitnode *t;
	datatype ch;
	scanf("%c", &ch);
	if(ch == '#')
		t = NULL;
	else 
	{
		t = (bitnode*)malloc(sizeof(bitnode));
		if(!t)
		{
			printf("结点创建失败");
			return NULL;
		}
		t->data = ch;
		t->lchild = createBiTree();
		t->rchild = createBiTree();
	}
	return t;
} 

/*递归前序遍历*/
void preorder(bitnode *t)
{
	if(t)
	{
		printf("%c ",t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

/*递归中序遍历*/
void inorder(bitnode *t)
{
	if(t)
	{
		inorder(t->lchild);
		printf("%c ",t->data);
		inorder(t->rchild);			
	}
}

/*递归后序遍历*/ 
void postorder(bitnode *t)
{
	if(t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%c ",t->data);
	}
}

/*非递归前序遍历*/
void preorder1(bitnode *t)
{
	seqstack s;
	s.top = 0;
	while((t) || (s.top != 0))
	{
		if(t)
		{
			printf("%c ", t->data);
			push(&s, t);
			t = t->lchild;
		}
		else 
		{
			t = pop(&s);
			t = t->rchild;
		}
	}
}


/*非递归中序遍历*/
void inorder1(bitnode *t)
{

	seqstack s;
	s.top = 0;
	while(t || s.top != 0)
	{
		if(t)
		{
			push(&s, t);
			t = t->lchild;
		}
		else 
		{
			t = pop(&s);
			printf("%c ", t->data);
			t = t->rchild;
		}
	}
} 

/*非递归后序遍历*/
void postorder1(bitnode *t)
{
	seqstack s;
	s.top = 0;
	while(t || s.top != 0)
	{
		if(t)
		{
			s.data[s.top] = t;
			s.tag[s.top] = 0;	
			s.top++;
			t = t->lchild;
		} 
		else 
		{
			if(s.tag[s.top - 1] == 1)
			{
				t = s.data[--s.top];	//这里的s.top必须先减再进行操作 
				printf("%c ", t->data);	
				t = NULL;
			}	
			else 
			{
				t = s.data[s.top - 1]; 
				s.tag[s.top - 1] = 1;
				t = t->rchild;
			}
		}
	} 
}

int countLeaf(bitnode *t)
{
	if(!t)
		return 0;
	if(!t->rchild && !t->lchild)	//某个节点的左子树及右子树都为空，则为叶子结点 
		return 1;
	else
		return countLeaf(t->lchild) + countLeaf(t->rchild);
}

int countLeaf1(bitnode *t){
	int sum = 0;
	seqstack s;
	s.top = 0;
	while((t) || (s.top != 0))
	{
		if(t)
		{
//			printf("%c ", t->data);
			push(&s, t);
			t = t->lchild;
		}
		else 
		{
			t = pop(&s);
			if(!t->rchild && !t->lchild)	//某个节点的左子树及右子树都为空，则为叶子结点 
				sum += 1;
			t = t->rchild;
			
		}
	}
	return sum;
} 

/*

			a
	b				C
d		e		f		g

input : abd##e##cf##g##
*/

int main()
{
	bitnode *root = createBiTree();
	printf("\n+------递归前序遍历------+\n");
	preorder(root);	//a b d  e c f g
	printf("\n+------递归中序遍历------+\n");
	inorder(root);	//d b e a f c g
	printf("\n+------递归后序遍历------+\n");
	postorder(root);//d e b f g c a	
	
	
	printf("\n+------非递归前序遍历------+\n");
	preorder1(root);	//a b d e c f g
	printf("\n+------非递归中序遍历------+\n");
	inorder1(root);	//d b e a f c g
	printf("\n+------非递归后序遍历------+\n");
	postorder1(root);//d e b f g c a	
	printf("\nleaf's number : %d\n", countLeaf(root));
	printf("leaf's number2 : %d", countLeaf1(root));
	return 0;	
}
