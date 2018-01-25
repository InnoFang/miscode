/*景点关节点查询*/
#ifndef _CUT_POINT_QUERY_H_
#define _CUT_POINT_QUERY_H_
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "AdjacencyMatrix.h"	/*邻接矩阵定义与创建*/

#define INFINITY 65535 // 表示无穷大
#define MAX 15 // 表示结点或者边的最大值 
#define ROOT 2 // 前序遍历树根节点 

int visi[MAX]; 
int cut[MAX];	// 存储关节点 
int cutNum = 0; // 是否有关节点 
void dfs_cut(Mgraph *g, int i)
{
	int j;
	if(visi[i] != ROOT)
		visi[i] = 1;
	int child = 0;
	for(j = 0; j < g->vertexNum; j++)
	{  
		if(g->edges[i][j].weight != 0 && g->edges[i][j].weight != INFINITY && !visi[j])
		{	
			child++; 
			dfs_cut(g, j);
		}
	}
	if(visi[i] == ROOT && child >= 2) // 若该点是根，并且有大于等于2的子树，则为关节点 
	{
		cutNum++; // 关节点总数加一 
		cut[i] = 1;	// 对该点标记为关节点 
	}
}

void cutPointQuery()
{
	int i;
	FILE *fp = NULL; // 初始化文件指针 
	char buff[100]; // 文件读取缓冲区 
	fp = fopen("NUCMap.txt", "r");
	if(fp == NULL)  
		puts("文件读取失败！");
	while(fgets(buff, 100, fp) != NULL)
	{
		printf("%s", buff);
	}
	fclose(fp); // 关闭文件指针 
	memset(cut, 0, sizeof(cut)); // 保存关节点 初始化 
	cutNum = 0;
	for(i = 0; i < g->vertexNum; i++) // 对每个结点进行DFS 
	{	
		memset(visi, 0, sizeof(visi)); // 访问数组初始化 
		visi[i] = ROOT; // 对该结点进行DFS之前，将该点标记为根节点 
		dfs_cut(g, i);
	}
	if(cutNum)
	{
		printf("\t\t\t校园图的关节点个数为：%d\n\n\t\t\t分别为: \n", cutNum);
		for(i = 0; i < g->vertexNum; i++) // 遍历输出关节点 
		{	
			if(cut[i] == 1)
				printf("\n\t\t\t\t* %s\n", g->vexs[i].name); 
		}
	} 
	else
		printf("\n\t\t\t关节点个数为0，不存在关节点\n");
	
} 
#endif
