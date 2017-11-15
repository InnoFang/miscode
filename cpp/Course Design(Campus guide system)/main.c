#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "AdjacencyMatrix.h"	/*邻接矩阵定义与创建*/
#include "SpotsInfoQuery.h" 	/*景点信息查询 */
#include "SpotsSearchQuery.h"   /*景点寻路查询，两点间最短路查询*/
#include "CutPointQuery.h"		/*景点关节点查询*/
#include "AllPathQuery.h" 		/*景点路径查询，两点间所有路*/
#include "RecommendationPath.h" /*多个景点的最佳路径推荐*/



// 使用帮助

void help()
{
	FILE *fp = NULL; // 初始化文件指针
	char buff[100]; // 文件读取缓冲区
	fp = fopen("help.txt", "r");
	if(fp == NULL)
		puts("文件读取失败！");
	while(fgets(buff, 100, fp) != NULL)
	{
		printf("%s", buff );
	}
	fclose(fp); // 关闭文件指针
}

/** 菜单 **/
int opera = 1; // 全局变量，菜单项指令

void updateUI(int k)  // 更新视图
{
	system("cls");
	FILE *fp = NULL; // 初始化文件指针
	char buff[100]; // 文件读取缓冲区
	fp = fopen("menu_head.txt", "r");
	if(fp == NULL)
		puts("文件读取失败！");
	while(fgets(buff, 100, fp) != NULL)
	{
		printf("%s", buff );
	}
	fclose(fp); // 关闭文件指针
	if(k == 1) // item1
	{
		puts("                ║		   ┃ 	 >> 景点信息查询     ┃ 	        ║");
	}
	else
	{
		puts("                ║		   ┃  #1   景点信息查询     ┃ 	        ║");
	}
	if(k == 2)// item2的状态
	{
		puts("                ║		   ┃    >> 景点寻路查询     ┃                 ║");
	}
	else
	{
		puts("                ║		   ┃  #2   景点寻路查询     ┃                 ║");
	}
	if(k == 3)// item3的状态
	{
		puts("                ║		   ┃    >> 关节点  查询     ┃ 	        ║");
	}
	else
	{
		puts("                ║		   ┃  #3   关节点  查询     ┃ 	        ║");
	}
	if(k == 4)// item4的状态
	{
		puts("                ║		   ┃    >> 景点路径查询     ┃ 	        ║");
	}
	else
	{
		puts("                ║		   ┃  #4   景点路径查询     ┃ 	        ║");
	}
	if(k == 5)// item5的状态
	{
		puts("                ║		   ┃    >> 观光路径推荐     ┃ 	        ║");
	}
	else
	{
		puts("                ║		   ┃  #5   观光路径推荐     ┃ 	        ║");
	}
	if(k == 6)// item6的状态
	{
		puts("                ║		   ┃    >> 使 用 帮 助      ┃ 	        ║");
	}
	else
	{
		puts("                ║		   ┃  #6   使 用 帮 助      ┃ 	        ║");
	}
	fp = fopen("menu_foot.txt", "r");
	if(fp == NULL)
		puts("文件读取失败！");
	while(fgets(buff, 100, fp) != NULL)
	{
		printf("%s", buff );
	}
	fclose(fp); // 关闭文件指针
}

void exec(int opera)
{
	int k; // 获取键盘指令
	while(1)
	{

		system("cls"); // 清屏
		// 执行菜单项
		switch(opera)
		{
			case 1:
				spotsInfoQuery(); // 景点信息查询
				break;
			case 2:
				spotsSearchQuery(); // 景点问路查询
				break;
			case 3:
				cutPointQuery();  // 求关节点/割点
				break;
			case 4:
				allPathQuery();		// 两点之间有路径
				break;
			case 5:
				recommendationPath();  // 推荐路径
				break;
			case 6:
				help();
				break;
			default:
				break;
		}
		if((k = getch()) == 27) // 进入指定功能后，点击esc或则BackSpace退回菜单界面
		{
			system("cls");
			updateUI(opera); // 返回菜单后，记住进入菜单项时的状态
			break;
		}
	}
}


void menu()
{
	int k;
	while(k = getch())
	{
		if(k == 224) // 如果点击的是方向键
			k = getch();
		else if(k == 27) // 菜单界面点击esc则直接退出
		{
			system("cls"); // 清屏
			FILE *fp = NULL; // 初始化文件指针
			char buff[100]; // 文件读取缓冲区
			fp = fopen("exit.txt", "r");
			if(fp == NULL)
			puts("文件读取失败！");
			while(fgets(buff, 100, fp) != NULL)
			{
				printf("%s", buff );
			}
			fclose(fp); // 关闭文件指针
			//Sleep(1000); // 等待1s后关闭
			exit(0);
		}
		else if(k == 13) // 点击回车执行菜单项功能
		{
			exec(opera);
			break;
		}
		else if(k == 49 || k == 50 || k == 51 || k == 52 || k == 53 || k == 54) // 点击菜单项序号直接执行菜单项功能,即输入1~6，执行相应的功能
		{
			opera = k - 48;	// 更新菜单项指令,即将字符变成数字
			exec(opera); // 执行菜单项功能
		}
		if(k == 72 || k == 119) //如果点击w或则方向键上键则更新视图，
		{
			if(opera == 1)
				updateUI(opera);
			else
				updateUI(--opera);
		}

		if(k == 80 || k == 115)// 如果点击s或则方向键下键则更新视图，
		{
			if(opera == 6)
				updateUI(opera);
			else
				updateUI(++opera);
		}
	}
}

void initMenu()
{
	// 默认菜单
	FILE *fp = NULL; // 初始化文件指针 e
	char buff[100]; // 文件读取缓冲区
	fp = fopen("menu.txt", "r");
	if(fp == NULL)
		puts("文件读取失败！");
	while(fgets(buff, 100, fp) != NULL)
	{
		printf("%s", buff );
	}
	fclose(fp); // 关闭文件指针
	while(1)
	{
		menu();
	}
}
/** 菜单 **/
int main()
{
	system("mode con lines=32 cols=100");
	system("color f0"); // 3f 
	g = (Mgraph*)malloc(sizeof(Mgraph)); // 创建图结构体
	create(g, "info.txt"); // 初始化图
	initMenu();
	return 0;
}
