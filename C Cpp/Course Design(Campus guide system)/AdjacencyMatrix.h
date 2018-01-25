/*邻接矩阵定义与创建*/
#ifndef _ADJACENCY_MATRIX_H_
#define _ADJACENCY_MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define INFINITY 65535 // 表示无穷大
#define MAX 15 // 表示结点或者边的最大值 

typedef struct { // 定义边结构体，成员为权重 
	int weight;
} edge;

typedef struct { // 定义结点结构体，即景点信息 
	char *name; // 景点名称
	char *code; // 景点代号  
	char *intro; // 景点简介 
} vertex;
 
typedef struct { // 定义邻接矩阵 
	vertex vexs[MAX]; // 结点 
	edge edges[MAX][MAX]; // 边 
	int vertexNum, edgeNum; // 结点数，边数 
} Mgraph; 

Mgraph *g = NULL; // 定义图的全局变量 

// 创建邻接矩阵 
void create(Mgraph *g, char *text)
{
	int i, j, k, w;
	char info[100]; // 用于缓存数据信息 
	int infoLen; // 数据信息的长度 
	FILE *rf;
	rf = fopen(text, "r");
	if(rf)
	{
		fscanf(rf, "%d%d", &g->vertexNum, &g->edgeNum); // 读入图的顶点数和边数
		for(i = 0; i < g->vertexNum; i++)   // 初始化景点结点信息 
		{
			fscanf(rf, "%s", info);	// 获取缓存信息 -- 景点代号 
			infoLen = strlen(info); // 获取缓存信息长度 
			g->vexs[i].code = (char*)malloc(infoLen * sizeof(char)); //  更具缓存信息长度为该结点的code字符串开辟空间 
			strcpy(g->vexs[i].code, info); // 给结点code成员赋值
			
			fscanf(rf, "%s", info);	// 获取缓存信息 -- 景点名称 
			infoLen = strlen(info); // 获取缓存信息长度 
			g->vexs[i].name = (char*)malloc(infoLen * sizeof(char)); //  更具缓存信息长度为该结点的name字符串开辟空间 
			strcpy(g->vexs[i].name, info); // 给结点name成员赋值
			 
			fscanf(rf, "%s", info);	// 获取缓存信息 -- 景点简介 
			infoLen = strlen(info); // 获取缓存信息长度 
			g->vexs[i].intro = (char*)malloc(infoLen * sizeof(char)); //  更具缓存信息长度为该结点的intro字符串开辟空间 
			strcpy(g->vexs[i].intro, info); // 给结点intro成员赋值
		}
		for(i = 0; i < g->vertexNum; i++)	// 初始化邻接矩阵 
		{
			for(j = 0; j < g->vertexNum; j++)
			{
				if(i == j)
				{
					g->edges[i][j].weight = 0;
				}
				else
				{
					g->edges[i][j].weight = INFINITY;
				}
			}
		}
		for(k = 0; k < g->edgeNum; k++)
		{
			fscanf(rf, "%d%d%d", &i, &j, &w);
			g->edges[i][j].weight = w;
			g->edges[j][i].weight = w; // 建立无向图邻接矩阵 
		}
		fclose(rf);
	}
	else
	{
		g->vertexNum = 0;
	}
}
#endif
