//#include<stdio.h>
//#include<stdlib.h>
//#define M 20	// 预定义图的最大顶点数
//typedef char DataType; // 顶点信息数据类型
//
//typedef struct node{ // 边表结点
//	int adjvex;		// 邻接点
//	struct node *next;
//} EdgeNode;
//
//typedef struct vnode{ // 头结点类型
//	DataType vertex;	// 顶点信息
//	EdgeNode *FirstEdge; // 邻链接表头指针
//} VertexNode;
//
//typedef struct{		// 邻接表类型
//	VertexNode adjlist[M];	// 存放头结点的顺序表
//	int n, e;	// 图的顶点数与边数
//} LinkedGraph;
//
//void create(LinkedGraph *g, char *filename, int c)
//{
//	int i, j, k; // c == 0 表示创建无向图，否则表示创建有向图
//	EdgeNode *s;
//	FILE *fp;
//	fp = fopen(filename, "r");
//	if(fp)
//	{
//		fscanf(fp, "%d%d", &g->n, &g->e);	// 读入顶点数与边数
//		for(i = 0; i < g->n; i++)
//		{
//			fscanf(fp, "%1s", &g->adjlist[i].vertex); // 读入顶点信息
//			g->adjlist[i].FirstEdge = NULL;	 // 边表置为空表
//		}
//		for(k = 0; k < g->e; k++)		// 循环e次建立边表
//		{
//			fscanf(fp, "%d%d", &i, &j); // 输入无序对（i， j）
//			s = (EdgeNode*)malloc(sizeof(EdgeNode));
//			s->adjvex = j; 	// 邻接点序号为j
//			s->next = g->adjlist[i].FirstEdge;
//			g->adjlist[i].FirstEdge = s; // 将新结点*s插入顶点Vi的边表头部
//			if(c == 0)	// 无向图
//			{
//				s = (EdgeNode*)malloc(sizeof(EdgeNode));
//				s->adjvex = i; // 邻接点序号为i
//				s->next = g->adjlist[j].FirstEdge;
//				g->adjlist[j].FirstEdge = s; // 将新结点*s插入顶点Vj的边表头部
//			}
//		}
//		fclose(fp);
//	}
//	else
//	{
//		g->n = 0;	// 文件打开失败
//	}
//}
//
//#define MAXVEX 100  // 最大顶点数
//typedef int Boolean;
//Boolean visited[MAXVEX]; // 访问标志数组
//#define TRUE 1
//#define FALSE 0
//
//// 邻接表的深度递归算法
//void dfs(LinkedGraph *g, int i)
//{
//	EdgeNode *p;
//	visited[i] = TRUE;
//	printf("%c ", g->adjlist[i].vertex);	// 打印顶点，也可以其他操作
//	p = g->adjlist[i].FirstEdge;
//	while(p)
//	{
//		if(!visited[p->adjvex])
//		{
//			dfs(g, p->adjvex); // 对访问的邻接点递归调用
//		}
//		p = p->next;
//	}
//}
//
//// 邻接表的深度遍历操作
//void DFSTraverse(LinkedGraph *g)
//{
//	int i;
//	for(i = 0; i < g->n; i++)
//	{
//		visited[i] = FALSE;
//	}
//	for(i = 0; i < g->n; i++)
//	{
//		if(!visited[i])
//		{
//			dfs(g, i);
//		}
//	}
//}
//
//
//void bfs(LinkedGraph *g, int i)
//{
//	int j;
//	EdgeNode *p;
//	int queue[M], front, rear;	// FIFO队列
//	front = rear = 0;	// 初始化空队列
//	printf("%c ", g->adjlist[i].vertex); // 访问源点v
//	visited[i] = TRUE;
//	queue[rear++] = i; // 被访问结点进队
//	while(rear > front) // 当队列非空时，执行下列循环体
//	{
//		j = queue[front++]; // 出队
//		p = g->adjlist[i].FirstEdge;
//		while(p)	// 广度优先搜素邻接表
//		{
//			if(visited[p->adjvex] == 0)
//			{
//				printf("%c ", g->adjlist[p->adjvex].vertex);
//				queue[rear++] = p->adjvex;
//				visited[p->adjvex] = 1;
//			}
//			p = p->next;
//		}
//	}
//}
//
//int BFSTraverse(LinkedGraph *g)
//{
//	int i, count = 0;
//	for(i = 0; i < g->n; i++)
//	{
//		visited[i] = 0;
//	}
//	for(i = 0; i < g->n; i++)
//	{
//		if(!visited[i])
//		{
//			//printf("\n");
//			count++;
//			bfs(g, i);
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int i;
//	LinkedGraph *g = (LinkedGraph*)malloc(sizeof(LinkedGraph));
//	create(g, "G7_.txt", 0);
//	printf("\n+=======深度优先搜索========+\n");
//	printf("|----邻接表的深度递归算法---|\n");
//	printf("|         ");dfs(g, 0);printf("          |");
//	printf("\n|----邻接表的深度遍历操作---|\n");
//	printf("|         ");DFSTraverse(g);printf("          |");
//	printf("\n+===========================+\n");
//
//
//	for(i = 0; i < M; i++)
//	{
//		visited[i] = FALSE;
//	}
//
//	printf("\n+=======广度优先搜索========+\n");
//	printf("|----邻接表的深度递归算法---|\n");
//	printf("|         ");bfs(g, 0);printf("          |");
//	printf("\n|----邻接表的深度遍历操作---|\n");
//	printf("|         ");BFSTraverse(g);printf("          |");
//	printf("\n+===========================+\n");
//	return 0;
//}
///*
//Input:
//
//4 4
//0123
//0 1
//0 2
//0 3
//2 3
//
//Output:
//0 3 2 1
//*/

