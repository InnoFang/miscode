#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FINITY 5000		// 此处用5000表示无穷大
#define M 20	// 最大顶点数
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef char vertextype;	// 顶点值类型
typedef int edgetype; // 权值类型
typedef struct {
	vertextype vexs[M]; // 顶点信息域
	edgetype edges[M][M]; // 邻接矩阵
	int n, e; // 图中顶点总数和边数
} Mgraph;

void create(Mgraph *g, char *s, int c) // c == 0 表示创建无向图
{
	int i, j, k, w;
	FILE *rf;
	rf = fopen(s, "r");	// 从文件中读取图的边信息
	if (rf)
	{

		fscanf(rf, "%d%d", &g->n, &g->e); // 读入图的顶点数和边数
		for ( i = 0; i < g->n; i++) // 读入图中的顶点值
		{
			fscanf(rf, "%1s", &(g->vexs[i]));
		}
		for ( i = 0; i < g->n; i++) // 初始化邻接矩阵
		{
			for ( j = 0; j < g->n; j++)
			{
				if (i == j)
				{
					g->edges[i][j] = 0;
				}
				else
				{
					g->edges[i][j] = FINITY;
				}
			}
		}

		for ( k = 0; k < g->e; k++) // 读入网络中的边
		{
			fscanf(rf, "%d%d%d", &i, &j, &w);
			g->edges[i][j] = w;
			if (c == 0)
			{
				g->edges[j][i] = w;	// 建立无向图邻接矩阵
			}
		}
		fclose(rf);	// 关闭文件
	}
	else
	{

		g->n = 0;
	}
}


#define MAXVEX 100  // 最大顶点数
typedef int Boolean;
Boolean visited[MAXVEX]; // 访问标志数组
#define TRUE 1
#define FALSE 0

// 邻接矩阵的深度优先搜索递归算法
void dfs(Mgraph *g, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c ", g->vexs[i]); // 打印顶点，也可以是其他操作
	for(j = 0; j < g->n; j++)
	{
		if(g->edges[i][j] !=0 && g->edges[i][j] != FINITY && !visited[j])
		{
			dfs(g, j);	// 对为访问的邻接顶点递归调用
		}
	}
}

// 邻接矩阵的深度遍历操作
void DFSTraverse(Mgraph *g)
{
	int i;
	for(i = 0; i < g->n; i++)
	{
		visited[i] = FALSE;	
	}
	for(i = 0; i < g->n; i++)
	{
		if(!visited[i])
		{
			dfs(g, i);
		}
	}
}

#define ROOT 0 // 前序遍历树根节点 
int dfn[M]; // 根据DFS的搜索顺序，搜索到该点的前序遍历序号 
int low[M]; // 表示该顶点可到达的最小的序号 
int parent[M]; // 在前序遍历树中，每个结点对应的父节点 
int vis[M]; // 每个节点是否被访问过 
int DFSCount = 0; // 前序遍历序号 
int cutNum = 0; // 关节点总数 
int cut[M]; // 保存找到的关节点 
int stack[M]; // DFS顺序栈
int top = -1; // 栈顶 
 
// Tarjan算法 
void cut_dfs(Mgraph *g, int u) 
{
	int i;
	vis[u] = 1;
	int children = 0; // 记录结点u的子树
	dfn[u] = low[u] = DFSCount++;
	for(i = 0; i < g->n; i++)
	{
		int v ;
		if(g->edges[u][i] != 0 && g->edges[u][i] != FINITY) 
			v = i;
		else
			continue;
		printf("test: vertex=%c, dfn=%d, low=%d\n", g->vexs[u], dfn[u], low[u]);
		if(!vis[v])
		{
			children++;
 			parent[v] = u; // u是v的父节点 
			cut_dfs(g, v);
			low[u] = min(low[u], low[v]); // u结点的low为能到达的最小结点的编号
			if(parent[u] == 0 && children > 1) //u结点是根结点时该结点子树数大于1 
			{	
				cutNum++;
				cut[u] = 1; // 结点u为关节点 
				puts("#1");
			}
			if(parent[u] != 0 && low[v] >= dfn[u])//u结点不为根结点时，子节点的编号大于u能到达的最小编号 
			{
				cutNum++; 
				cut[u] = 1;// 结点u为关节点 
				puts("#2");
			}
		}	
		else if(parent[v] != u) // 若u的邻结点已经被访问，并且该邻结点不是u的父结点时,则(u,v)构成回边 
		{	
			printf("yes,parent[v] = %d, u = %d\n", parent[v], u);
			low[u] = min(low[u], dfn[v]);	
		} 
	} 
}

void cutPointQuery(Mgraph *g)
{
	int i;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(vis, 0, sizeof(vis));	// 初始化
	memset(parent, 0, sizeof(parent)); // 初始化父节点数组 
	memset(cut, 0, sizeof(cut)); // 初始化关节点数组 
//	parent[0] = -1; // 将编号0作为根结点 
	cut_dfs(g, 0);
	if(cutNum > 0)
	{
		printf("\t\t\t关节点个数为：%d，分别为\n", cutNum);
		for(i = 0; i < g->n; i++) // 遍历输出关节点 
		{	
			if(cut[i] == 1)
				printf("%c", g->vexs[i]); 
		}
	} 
	else
		printf("\t\t\t关节点个数为0，不存在关节点\n");
}
int main()
{
	int i;
	Mgraph *g = (Mgraph*)malloc(sizeof(Mgraph));
	create(g, "G7.txt", 0);
//	int i, j;
//	for(i = 0; i < g->n; i++)
//	{
//		for(j = 0; j < g->n; j++)
//		{
//			printfe("%d ", g->edges[i][j]);
//		}
//		printf("\n");
//	}
	dfs(g, 0) ;
//	printf("\n+------+\n");
//	DFSTraverse(g);

	/*求邻接矩阵无向图的关节点*/
//	cutPointQuery(g); 
//	for(i = 0; i < M; i++)
//		printf("%d ", parent[i]);
//	putchar('\n');
//	for(i = 0; i < M; i++)
//	{
//		if(cut[i] == 1)
//			printf("%c ", g->vexs[cut[i]]);
//	}
//	putchar('\n');
//	return 0;
}
/*
Input:

4 4
0123
0 1 56
0 2 34
0 3 78
2 3 25

Output:
0 1 2 3
*/
