#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lc{
	char *card_num; // 卡号 
	char *name;     // 姓名 
	char *major;	// 专业 / 系
	char *class_num; 	// 班级号 
	struct lc * next;
} library_card;

library_card * head = NULL; // 头结点
library_card * curr = NULL; // 标记链表最后一个元素，用于添加元素 
char info[100]; // 用于获取读入信息 

// 借书卡信息初始化，用户信息输入 
library_card * initInfo(library_card * lc)
{
	int info_length;
	lc = (library_card*)malloc(sizeof(library_card));
	
	puts("输入卡号:");
	scanf("%s", info);
	info_length = strlen(info);
	lc->card_num = (char*)malloc(info_length * sizeof(char));
	strcpy(lc->card_num, info);
	
	puts("输入姓名:");
	scanf("%s", info);
	info_length = strlen(info);
	lc->name = (char*)malloc(info_length * sizeof(char));
	strcpy(lc->name, info);
	
	puts("输入系名:");
	scanf("%s", info);
	info_length = strlen(info);
	lc->major = (char*)malloc(info_length * sizeof(char));
	strcpy(lc->major, info);
	
	puts("输入班级:");
	scanf("%s", info);
	info_length = strlen(info);
	lc->class_num = (char*)malloc(info_length * sizeof(char));
	strcpy(lc->class_num, info);
	
	lc->next = NULL;
	
	puts("添加成功");
	/*//test
	printf("%s\n", lc->card_num);
	printf("%s\n", lc->name);
	printf("%s\n", lc->major);
	printf("%s\n", lc->class_num);
	*/
	return lc;
}

// 借书卡初始化，即是第一个卡时，让头节点指向它 
library_card * initLibraryCard(library_card * head)
{
	//puts("init");
	library_card * lc;
	lc = initInfo(lc);
	head->next = lc;
	curr = lc;
	return head;
}

// 添加借书卡 
library_card * addLibraryCard(library_card * head)
{
//	puts("add");
	if(head->next == NULL)
		return initLibraryCard(head);
	library_card * lc;
	lc = initInfo(lc);
	curr->next = lc;
	curr = lc;
	return head;
}

// 交换链表两相邻元素
void reverseInfo(library_card * pr, library_card * cu, library_card * ne) 
{
//	puts("reverse info");
	if(ne == NULL)
		return ;
	library_card * pre = pr; // cu的前一个元素 
	library_card * cur = cu; // 当前cu元素 
	library_card * nex = ne; // cu的后一个元素 
	
	cur->next = nex->next;
	nex->next = pre->next;
	pre->next = nex;
} 

// 冒泡排序 
library_card * sortLibraryCardByCardNum(library_card * head)
{
//	puts("sort");
	if(head == NULL && head->next == NULL)
	{
		puts("没有可排序的信息~"); 
		return head;
	}
	library_card * p = head->next;
	library_card * q = p->next;
	library_card * cu = head->next; //当前元素 
	library_card * pr = head; // 当前元素的前一个元素  
	while(p)
	{
		while(q)
		{
			if(strcmp(p->card_num, q->card_num) > 0)
			{
				reverseInfo(pr, p, p->next);
			}
			q = q->next;
			//printf("p's card_num is %s\n", p->card_num);
		} 
		pr = p;
		p = p->next;
	} 
	puts("排序完成~");
	return head;
}

library_card * searchLibraryCardByMajor(library_card * head)
{
//	puts("search");
	int isFound = 0; // 是否有该系的借书卡信息 
	int order = 0; // 借书卡信息序号 
	puts("输入要查找的系名:");
	scanf("%s", info);
//	puts(info);
	library_card * lc = head->next;
	while(lc)
	{
//		puts(lc->name);
//		puts(lc->major);
		if(strcmp(lc->major, info) == 0)
		{
			if(!isFound)
			{
				printf("\n+----------   %-8s系借书卡信息    -------+\n",info);
				printf("| ");
				printf("|%-10s", "卡号");
				printf("|%-10s", "姓名");
				printf("|%-17s", "系名");
				printf("|%-10s", "班级");
				printf("|\n");
				isFound = 1;
			}
			printf("|%d", ++order);
			printf("|%-10s", lc->card_num);
			printf("|%-10s", lc->name);
			printf("|%-17s", lc->major);
			printf("|%-10s", lc->class_num);
			printf("|\n");
		}
		lc = lc->next;
	}
	if(!isFound)
		puts("没有该系的借书卡信息~");
	else
		puts("+----------------------------------------------------+");
	return NULL;
}

void menu()
{
	puts(" ");
	puts("		+--借书证信息管理系统--+");
	puts("		|                      |");
	puts("		|  信息录入(1)         |");
	puts("		|  信息排序(2)         |");
	puts("		|  信息查找(3)         |");
	puts("		|                      |");
	puts("		|  退出(0)             |");
	puts("		+----------------------+");
	puts(" ");
}

int main()
{
	int opera;		// 指令 
	int isExit = 0; // 是否退出 
	char isAddNext; // 是否继续添加 
	head = (library_card*)malloc(sizeof(library_card));
	head->next = NULL;
	head->card_num = NULL; // 卡号 
	head->name = NULL;     // 姓名 
	head->major = NULL;	   // 专业 / 系
	head->class_num = NULL; 	// 班级号 
	system("mode con lines=30 cols=70");
	while(1)
	{
		menu();
		printf("指令输入: ");
		scanf("%d", &opera);
		puts("- - - - - - - - - - - - - - - - ");
		switch(opera)
		{
			case 1:
				isAddNext = 'y';
				while(isAddNext == 'y')
				{
					addLibraryCard(head); // 添加借书卡信息 
					while(1) // 让用户选择是否继续添加信息，y->继续，n->停止，若为其他指令，则继续询问 
					{
						puts("是否继续添加(y/n)?");
						getchar(); // 吃掉回车 
						isAddNext = getchar();
						tolower(isAddNext); // 将字符转换为小写，防止用户输入大写 
						if(isAddNext == 'y' || isAddNext == 'n')
							break;
					} 
				}
				system("cls");
				break;
			case 2:
				sortLibraryCardByCardNum(head);
				system("pause");
				system("cls");
				break;
			case 3:
				searchLibraryCardByMajor(head);
				system("pause");
				system("cls");
				break;
			case 0:
				isExit = 1;
				break;
			default:
				puts("请输入正确指令");
				system("pause");
				system("cls");
				break;
		}
		if(isExit)
			break;
	}
	return 0;
}

/*
1
1507064146
张三
计算机科学与技术 
15070641
y
1507064132
李四
计算机科学与技术
15070641
y
1507064112
王五 
计算机科学与技术
15070641
n
3
计算机科学与技术

*/
