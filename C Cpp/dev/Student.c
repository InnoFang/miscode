#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct s{
	char name[5];
	int id;
	char phone[11];
	struct s *next;
} Student;

Student *init_student(Student *head, Student *curr, char *name, int id, char *phone)
{
	Student *p = (Student*)malloc(sizeof(Student));
	strcpy(p->name, name);
	p->id = id;
	strcpy(p->phone, phone);
	p->next = NULL;
	head->next = p;
	curr = p;
	printf("添加成功！\n\n");
	return p;
}

Student *add_student(Student *head, Student *curr, char *name, int id, char *phone)
{
	if(NULL == head->next)
	{
		return init_student(head, curr, name, id, phone);
	}
	Student *p = (Student*)malloc(sizeof(Student));
	strcpy(p->name, name);
	p->id = id;
	strcpy(p->phone, phone);
	p->next = NULL;
	curr->next = p;
	curr = p;
	printf("添加成功！\n\n");
	return p;
}

Student *find(Student *head, int local)
{
	int j = 0;
	Student *p = head;
	if(local < 0)
	{
		printf("第%d个位置不存在\n", local);
		return NULL;
	}
	else if(local == 0)
	{
		return p;
	}
	while(p && local != j)
	{
		p = p->next;
		j++;
	}
	return p;
}

Student *insert_student(Student *head, int local, char *name, int id, char *phone)
{
	Student *p, *q;
	q = find(head, local - 1);
	if(!q)
	{
		printf("无法插入数据！\n");
		return head;
	}
	p = (Student*)malloc(sizeof(Student));
	strcpy(p->name, name);
	p->id = id;
	strcpy(p->phone, phone);
	p->next = q->next;
	q->next = p;
	printf("插入成功！\n");
	return head;
}

Student *query_student(Student *head, char *name)
{
	if(NULL == head)
	{
		printf("学生通讯录为空！\n");
		return NULL;
	}
	Student *p = head->next;
	while(p)
	{
		if(strcmp(p->name, name) == 0)
		{
			break;
		}
		p = p->next;
	}
	return p;
}

Student *delete_student(Student *head, char *name)
{
	Student *pre = head, *q;
	q = head->next;
	if(!query_student(head, name))
	{
		printf("没有名字为:%s的学生记录！\n",name);
		return NULL;
	}
	while(q && strcmp(q->name, name) != 0)
	{
		pre = q;
		q = q->next;
	}
	if(q)
	{
		pre->next = q->next;
		free(q);
	}
	printf("删除成功!\n");
	return head;
}

void print_student(Student *head)
{
	Student *p = head->next;
	int size = 1;
	printf("+----------------------------学生通讯录----------------------------+\n");
	while(p)
	{
		printf("|%d|姓名：%-10s	学号：%-15d	电话：%-12s |\n", size++, p->name, p->id, p->phone);
		p = p->next;
	}
	printf("+------------------------------------------------------------------+\n");
}

int main()
{
	int order;		/*操作数*/
	int addNum;		/*添加学生数据数量*/
	int local;		/*插入数据位置*/
	int isExit = 0;	/*是否退出*/
	int id;			/*学生学号*/
	char name[5];	/*学生名字*/
	char phone[11];	/*学生电话*/
	Student *head = (Student*)malloc(sizeof(Student));;	/*头结点*/
	Student *curr = head->next = NULL;	/*记录当前结点地址，用于添加数据*/
	Student *temp = NULL;	/*保存临时结构体变量*/
	int i, j;
	while(1)
	{
		printf("\n+------指令菜单------+\n");
		printf("|                    |\n");
		printf("|  添加学生数据(1)   |\n");	/*初始化学生数据表，并添加数据*/
		printf("|  插入学生数据(2)   |\n");
		printf("|  删除学生数据(3)   |\n");
		printf("|  输出学生数据(4)   |\n");	/*打印输出所有学生数据*/
		printf("|  查询学生数据(5)   |\n");	/*根据名字查询学生记录*/
		printf("|                    |\n");
		printf("|  退出(0)           |\n");
		printf("+--------------------+\n");
		printf("\n请输入你的指令：");
		scanf("%d", &order);
		switch(order)
		{
			case 1:
				printf("\n你想要添加数据的数目：");
				scanf("%d", &addNum);
				for(i = 0; i < addNum; i++)
				{
					printf("请输入姓名：");
					scanf("%s", name);
					printf("请输入学号：");
					scanf("%d", &id);
					printf("请输入电话：");
					scanf("%s", phone);
					curr = add_student(head, curr, name, id, phone);
				}
				break;
			case 2:
				printf("\n输入你要插入的位置：");
				scanf("%d", &local);
				printf("请输入姓名：");
				scanf("%s", name);
				printf("请输入学号：");
				scanf("%d", &id);
				printf("请输入电话：");
				scanf("%s", phone);
				insert_student(head, local, name, id, phone);
				break;
			case 3:
				printf("输入你要s删除的学生的名字：");
				scanf("%s", name);
				delete_student(head, name);
				break;
			case 4:
				print_student(head);
				break;
			case 5:
				printf("输入你要查询的学生的名字：");
				scanf("%s", name);
				temp = query_student(head, name);
				if(temp)
				{
					printf("+----------------------------查询结果-----------------------------+\n");
					printf("|姓名：%-10s	学号：%-15d	电话：%-12s|\n", temp->name, temp->id, temp->phone);
					printf("+-----------------------------------------------------------------+\n");
				}
				else
					printf("\n没有该学生记录！\n");
				break;
			case 0:
				isExit = 1;
				break;
			default:
				printf("\n指令有误，请重新输入！\n");
				break;
		}
		if(isExit)
			break;
	}
	printf("程序已退出\n");
	return 0;
}

