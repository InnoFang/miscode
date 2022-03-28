/*景点信息查询 */
#ifndef _SPOT_INFO_QUERY_H_ 
#define _SPOT_INFO_QUERY_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "AdjacencyMatrix.h"	/*邻接矩阵定义与创建*/

void spotsInfoQuery()
{
	int order; // 获取用户输入的景点序号 
	puts(" ");
	puts("\t\t\t\t       【景 点 信 息 查 询】\t\t\t\t\t"); 
	puts("\t\t\t\t0. 德怀楼\t┃\t5. 红房子\t\t\t\t");
	puts("\t\t\t\t1. 柏林园\t┃\t6. 体育场\t\t\t\t");
	puts("\t\t\t\t2. 二龙山\t┃\t7. 图书馆\t\t\t\t");
	puts("\t\t\t\t3. 科艺苑\t┃\t8. 行知广场\t\t\t");
	puts("\t\t\t\t4. 文瀛餐厅\t┃\t9. 璟瑜国际会议中心\t\t\t");
	puts(" "); 
	printf("\t\t\t    输入景点序号进行查询 ：");
	order = getch();
	if(order >= 48 && order <= 57) // 如果输入的是0 ~ 9 则显示相应的景点信息 
	{
		order -= 48; 
		printf("%d\n", order);
		puts("\t\t    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \t\t");
		printf("\n\t\t\t景点代号：%s\n", g->vexs[order].code);
		printf("\n\t\t\t景点名称：%s\n", g->vexs[order].name);
		printf("\n\t\t\t景点简介：\n\n\t\t%s", g->vexs[order].intro);
	}
}
#endif