#include<stdio.h>
#include<stdlib.h>
#define M 20
typedef char datatype;

typedef struct node{
  int adjvex;
  struct node *next;
} edgenode;

typedef struct vnode{
  datatype vertex;
  edgenode *firstedge;
} vertexnode;

typedef struct {
  vertexnode adjlist[M];
  int v, e;
} graph;

void create_graph(graph *g, int c){
  int i, j, k;
  edgenode *s;
  scanf("%d%d", &g->v, &g->e);
  for(i = 0; i < g->v; i++)
  {
    scanf("%d", &g->adjlist[i].vertex);
    g->adjlist[i].firstedge = NULL;
  }
  for(k = 0; k < g->e; k++)
  {
    scanf("%d%d", &i, &j);
    s = (edgenode*)malloc(sizeof(edgenode));
    s->adjvex = j;
    s->next = g->adjlist[i].firstedge;
    g->adjlist[i].firstedge = s;
    if (c == 0) {
      s = (edgenode*)malloc(sizeof(edgenode*));
      s->adjvex = i;
      s->next = g->adjlist[j].firstedge;
      g->adjlist[j].firstedge = s;
    }
  }
} 
  int visited[M] = {0};
  void dfs(graph *g, int i)
  {
      edgenode *s;
      visited[i] = 1;
      printf("%d ", g->adjlist[i].vertex);
      s = g->adjlist[i].firstedge;
      while(s)
      {
        if (!visited[s->adjvex]) {
          dfs(g, s->adjvex);
        }
        s = s->next;
      }
  }
  void DFSTraverse(graph *g)
  {
    int i;
    for ( i = 0; i < g->v; i++) {
      visited[i] = 0;
    }
    for ( i = 0; i < g->v; i++) {
      if (!visited[i]) {
            dfs(g, i);
      }
    }
  }

  void bfs(graph *g , int i)
  {
    int j;
    edgenode *s;
    int queue[M], rear, front;
    rear = front = 0;
    visited[i] = 1;
    queue[rear++] = i;
    printf("%d ", g->adjlist[i].vertex);
    while(rear > front)
    {
      j = queue[front++];
      s = g->adjlist[i].firstedge;
      while(s)
      {
        if (!visited[s->adjvex]) {
          printf("%d ", s->adjvex);
          queue[rear++] = s->adjvex;
          visited[s->adjvex] = 1;
        }
        s = s->next;
      }
    }
  }

  int BFSTraverse(graph *g)
  {
    int i, j, count = 0;
    for ( i = 0; i < g->v; i++) {
      visited[i] = 0;
    }
    for ( j = 0; j < g->v; j++) {
      if (!visited[g->adjlist[j].vertex]) {
        count++;
        bfs(g, g->adjlist[j].vertex);
      }
    }
    return count;
  }


int main()
{
	graph *g = (graph*)malloc(sizeof(graph));
	create_graph(g, 0);
	//bfs(g, 0);
	int b = BFSTraverse(g);
	//DFSTraverse(g);
	printf("\n共有 %d 个连通分量\n", b);
	return 0;
}
/*
Eg1:

4 4
0 1 2 3
0 1
0 2
0 3
2 3

Eg2:
6 7
0 1 2 3 4 5
0 1
0 2
1 3
3 4
1 4
4 5
5 2

*/ 
