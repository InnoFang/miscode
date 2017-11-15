/*景点路径查询，两点间所有路*/
#ifndef _ALL_PATH_QUERY_H_
#define _ALL_PATH_QUERY_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "AdjacencyMatrix.h"	/*邻接矩阵定义与创建*/

#define INFINITY 65535 // 表示无穷大
#define MAX 15 // 表示结点或者边的最大值 

int path[MAX]; // 两点之间路径
int top = -1; // path的顶端
int num = 0; // 路径总数 
// 判断一个顶点是否是在该该路径中 
int isInPath(int vertex)
{
	int i;
	for(i = 0; i < top; i++)
	{
		if(path[i] == vertex)
			return 1;
	}
	return 0;
}
// 输出两点之间所有路径 
void allPathStartToDest(int vertex, int dest)
{
	int i;
	if(isInPath(vertex)) // 若该结点已经在路径中存在则直接返回 
	{
		return ;
	}
	if(vertex == dest) // 若当前结点就是目的地，则输出
	{
		num++; 
		printf("\n    路径%d:  ", num);
		for(i = 0; i <= top; i++)
		{
			printf("%s ==》", g->vexs[path[i]].name);
		}
		printf("%s", g->vexs[vertex].name);
	} 
	else
	{
		for(i = 0; i < g->vertexNum; i++)
		{	
			if(g->edges[vertex][i].weight != 0 && g->edges[vertex][i].weight != INFINITY) // 符合邻接点要求，并且不在路径中，也没被访问过 
			{	
				path[++top] = vertex; // 符合要求加入路径中
				allPathStartToDest(i, dest);
				top--; 		
			}
		}
	}
}

//景点路径查询 
void allPathQuery()
{
	int i, j;
	int start = 0, dest = 0; // 获取用户输入的景点序号 
	puts(" ");
	puts("\t\t\t\t\t 景 点 路 径 查 询\t\t\t\t\t"); 
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
		while((dest = getch()) < 48 || dest > 57); // 等待用户输入正确序号
		dest -= 48;
  	    printf("%s\n", g->vexs[dest].name);
		puts("\t\t\t\t- - - - - - - - - - - - - - - - - - \t\t\t");
		puts("\t\t\t\t      为 您 提 供 所 有 路 径 \t\t\t");
		memset(path, -1, sizeof(path));
		top = -1;
		num = 0;
		allPathStartToDest(start, dest); // 输出两点之间所有路径 
	}	
} 
#endif
