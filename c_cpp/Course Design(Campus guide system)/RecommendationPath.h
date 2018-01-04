/*多个景点的最佳路径推荐*/
#ifndef _RECOMMENDATION_PATH_H_
#define _RECOMMENDATION_PATH_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "AdjacencyMatrix.h"	/*邻接矩阵定义与创建*/
#include "SpotsSearchQuery.h"   /*景点寻路查询，两点间最短路查询*/

#define INFINITY 65535 // 表示无穷大
#define MAX 15 // 表示结点或者边的最大值 

//观光路径推荐
int haveChosen[MAX]; // 已经被选择的景点 
int choose[MAX]; 	//要去的景点栈 
int choose_top = -1; 		 // 景点栈顶 
int visit[MAX]; 
int dfsOrder[MAX]; // 根据dfs遍历顺序排序客户用户输入的结点 
int dfsOrder_top = -1;	// dfs遍历顺序栈栈顶 
int path[MAX] = {0}; // 推荐路径 
int path_top = -1;	// 推荐路径栈栈顶 
int distance = 0; // 总路径，和总距离 

int isInChoose(int i) // 判断结点是否是用户选择的结点, 是返回1，不是返回0 
{
	int j;
	for(j = 0; j <= choose_top; j++)
	{
		if(choose[j] == i)
		{
			return 1;
		}
	}
	return 0;
} 

// 邻接矩阵的深度优先搜索递归算法，利用DFS为用户选择的结点排序 
void dfs(Mgraph *g, int i)
{
	int j;
	visit[i] = 1;
	if(isInChoose(i)) // 如果是用户选的结点则放入DFS顺序栈中 
		dfsOrder[++dfsOrder_top] = i;
	for(j = 0; j < g->vertexNum; j++)
	{
		if(g->edges[i][j].weight != 0 && g->edges[i][j].weight != INFINITY && !visit[j])
		{
			dfs(g, j);
		}
	}
}

void getPath(Mgraph *g, int p[], int d[], int start, int end) // 获取从start到end的最短路径 
{
	int st[MAX], i, pre, top = -1; // 定义栈st并初始化空栈
	distance += d[end]; // 保存start到end两点的最短距离 
	st[++top] = start;
	pre = p[end];
	while(pre != -1)
	{
		st[++top] = pre;
		pre = p[pre];	
	}	
	while(top > 0)
		path[++path_top] = st[top--];  // 保存start到end的最短路径 
	if(start == end)	// start等于end的情况及为已经走到最后一个点的情况，这时把到end的路作为最后的路径 
		path[++path_top] = end;
}
void recommendation() // 推荐路径搜索 
{
	int i; 		
	int p[MAX] = {0}; // 保存路径 
	int d[MAX] = {0}; // 保存距离 
	dfs(g, 0); /*利用dfs找到景点的dfs顺序栈*/
	putchar('\n');
	for( i = 0; i < dfsOrder_top; i++) // 求dfs顺序栈中，两相邻结点的最短距离，并记录结点信息 
	{
		memset(p, 0, sizeof(p)); // 路径数组初始化 
		memset(d, 0, sizeof(d)); // 距离数组初始化 
		dijkstra(g, dfsOrder[i], p, d); // 利用Dijkstra找到最短路 
		getPath(g, p, d, dfsOrder[i], dfsOrder[i + 1]); // 获取指定的最短路 
	}
	dijkstra(g, dfsOrder[i], p, d); // 循环过后，还剩最后一个景点没有查找，继续利用Dijkstra查找最短路 
	getPath(g, p, d, dfsOrder[i], dfsOrder[i]); // 获取最短路 
	printf("\t"); 
	for(i = 0; i <= path_top; i++) // 输出推荐路径 
	{
		printf("%s", g->vexs[path[i]].name);
		if(i < path_top)
			printf(" ==》 ");	
	} 
	putchar('\n');
	printf("\n\t全程距离为%d米", distance); // 输出全程距离 
}

void recommendationPath()
{ 
	puts("\n\n\t\t\t\t观    光    路    径    推     荐"); 
	puts("\t\t\t    =========================================\n"); 
	puts("\t0. 德怀楼\t1. 柏林园\t2. 二龙山\t3. 科艺苑\t4. 文瀛餐厅");
	puts("\t5. 红房子\t6. 体育场\t7. 图书馆\t8. 行知广场\t9. 璟瑜国际会议中心");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("\t\t\t     Tips:数字选中，退位键取消选中，回车执行"); 
	int order = -1;	// 获取选择的景点序号 
	int k; // 键盘输入 
	int i;
	memset(haveChosen, 0, sizeof(haveChosen)); // 初始化已经选择景点数组 
	choose_top = -1;
	while((k = getch())!= 27 && k != 13) // 点击ESC或Enter停止选择， 
	{
		system("cls"); // 清屏 
		if(k == 8) // 当点击BackSpace(ASCII为8)键时，已选景点栈栈顶退出，已选景点置零，若为空，则不操作
		{
			haveChosen[choose[choose_top--]] = 0;	
		}
		//将点击的键减去48即得到一个新值，若为数字(数字0~9的ASCII为48~57)，则会得到对应的整型数字 
		order = k - 48; 
		// 判断用户的选择是否是数字键 
		if(order >= 0 && order <= 9 && haveChosen[order] == 0) // 是数字，并且该景点没有被选过 
		{
			haveChosen[order] = 1; //  标记该景点已经选过了 
			if(choose_top < g->vertexNum - 1) // 加入已选景点栈 
			{
				choose[++choose_top] = order;
			}
		} 
		// 更新用户的选择 
		puts("\n\n\t\t\t\t观    光    路    径    推     荐"); 
		puts("\t\t\t    =========================================\t\t\t\t\n"); 
		haveChosen[0] == 0 ? printf("\t0. 德怀楼") : printf("");
		haveChosen[1] == 0 ? printf("\t1. 柏林园") : printf("");
		haveChosen[2] == 0 ? printf("\t2. 二龙山") : printf("");
		haveChosen[3] == 0 ? printf("\t3. 科艺苑") : printf("");
		haveChosen[4] == 0 ? printf("\t4. 文瀛餐厅") : printf("");
		haveChosen[5] == 0 ? printf("\t5. 红房子") : printf("");
		haveChosen[6] == 0 ? printf("\t6. 体育场") : printf("");
		haveChosen[7] == 0 ? printf("\t7. 图书馆") : printf("");
		haveChosen[8] == 0 ? printf("\t8. 行知广场") : printf("");
		haveChosen[9] == 0 ? printf("\t9. 璟瑜国际会议中心") : printf("");
		puts("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
		printf("\n    您已选择：\n\t");
		for(i = 0 ; i <= choose_top ; i++) // 显示用户选择的所有节点 
		{
			printf("%s  ", g->vexs[choose[i]].name);
		}
	}
	if(k == 13) // 当用户点击了Enter出车键执行推荐路径算法 
	{ 
		puts("\n\n    为您推荐最佳路径：");
		memset(visit, 0, sizeof(visit));
		memset(dfsOrder, 0, sizeof(dfsOrder)); // 根据dfs遍历顺序排序客户用户输入的结点 
		dfsOrder_top = -1;	
		memset(path, -1, sizeof(path)); // 总路径栈初始化 
		path_top = -1;
		distance = 0; // 总距离初始化 
		recommendation();
	}
		
}

#endif
