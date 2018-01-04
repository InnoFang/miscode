#include<stdio.h>
#include<stdlib.h>
typedef struct bin_tree{
	int data ;
	struct bin_tree * right, * left;
} node; 

/*插入*/
void insert(node ** tree, int val)
{
	node *temp = NULL;
	if(!(*tree))
	{
		temp = (node*)malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		return ;
	}
	if(val < (*tree)->data)
	{
		insert(&(*tree)->left, val);
	}
	else if(val > (*tree)->data)
	{
		insert(&(*tree)->right, val);
	}
}

/*前序遍历*/
void print_preorder(node * tree)
{
	if(tree)
	{
		printf("%d\n", tree->data);
		print_preorder(tree->left);
		print_preorder(tree->right);
	}	
} 

/*中序遍历*/
//void print_inorder(node * tree)
//{
//	if(tree)
//	{
//		print_inoreder(tree->left);
//		printf("%d\n", tree->data);
//		print_inorder(tree->right);
//	}
//}

/*后序遍历*/
//void print_postorder(node * tree)
//{
//	if(tree)
//	{
//		print_postorder(tree->left);
//		print_postorder(tree->right);
//		printf("%d\n", tree->data);
//	}
//}
//
/*将树销毁*/
void deltree(node * tree)
{
	if(tree)
	{
		deltree(tree->left);
		deltree(tree->right);
		free(tree);
	}
}

/*搜索*/
node* search(node ** tree, int val)
{

	if(!(*tree))
	{
		return NULL;
	}
	
	if(val < (*tree)->data)
	{
		search(&(*tree)->left, val);
	}
	else if(val > (*tree)->data)
	{
		search(&(*tree)->right, val);
	}
	else if(val == (*tree)->data)
	{
		return *tree;
	}
}

int main()
{
	node *root;
	node *tmp;
	root = NULL;
	
	/*inserting nodes into tree*/
	insert(&root, 9);
	insert(&root, 4);
	insert(&root, 15);
	insert(&root, 6);
	insert(&root, 12);
	insert(&root, 7);
	insert(&root, 2);
	
	/*printing node of tree*/
	printf("Pre Order Display\n");
	print_preorder(root);

//	printf("In Order Display\n");
//	print_inorder(root);
//	
//	pritnf("Post Order Display\n");
//	print_postorder(root);
//	
//	/*Search node into tree*/
//	tmp = search(&root, 4);
//	if(tmp)
//	{
//		printf("Searched node = %d\n", tmp->data);	
//	}	
//	else
//	{
//		printf("Data Not Found in Tree\n");	
//	}
//	
//	/*Deleting all nodes of tree*/
//	deltree(root);
//	return 0;
}
