#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct
{
	int list[MAX_SIZE];
	int last;	
} SeqList;
/*顺序表的初始化 将L设为指针参数，首先动态分配存储空间，然后，将表中last 指针置为－1，表示表中没有数据元素*/

SeqList* init_SeqList()
{
	SeqList *l;
	l = (SeqList*)malloc(sizeof(SeqList));
	l->last = -1;
	return l;  
}
/*
 插入运算
(1) 将ai～an 顺序向下移动，为新元素让出位置；
(2) 将x 置入空出的第i个位置；
(3) 修改last 指针(相当于修改表长)，使之仍指向最后一个元素。
本算法中注意以下问题：
(1) 顺序表中数据区域有MAXSIZE个存储单元，所以在向顺序表中做插入时先检查表空间是否满了，在表满的情况下不能再做插入，否则产生溢出错误。
(2) 要检验插入位置的有效性，这里i 的有效范围是：1<=i<=n+1，其中n 为原表长。
(3) 注意数据的移动方向。
*/
int insert_SeqList(SeqList *l, int i, int x)
{
	int j;
	if(l->last == MAX_SIZE - 1)/*表空间已满，不能插入*/
	{
		printf("It's full!");
		return  -1;
	}
	if(i < 1 || i > l->last + 2)/*检查插入位置的正确性,不能小于第一个和最后一个的后一个位置*/
	{
		printf("Insert error!");
		return 0;
	}
	for(j = l->last; j >= i - 1; j--)
	{
		l->list[j+1] = l->list[j];	/* 结点移动*/
	}
	l->list[i-1] = x;/*新元素插入*/
	l->last++;/*last仍指向最后元素*/
	return 1;/*插入成功，返回*/
}
/*
删除运算
(1) 将ai+1～an 顺序向上移动。
(2) 修改last指针(相当于修改表长)使之仍指向最后一个元素。
本算法注意以下问题：
（1）删除第i个元素，i的取值为1<=i<=n ,否则第i个元素不存在，因此，要检查删除位置的有效性。
（2）当表空时不能做删除，因表空时L->last的值为-1，条件（i<1 || i>L->last+1）也包括了对表空的检查。
（3）删除ai 之后，该数据已不存在，如果需要，先取出ai ，再做删除
*/
int delete_SeqList(SeqList *l, int i)
{
	int j;
	if(i < 1|| i > l->last + 1)/*检查空表及删除位置的合法性*/
	{
		printf("It does not exist!");
		return -1;
	}
	for(j = i; j <= l->last; j++) /*向上移动*/
	{
		l->list[j-1] = l->list[j];
	}
	l->last--;
	return 1;/*删除成功*/
}
/*按值查找
线性表中的按值查找是指在线性表中查找与给定值x相等的数据元素。
在顺序表中完成该运算最简单的方法是：从第一个元素a1 起依次和x比较，
直到找到一个与x相等的数据元素，则返回它在顺序表中的存储下标或序号（二者差一）；
或者查遍整个表都没有找到与x 相等的元素，返回-1*/
int local_SeqList(SeqList *l, int x)
{
	int j;
	for(j = 0; j <= l->last; j++)
	{
		if(l->list[j] == x)
		{
			printf("%d's index is %d\n",x,j+1);
			return 1;
		}
	}
	if(j > l->last)
	{
		return -1;
	}
//  int i=0;
//	while(i<=L.last && L->data[i]!= x)
//	i++;
//	if (i>L->last) return -1;
//	else return i; /*返回的是存储位置*/
}
int main()
{
	SeqList *l;
	l = init_SeqList();
	int i, j, n;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&l->list[i]);
	}
	l->last = n;	
	insert_SeqList(l, 2, 5);
	printf("After inserted:\n");
	for(i = 0; i < l->last; i++)
	{
		printf("%d ",l->list[i]);
	}
	printf("\n");
	delete_SeqList(l, 3);
	printf("After deleted:\n");
	for(i = 0; i < l->last; i++)
	{
		printf("%d ",l->list[i]);
	}
	printf("\n");
	printf("Search the '5'...\n");
	local_SeqList(l, 5);
	return 0;
}
