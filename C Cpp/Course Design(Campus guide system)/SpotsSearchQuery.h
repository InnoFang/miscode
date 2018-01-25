/*景点寻路查询*/
/*Dijkstra算法*/ 
#ifndef _SPOTS_SEARCH_QUERY_H
#define _SPOTS_SEARCH_QUERY_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "AdjacencyMatrix.h"	/*邻接矩阵定义与创建*/

#define INFINITY 65535 // 表示无穷大
#define MAX 15 // 表示结点或者边的最大值 

void dijkstra(Mgraph *g, int v0, int path[], int dist[])
{
	int i, k, v, min, x;
	int final[MAX]; // 表示当前元素是否已求出最短路径
	memset(final,  0, sizeof(final)); // 将final数组元素全部置0，即初始化所有节点皆为未访问
	for(v = 0; v < g->vertexNum; v++)
	{
		dist[v]	= g->edges[v0][v].weight;
		if(dist[v] < INFINITY && dist[v] != 0)
			path[v] = v0;  // 表示该结点的前驱结点为v0 
		else 
			path[v] = -1;  // 表示该结点无前驱结点 
	}	
	final[v0] = 1; // 当前结点到当前结点的路径已经找到
	dist[v0] = 0; // 路径长度为0
	for(i = 1; i < g->vertexNum; i++)
	{
		min = INFINITY; // 初识化最短路径 
		for(k = 0; k < g->vertexNum; k++)
		{
			if(!final[k]  && dist[k] < min) // 若该结点还未被选，并且路径小于min 
			{
				v = k;	 // 保存有最短顶点距离的顶点 
				min = dist[k];
			}
		}	
		if(min == INFINITY) // 如果该顶点距离是无穷大，即返回 
			return ;
		final[v] = 1; // v0到当前结点的最短路径已经找到
		for(k = 0; k < g->vertexNum; k++)
		{
			if(!final[k] && (min + g->edges[v][k].weight < dist[k]))	// 在未被选的顶点中还有 
			{
				dist[k] = min + g->edges[v][k].weight;
				path[k] = v;
			}
		} 
	} 
} 

void startToDest(Mgraph *g, int path[], int dist[], int start, int dest) 
{
	int st[MAX], i, pre, top = -1; // 定义栈st并初始化空栈
	printf("\n\t    行走路线:\n");
	st[++top] = dest;
	pre = path[dest];
	while(pre != -1)
	{
		st[++top] = pre;
		pre = path[pre];	
	}	
	printf("\t\t    ");
	while(top > 0)
		printf("%s ==》", g->vexs[st[top--]].name);
	printf("%s", g->vexs[dest].name);	
	putchar('\n');
 	printf("\n\t    全程距离：\n\t\t    %d米" , dist[dest]);
}

void spotsSearchQuery()
{
	int path[MAX], dist[MAX], i;
	int start = 0, dest = 0; // 获取用户输入的景点序号 
	puts(" ");
	puts("\t\t\t\t       【景 点 寻 路 查 询】\t\t\t\t\t"); 
	puts("\t\t\t\t0. 德怀楼\t┃\t5. 红房子\t\t\t\t");
	puts("\t\t\t\t1. 柏林园\t┃\t6. 体育场\t\t\t\t");
	puts("\t\t\t\t2. 二龙山\t┃\t7. 图书馆\t\t\t\t");
	puts("\t\t\t\t3. 科艺苑\t┃\t8. 行知广场\t\t\t");
	puts("\t\t\t\t4. 文瀛餐厅\t┃\t9. 璟瑜国际会议中心\t\t\t");
	puts(" "); 
	printf("\t\t\t\t请问您想从哪到哪呢？:-)\n");
	start = getch();
	if(start >= 48 && start <= 57) // 如果输入的是0 ~ 9 则显示相应的景点信息 
	{
		start -= 48; 
		printf("\t\t\t\t    %s\t==》\t", g->vexs[start].name);
		dijkstra(g, start, path, dist);
		while((dest = getch()) < 48 || dest > 57); // 等待用户输入正确序号
		dest -= 48;
  	    printf("%s\n", g->vexs[dest].name);
		puts("\t\t\t\t- - - - - - - - - - - - - - - - - - \t\t\t");
		puts("\t\t\t\t    为 您 提 供 最 短 路 径 \t\t\t");
		startToDest(g, path, dist, start, dest); // 输出最短路径 
	}
}

#endif
