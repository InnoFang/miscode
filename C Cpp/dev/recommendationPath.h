#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "AdjacencyMatrix.h"	/*邻接矩阵定义与创建*/
#include "SpotsInfoQuery.h" 	/*景点信息查询 */
#include "SpotsSearchQuery.h"   /*景点寻路查询，两点间最短路查询*/
#include "CutPointQuery.h"		/*景点关节点查询*/
#include "AllPathQuery.h" 		/*景点路径查询，两点间所有路*/

#define INFINITY 65535 // 表示无穷大
#define MAX 15 // 表示结点或者边的最大值 

//观光路径推荐
int haveChosen[MAX]; // 已经被选择的景点 
int choose[MAX]; 	//要去的景点栈 
int t = -1; 		 // 栈顶 
// 邻接矩阵的深度优先搜索递归算法
void dfs(Mgraph *g, int i)
{
	int j;

}

void recommendation() // 推荐路径搜索 
{
	puts("这是推荐路径~~~~~"); 
}

void recommendationPath()
{ 
	puts("\n\n\t\t\t\t\t观 光 路 径 推 荐\t\t\t\t\t"); 
	puts("\t\t\t\t\t=================\t\t\t\t\t\n"); 
	puts("\t0. 德怀楼\t1. 柏林园\t2. 二龙山\t3. 科艺苑\t4. 文瀛餐厅");
	puts("\t5. 红房子\t6. 体育场\t7. 图书馆\t8. 行知广场\t9. 璟瑜国际会议中心");
	puts("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	int order = -1;	// 获取选择的景点序号 
	int k; // 键盘输入 
	int i;
	memset(haveChosen, 0, sizeof(haveChosen));
	t = -1;
	while((k = getch())!= 27 && k != 13) // 点击ESC或Enter退出， 
	{
		system("cls");
		if(k == 8) // 当点击BackSpace(ASCII为8)键时，栈顶退出，若为空，则不操作
		{
			haveChosen[choose[t--]] = 0;	
		}
		order = k - 48;
		if(order >= 0 && order <= 9 && haveChosen[order] == 0)
		{
			haveChosen[order] = 1;
			if(t < g->vertexNum - 1)
			{
				choose[++t] = order;
			}
		} 
		puts("\n\n\t\t\t\t\t观 光 路 径 推 荐\t\t\t\t\t"); 
		puts("\t\t\t\t\t=================\t\t\t\t\t\n");
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
		t >= g->vertexNum ? puts("\t\t\t\t\t   您已经选完了！") : puts(" ");
		puts("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
		printf("    您已选择：\n\t");
		for(i = 0 ; i <= t ; i++)
		{
			printf("%s  ", g->vexs[choose[i]].name);
		}
	}
	if(order == 13)
	{
		puts("\n    最佳路径推荐如下：");	
		recommendation();
	}
		
}

