#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxSize 100
/*线索二叉树类型定义*/
typedef char DataType;
typedef enum{
	Link, Thread
} PointerTag;

typedef struct Node/*结点类型*/
{
	DataType data;
	struct Node *lchild, *rchild;
	PointerTag ltag, rtag;
} BiThrNode;

typedef BiThrNode* BiThrTree;

/*函数声明*/
void CreateBitTree2(BitThrTree *T, char str[]);
int main()
{
	return 0;
}
void CreateBitTree2(BitThrTree *T, char str[])
{
	
}


