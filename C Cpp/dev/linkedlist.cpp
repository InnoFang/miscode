//the linked list
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct s
{
	int  id;
	float score;
	struct s *next;
} Student;
Student *head = NULL;
Student *curr = NULL;

Student* create_list(int id, float score)
{
	Student *p = (Student*)malloc(sizeof(Student));
	if(NULL == p)
	{
		printf("It's fail to add!");
		return NULL;
	}
	p->id = id;
	p->score = score;
	p->next = NULL;
	head = curr = p;
	return p;
}

Student* add_list(int id, float score)
{
	if(NULL == head)
		return create_list(id, score);
	Student *p = (Student*)malloc(sizeof(Student));
	if(NULL == p)
	{
	    printf("It's fail to add!");
		return NULL;
	}
	p->id = id;
	p->score = score;
	p->next = NULL;
	curr->next = p;
	curr = p;
}

Student* search_list(int id)
{
	printf("\nSearching the list for id %d\n",id);
	Student *p = head;
	bool found = false;
	while(p != NULL)
	{
		if(p->id == id)
		{
			found = true;
			break;
		}	
		else 
		{
			p = p->next;
		}
	}
	if(found)
		return p;
	else
		return NULL;	
}

int delete_list(int id)
{
	Student *p1 = head, *p2;
	p2 = p1;
	Student *q = search_list(id);
	if(NULL == q)
	{
		return -1;
	}	
	while(p1 != q)
	{
		p2 =p1;   
		p1 = p1->next; 	
	}
	if(p1 == head)
		head = p1->next;
	else
		p2->next = p1->next;
	free(q);
	return 1;
}

int insert_list(int local, int id, float score)
{
	int i = 1;
	Student *p1, *p2, *s;
	if(NULL == head)
	{
		create_list(id, score);			
	}
	p1 = p2 = head;
	s = (Student*)malloc(sizeof(Student));
	if(NULL == s)
	{
		return -1;
	}
	s->id = id;
	s->score = score;
	while(i < local && p1->next != NULL)
	{
		i++;
		p2 = p1;
		p1 = p1->next;	
	}
	if(i != local && p1->next == NULL)
	{
		return -1;
	}
	if(i == 1)/*the first one*/
	{
		s->next = p1;
		head = s;
	}
	else if(p1->next == NULL && i + 1 == local)/*the last one*/
	{
		p1->next = s;
		s->next = NULL;
	}
	else/*between the first one and last one*/
	{
		s->next = p1;
		p2->next = s;
	}
	return 1;
}

int length_list()
{
	if(NULL == head)
		return 0;

	Student *p = head;
	int i = 1;	
	while(p->next)
	{
		i++;
		p = p->next;	
	}
	/*int i = 0;	
	while(p)
	{
		i++;
		p = p->next;	
	}*/
	return i;	
}

void print_list()
{
	printf("\n--------printing start--------\n");
	Student *p = head;
	while(p)
	{
		printf("%d  %5.2f\n",p->id, p->score);
		p = p->next;
	}
	printf("\n--------printing end--------\n");
}

int main()
{
//	freopen("LinkedList.in","r",stdin);
//	freopen("LinkedList.out","w",stdout);
 
	printf("input the numbers you want to add : \n");
	int num, id;
	float score;
	scanf("%d",&num);
	printf("enter %d sets of data : \n",num);
	for(int i = 0; i < num; i++)
	{
		scanf("%d%f",&id, &score);
		add_list(id, score);
	}
	print_list();
	
	printf("\ninput the id you want to search\n");
	int n;
	scanf("%d",&n);
	Student *p = search_list(n);
	if(p != NULL)
		printf("The score of id %d is %.2f\n",p->id,p->score);
	else
		printf("\n Search id %d failed, no such id found\n",n);
	
	
	printf("\ninput the id you want to delete\n");
	int m;
	scanf("%d",&m);
	int result = delete_list(m);
	if(result == -1)
    {
        printf("\n delete id %d failed, no such id found\n",m);
    }
    else
    {
        printf("\n delete id %d  passed \n",m);
    }
    print_list();
    
    printf("enter a set of data : \n");
    int isId, local;
	float isScore;
    scanf("%d%d%f",&local, &isId, &isScore);
    result = insert_list(local,isId,isScore);
    if(result == -1)
    {
       		printf("It's fail to insert!");
    }
    else
    {
        printf("\n insert passed \n");
    }
    print_list();
    
    printf("continue enter a set of data : \n");
    scanf("%d%d%f",&local, &isId, &isScore);
    result = insert_list(local,isId,isScore);
    if(result == -1)
    {
       		printf("It's fail to insert!");
    }
    else
    {
        printf("\n insert passed \n");
    }
    print_list();
    
    int len = length_list();
    printf("\nNow, the length of the linked list is %d\n",len);
	return 0;
}
