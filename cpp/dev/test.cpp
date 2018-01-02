
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int a[1][2] = {{1,2}}, b[2][3] = {{1,2,3},{4,5,6}}, c[1][3];
//	memset(c,0,sizeof(c));
//    int p,q,r;
//    for(p=0;p<1;p++)
//	{
//		for(r=0;r<3;r++)
//		{
//			for(q=0;q<2;q++)
//			{
//                c[p][r]+=a[p][q]*b[q][r]; 
//			}
//		}
//	}
//	for(p = 0; p < 1 ; p++)
//	{
//		for(q = 0; q < 3; q++)
//		{
//			printf("%d ",c[p][q]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int m;
//	while(scanf("%d",&m) != EOF)
//	{
//		int sram[m], i, j, n = 0;
//		for(i = 0; i < m; i++)
//		{
//			scanf("%d",&sram[i]);
//		}
//		for(i = 0; i < m; i++)
//		{
//			for(j = i + 1; j < m; j++)
//			{
//				if(sram[i] > sram[j])
//				{
//					n++;
//					printf("%d---%d\n",sram[i],sram[j]);
//				}
//			}
//		}
//		printf("%d\n",n);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<time.h>
//#include<string.h>
//#include<stdlib.h>
//#define maxn  100000000
//char s[maxn];
//int main()
//{
//	srand(time(NULL));
//	memset(s,0,sizeof(s));
//	
//	sprintf(s,"%lf",(double)rand());
//	printf("%s\n",s);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int n = 3467, m = 8;
//	while(n)
//	{
//		printf("%d\n",n%m);
//		n /= m;
//	}
//	return 0;
//}
//#include<stdio.h> 
// 
// int main(void)
// {
//     int n;
// 
//     while (scanf("%d", &n) == 1)
//     {
//         int k = 1;
//         while (k < n) //k为第N项所在行数；n减后意义为，所求数在第K行第n项。
//         {
//             n -= k;
//             k++;
//         }
//         if (0 == k%2)
//         {
//             printf("%d/%d\n", n, k+1-n);
//         }
//         else
//        {
//             printf("%d/%d\n", k+1-n, n);
//         }
//     }
// 
//     return 0; 
// }
//quick sort
//#include<stdio.h>
//#include<stdlib.h>
//int cmp(const void *a, const void *b)
//{
//	return (*(int*)a - *(int*)b);
//}
//int main()
//{
//	int a[] = {10,9,8,7,6,5,4,3,2,1};
////	qsort(a,10,sizeof(int),cmp);
//	qsort(a,10,sizeof(a[0]),cmp);
//	for(int i = 0; i < 10; i++)
//	{
//		printf("%d ",a[i]);
//	}
//	return 0;
//}

//buble sort
//#include<stdio.h>
//int main()
//{
//	int c[] = {1,2,3,4,5,6,7,8,9,10};
//	for(int i = 8; i >= 0; i--)
//	{
//		for(int j = 0; j <= i; j++)
//		{
//			if(c[j] < c[j+1])
//			{
//
//				int	temp = c[j];
//				c[j] = c[j+1];
//				c[j+1] = temp;
//			}
//		}
//	}
//	for(int i = 0;i < 10 ; i++)
//	{
//		printf("%d ",c[i]);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 4, b = 6;
//	printf("max = %d\n",max(a,b));
//	return 0;
//}

//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//const int MAXN = 410;
//
//struct bign
//{
//	int len, s[MAXN];
//	bign ()
//	{
//		memset(s, 0, sizeof(s));
//		len = 1;
//	}
//	bign (int num) { *this = num; }
//	bign (const char *num) { *this = num; }
//	bign operator = (const int num)
//	{
//		char s[MAXN];
//		sprintf(s, "%d", num);
//		*this = s;
//		return *this;
//	}
//	bign operator = (const char *num)
//	{
//		for(int i = 0; num[i] == '0'; num++) ;  //去前导0
//		len = strlen(num);
//		for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
//		return *this;
//	}
//	bign operator + (const bign &b) const //+
//	{
//		bign c;
//		c.len = 0;
//		for(int i = 0, g = 0; g || i < max(len, b.len); i++)
//		{
//			int x = g;
//			if(i < len) x += s[i];
//			if(i < b.len) x += b.s[i];
//			c.s[c.len++] = x % 10;
//			g = x / 10;
//		}
//		return c;
//	}
//	bign operator += (const bign &b)
//	{
//		*this = *this + b;
//		return *this;
//	}
//	void clean()
//	{
//		while(len > 1 && !s[len-1]) len--;
//	}
//	bign operator * (const bign &b) //*
//	{
//		bign c;
//		c.len = len + b.len;
//		for(int i = 0; i < len; i++)
//		{
//			for(int j = 0; j < b.len; j++)
//			{
//				c.s[i+j] += s[i] * b.s[j];
//			}
//		}
//		for(int i = 0; i < c.len; i++)
//		{
//			c.s[i+1] += c.s[i]/10;
//			c.s[i] %= 10;
//		}
//		c.clean();
//		return c;
//	}
//	bign operator *= (const bign &b)
//	{
//		*this = *this * b;
//		return *this;
//	}
//	bign operator - (const bign &b)
//	{
//		bign c;
//		c.len = 0;
//		for(int i = 0, g = 0; i < len; i++)
//		{
//			int x = s[i] - g;
//			if(i < b.len) x -= b.s[i];
//			if(x >= 0) g = 0;
//			else
//			{
//				g = 1;
//				x += 10;
//			}
//			c.s[c.len++] = x;
//		}
//		c.clean();
//		return c;
//	}
//	bign operator -= (const bign &b)
//	{
//		*this = *this - b;
//		return *this;
//	}
//	bign operator / (const bign &b)
//	{
//		bign c, f = 0;
//		for(int i = len-1; i >= 0; i--)
//		{
//			f = f*10;
//			f.s[0] = s[i];
//			while(f >= b)
//			{
//				f -= b;
//				c.s[i]++;
//			}
//		}
//		c.len = len;
//		c.clean();
//		return c;
//	}
//	bign operator /= (const bign &b)
//	{
//		*this  = *this / b;
//		return *this;
//	}
//	bign operator % (const bign &b)
//	{
//		bign r = *this / b;
//		r = *this - r*b;
//		return r;
//	}
//	bign operator %= (const bign &b)
//	{
//		*this = *this % b;
//		return *this;
//	}
//	bool operator < (const bign &b)
//	{
//		if(len != b.len) return len < b.len;
//		for(int i = len-1; i >= 0; i--)
//		{
//			if(s[i] != b.s[i]) return s[i] < b.s[i];
//		}
//		return false;
//	}
//	bool operator > (const bign &b)
//	{
//		if(len != b.len) return len > b.len;
//		for(int i = len-1; i >= 0; i--)
//		{
//			if(s[i] != b.s[i]) return s[i] > b.s[i];
//		}
//		return false;
//	}
//	bool operator == (const bign &b)
//	{
//		return !(*this > b) && !(*this < b);
//	}
//	bool operator != (const bign &b)
//	{
//		return !(*this == b);
//	}
//	bool operator <= (const bign &b)
//	{
//		return *this < b || *this == b;
//	}
//	bool operator >= (const bign &b)
//	{
//		return *this > b || *this == b;
//	}
//	string str() const
//	{
//		string res = "";
//		for(int i = 0; i < len; i++) res = char(s[i]+'0') + res;
//		return res;
//	}
//};
//
//istream& operator >> (istream &in, bign &x)
//{
//	string s;
//	in >> s;
//	x = s.c_str();
//	return in;
//}
//
//ostream& operator << (ostream &out, const bign &x)
//{
//	out << x.str();
//	return out;
//}
//
//int main()
//{
//	bign a, b, c, d, e, f, g;
//	while(cin>>a>>b)
//	{
//		a.clean(), b.clean();
//		c = a+b;
//		d = a-b;
//		e = a*b;
//		f = a/b;
//		g = a%b;
//		cout<<"a+b"<<"="<<c<<endl; // a += b
//		cout<<"a-b"<<"="<<d<<endl; // a -= b;
//		cout<<"a*b"<<"="<<e<<endl; // a *= b;
//		cout<<"a/b"<<"="<<f<<endl; // a /= b;
//		cout<<"a%b"<<"="<<g<<endl; // a %= b;
//		if(a != b) printf("YES\n");
//		else printf("NO\n");
//	}
//	return 0;
//}


//高精度阶乘 
//#include<stdio.h>
//#include<string.h>
//const int  maxn = 3000;
//int f[maxn];
//int main()
//{
//	int i, j, n;
//	while(scanf("%d",&n) == 1)
//	{		
//	memset(f, 0, sizeof(f));
//	f[0] = 1;
//	for(i = 2; i <= n; i++)
//	{
//		int c = 0;//保存进位 
//		//模拟乘法 
//		for(j = 0; j < maxn; j++)
//		{
//			int s = f[j] * i + c;//获得各个位与因数i的乘积 
//			f[j] = s % 10;//将得到的积取余，即为两数相乘后该位上的数 
//			c = s / 10;//若两数的乘积大于9，就进位 
//		}
//	}
//	for(i = maxn - 1; i >= 0; i--)
//	{
//		if(f[i])
//			break;
//	}
//	for(j = i; j >= 0; j--)
//	{
//		printf("%d",f[j]);
//	}
//	printf("\n");
//	}
//	return 0;
//}


//#include <stdio.h>  
//#include <string.h>  
//  
//int c[] = { 0, 0, 64, 32, 16, 8, 0, 4, 2, 1, 0};  
// 
//int main() {  
//    char str[15];  
//   int value,i;  
//   //freopen("C:\\Users\\XIAOSI\\Desktop\\acm.txt","r",stdin);     
//   gets(str);  
//   while(gets(str) && str[0] != '_'){  
//       value = 0;  
//        int len = strlen(str);  
//       for(i = 2;i < len;i++){  
//           if(str[i] == 'o'){  
//              value += c[i];  
//           }  
//      }  
//       printf("%c",value);  
//    }  
//}  
//  

////delete the repeated element from the list
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct s{
//	int id;
//	struct s *next;
//}Linklist;
//
//Linklist *HA = NULL;
//Linklist *HB = NULL;
//
//Linklist* create_A()
//{
//	Linklist *p1, *p2;
//	p1 = p2 = (Linklist*)malloc(sizeof(Linklist));
//	scanf("%d",&p1->id);
//	while(p1->id != 0)
//	{
//		if(HA == NULL)
//			HA = p1;
//		else	
//			p2->next = p1;
//		p2 = p1;
//		p1 = (Linklist*)malloc(sizeof(Linklist));
//		scanf("%d",&p1->id);
//	}
//	p2->next = NULL;
//	return HA;
//}
//
//Linklist* create_B()
//{
//	Linklist *p1, *p2;
//	p1 = p2 = (Linklist*)malloc(sizeof(Linklist));
//	scanf("%d",&p1->id);
//	while(p1->id != 0)
//	{
//		if(NULL == HB)
//			HB = p1;
//		else
//			p2->next = p1;
//		p2 = p1;
//		p1 = (Linklist*)malloc(sizeof(Linklist));
//		scanf("%d",&p1->id);
//	}
//	p2->next = NULL;
//	return HB;
//}
//
//void combine()
//{
//	void print(Linklist *H);
//	Linklist *C, *p1, *p2, *s;
//	p1 = HA, p2 = HB;
//	C->next = NULL;
//	while(p1&&p2)
//	{
//		if(p1->id < p2->id)
//		{
//			s = p1;
//			p1 = p1->next;
//		}	
//		else
//		{
//			s = p2;
//			p2 = p2->next;
//		}		
//		s->next = C->next;
//		C->next = s;
//	}
//	if(NULL == p1)
//		p1 = p2;
//	while(p1)
//	{
//		s = p1;
//		p1 = p1->next;
//		s->next = C->next;
//		C->next = s;
//	}
//	print(C->next);
//}
//void print(Linklist *H)
//{
//	printf("\n--------printing start--------\n");
//	if(NULL == H)
//		return ;
//	Linklist *p = H;
//	while(p)
//	{
//		printf("%d\n",p->id);
//		p = p->next;
//	}
//	printf("\n--------printing end--------\n");	
//}
//
//int main()
//{
//	printf("input A\n");
//	create_A();
//	printf("input B\n");
//	create_B();
//	printf("print A\n");
//	print(HA);
//	printf("print B\n");
//	print(HB);
//	printf("\n\n--------After combine A and B--------\n\n");
//	combine();
//	return 0;
//}


////delete the repeated element from the list
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct s{
//	int id;
//	struct s *next;
//}Student;
//
//Student *head = NULL;
//
//void print()
//{
//	printf("\n--------printing start--------\n");
//	if(NULL == head)
//		return ;
//	Student* p = head;
//	while(p)
//	{
//		printf("%d\n",p->id);
//		p = p->next;
//	}
//	printf("\n--------printing end--------\n");	
//}
//
//void delete_repetition()
//{
//	Student *p, *q, *r;
//	if(NULL == head)
//		return ;
//	p = q = head;
//	while(p)
//	{
//		q = p;//*****
//		while(q->next)
//		{
//			if(q->next->id == p->id)
//			{
//				r = q->next;
//				q->next = r->next;
//				free(r);//*****
//			}
//			else
//			{
//				q = q->next;printf("******\n");
//			}
//				
//		}
//		p = p->next;
//	}
//}
//
//int main()
//{
//	Student *p1, *p2;
//	p1 = p2 = (Student*)malloc(sizeof(Student));
//	scanf("%d",&p1->id);
//	while(p1->id != 0)
//	{
//		if(NULL == head)
//			head = p1;
//		else
//			p2->next = p1;
//		p2 = p1;
//		p1 = (Student*)malloc(sizeof(Student));
//		scanf("%d",&p1->id);
//	}
//	p2->next = NULL;
//	print();
//	printf("\n\n--------After delete--------\n\n");
//	delete_repetition();
//	print();
//	return 0;
//}

//
////linked List reverse
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct s{
//	int id;
//	struct s *next;
//}Student;
//
//Student *head = NULL;
//
//void print()
//{
//	printf("\n--------printing start--------\n");
//	if(NULL == head)
//		return ;
//	Student* p = head;
//	while(p)
//	{
//		printf("%d\n",p->id);
//		p = p->next;
//	}
//	printf("\n--------printing end--------\n");	
//}
//
//void reverse()
//{
//	Student *p1, *p2;
//	p1 = p2 = head;
//	head = NULL;
//	while(p1)
//	{
//		p2 = p1;
//		p1 = p1->next;
//		p2->next = head;
//		head = p2;
//	}
//}
//int main()
//{
//	Student *p1, *p2;
//	p1 = p2 = (Student*)malloc(sizeof(Student));
//	scanf("%d",&p1->id);
//	while(p1->id != 0)
//	{
//		if(NULL == head)
//			head = p1;
//		else
//			p2->next = p1;
//		p2 = p1;
//		p1 = (Student*)malloc(sizeof(Student));
//		scanf("%d",&p1->id);
//	}
//	p2->next = NULL;
//	print();
//	printf("\n\n--------After reverse--------\n\n");
//	reverse();
//	print();
//	return 0;
//}

////Linked List test
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//struct test_struct
//{
//    int val;
//    struct test_struct *next;
//};
//
//struct test_struct *head = NULL;
//struct test_struct *curr = NULL;
//
//struct test_struct* create_list(int val)
//{
//    printf("\n creating list with headnode as [%d]\n",val);
//    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
//    if(NULL == ptr)
//    {
//        printf("\n Node creation failed \n");
//        return NULL;
//    }
//    ptr->val = val;
//    ptr->next = NULL;
//
//    head = curr = ptr;
//    return ptr;
//}
//
//struct test_struct* add_to_list(int val, bool add_to_end)
//{
//    if(NULL == head)
//    {
//        return (create_list(val));
//    }
//
//    if(add_to_end)
//        printf("\n Adding node to end of list with value [%d]\n",val);
//    else
//        printf("\n Adding node to beginning of list with value [%d]\n",val);
//
//    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
//    if(NULL == ptr)
//    {
//        printf("\n Node creation failed \n");
//        return NULL;
//    }
//    ptr->val = val;
//    ptr->next = NULL;
//
//    if(add_to_end)
//    {
//        curr->next = ptr;
//        curr = ptr;
//    }
//    else
//    {
//        ptr->next = head;
//        head = ptr;
//    }
//    return ptr;
//}
//
//struct test_struct* search_in_list(int val, struct test_struct **prev)
//{
//    struct test_struct *ptr = head;
//    struct test_struct *tmp = NULL;
//    bool found = false;
//
//    printf("\n Searching the list for value [%d] \n",val);
//
//    while(ptr != NULL)
//    {
//        if(ptr->val == val)
//        {
//            found = true;
//            break;
//        }
//        else
//        {
//            tmp = ptr;
//            ptr = ptr->next;
//        }
//    }
//
//    if(true == found)
//    {
//        if(prev)
//            *prev = tmp;
//        return ptr;
//    }
//    else
//    {
//        return NULL;
//    }
//}
//
//int delete_from_list(int val)
//{
//    struct test_struct *prev = NULL;
//    struct test_struct *del = NULL;
//
//    printf("\n Deleting value [%d] from list\n",val);
//
//    del = search_in_list(val,&prev);
//    if(del == NULL)
//    {
//        return -1;
//    }
//    else
//    {
//        if(prev != NULL)
//        {
//        	prev->next = del->next;
//		}
//           
//
//        if(del == curr)
//        {
//            curr = prev;
//        }
//        else if(del == head)
//        {
//            head = del->next;
//        }
//    }
//
//    free(del);
//    del = NULL;
//
//    return 0;
//}
//
//
//void print_list(void)
//{
//    struct test_struct *ptr = head;
//
//    printf("\n -------Printing list Start------- \n");
//    while(ptr != NULL)
//    {
//        printf("\n [%d] \n",ptr->val);
//        ptr = ptr->next;
//    }
//    printf("\n -------Printing list End------- \n");
//
//    return;
//}
//
//int main(void)
//{
//    int i = 0, ret = 0;
//    struct test_struct *ptr = NULL;
//
//    print_list();
//
//    for(i = 5; i<10; i++)
//        add_to_list(i,true);
//
//    print_list();
//
//    for(i = 4; i>0; i--)
//        add_to_list(i,false);
//
//    print_list();
//
//    for(i = 1; i<10; i += 4)
//    {
//        ptr = search_in_list(i, NULL);
//        if(NULL == ptr)
//        {
//            printf("\n Search [val = %d] failed, no such element found\n",i);
//        }
//        else
//        {
//            printf("\n Search passed [val = %d]\n",ptr->val);
//        }
//
//        print_list();
//
//        ret = delete_from_list(i);
//        if(ret != 0)
//        {
//            printf("\n delete [val = %d] failed, no such element found\n",i);
//        }
//        else
//        {
//            printf("\n delete [val = %d]  passed \n",i);
//        }
//
//        print_list();
//    }
//
//    return 0;
//}
//
////动态链表
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct s
//{
//	float num ;
//	int score;
//	struct s *next;
//} Student;
//Student* creat()
//{
//	Student *head, *p1, *p2;
//	p1 = p2 = (Student*) malloc(sizeof(Student));
//	scanf("%f%d",&p1->num, &p1->score);
//	head = NULL;
//	while(p1->num != 0) 	
//	{
//		if(head == NULL)
//		{
//			head = p1;
//		}
//		else
//		{
//			p2->next = p1;
//		}
//		p2 = p1;
//		p1 = (Student*)malloc(sizeof(Student));
//		scanf("%f%d",&p1->num, &p1->score);
//	}
//	p2->next = NULL;
//	return head;
//}
//int main()
//{
//	Student *p;
//	p = creat();
//	while(p != NULL)
//	{
//		printf("%5f%5d\n",p->num, p->score);
//		p = p->next;
//	}
//	return 0;	
//} 



////静态链表 
//#include<stdio.h>
//typedef struct s
//{
//	float num;
//	int score;
//	struct 	s  *next;
//} Student;
//int main()
//{
//	Student a, b, c, *head, *p;
//	a.num = 100;
//	a.score = 60;
//	b.num = 110;
//	b.score = 70;
//	c.num = 111;
//	c.score = 80;
//	head = &a;
//	a.next = &b;
//	b.next = &c;
//	c.next = NULL;
//	p = head;
//	while(p != NULL)
//	{
//		printf("%5f%5d\n",p->num, p->score);
////		printf("%5f%5d\n",(*p).num, (*p).score);
////		p = (*p).next;
//		p = p->next;
//	}
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int num[100];
//int main()
//{
//    int s,t;
//	scanf("%d",&s);
//    while(s--)
//	{
//	    int i,j,t,n=0;
//	    scanf("%d",&t);
//	    for(i=0;i<t;i++)
//	    scanf("%d",&num[i]);
//	    for(i=0;i<t;i++)
//	    {
//	        for(j=i+1;j<t;j++)
//	        {
//	           if(num[i]>num[j])
//	           {
//	                int tmp;
//	                tmp=num[i];
//	                num[i]=num[j];
//	                num[j]=tmp;
//	                n++;
//	            }
//	        }
//	    }
//	    printf("Optimal train swapping takes %d swaps.\n",n);
//    }
//    return 0;
//}
//#include<stdio.h>
//#include<string.h>
//typedef struct
//{
//	int num;
//	char name[20];
//	float score;
//} Student;
//void fun(Student stu[],int n)
//{
//	int i, j, k;
//	Student temp;
//	for(i = 0; i < n - 1; i++)
//	{
//		k = i;
//		for(j = i + 1; j < n; j++)
//		{
//			if(strcmp(stu[j].name, stu[k].name) < 0)
//			{
//				k = j;
//			}		
//		}
//			temp = stu[k];
//			stu[k] = stu[i];
//			stu[i] = temp;
//	
//	}
//}
//int main()
//{
//	Student s[5] = 
//	{{10101,"Zhang",78},{10103,"Wang",98.5},{10106,"Li",86},
//	{10108,"Ling",73.5},{10110,"Sun",100}};
//	Student temp;
//	const int n = 5;
//	int i, j, k;
//	printf("The order is: \n");
//	fun(s,n);
//	for(i = 0; i < n; i++)
//	{
//		printf("%6d %8s %6.2f\n",s[i].num,s[i].name,s[i].score);
//	}
//	printf("\n");
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int total,a,b,c,len , i = 8;
//	char buf[20],buf1[20],s[20];	
//	char a1[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'} ,a2[] = {'H', 'I', 'J', 'K', 'L', 'M', 'N'};	
//	char ch[]="MemTotal:        2028248 kB";
//	sscanf(ch,"%*s%d",&total);
//	printf("%d\n",total);
//	sscanf("123456","%4s",buf);
//	printf("%s\n",buf);
//	sscanf("123456 asdf","%[^ ]",buf1);
//	printf("%s\n",buf1);
//	sscanf("123456 asdfgh","%*[^2]%[^d]",buf1);
//	printf("%s\n",buf1);
//	sscanf("hello, world","%*s%s",buf1);
//	printf("%s\n",buf1);
//	sscanf("2006:03:18","%d:%d:%d",&a,&b,&c);
//	printf("%d %d %d\n",a,b,c);
//	sscanf("2006:03:18 - 2006:04:18","%s - %s",buf,buf1);
//	printf("%s %s\n",buf,buf1);
//	sscanf("2006:03:18-2006:04:18","%[0-9,:]%[0-9,:]",buf,buf1);
//	printf("%s %s\n",buf,buf1);
//
//	sprintf(s, "%d", 123); //产生"123"
//	printf("%s\n",s);
//	sprintf(s, "%08X", 4567); //产生："000011D7"
//	printf("%s\n",s);
//	sprintf(s, "%.7s%.7s", a1, a2);//产生："ABCDEFGHIJKLMN"//下面两句结果一样 
//	//	sprintf(s, "%.*s%.*s", 7, a1, 7, a2);
//	//　　sprintf(s, "%.*s%.*s", sizeof(a1), a1, sizeof(a2), a2);
//	printf("%s\n",s);
//	sprintf(s, "%.6s%.5s", a1, a2);//产生："ABCDEFHIJKL"
//	printf("%s\n",s);
//	sprintf(s, "%-*d", 4, 'A'); //产生"65 "
//	printf("%s\n",s);
//	sprintf(s,"%*.*f",2,3,3.1415926);//产生" 3.14"
//	printf("%s\n",s);	
//	sprintf(s,"%#0*x",8,128);//产生"0X000080"，"#"产生0X
//	printf("%s\n",s);
//	len = sprintf(s, "%d", i);
//	printf("%d\n",len);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
////	FILE *fin ,*fout;
////	fin = fopen("triangle.in","rb");
////	fout = fopen("triangle.out","wb");
//	int x , i , j , k;
//	while(scanf("%d",&x) == 1)
//	{
//		for(i = 5 ; i >= 0 ;i--)
//		{
//			for(j = x ; j > i ; j--)
//				printf(" ");
//			for(k = 2 * i ; k >= 0 ;k--)
//				printf("#");
//		printf("\n");
//		}
//	}
////	fclose(fout);
////	fclose(fin);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	double i;
//	double j = 10.0;
//	for(i = 0;i != j; i += 0.1)
//	{
//		if(i > 11)
//			break;
//		printf("%lf\n",i);n
//	}
//	return 0;
//}

//#include<stdio.h>  
//#include<string.h>  
// 
//char Matrix[51][51]; 
//char str[21],temp[21]; 
//int StartR,StartC; 
////M行 N列  
//int Match(int M,int N,int &StartR,int &StartC){ 
//    int i,j,k,flag; 
//    StartR = 51,StartC = 51; 
//    int len = strlen(str); 
//    for(i = 0;i < M;i++){ 
//        for(j = 0;j < N;j++){ 
//            flag = 1; 
//            //left - right  
//            if(j + len <= N){ 
//                flag = 0; 
//                for(k = 0;k < len;k++){ 
//                    if(str[k] != Matrix[i][j+k]){ 
//                        flag = 1; 
//                        break; 
//                    } 
//                } 
//                if(flag == 0){ 
//                    if(StartR >  i){ 
//                        StartR = i+1; 
//                        StartC = j+1; 
//                    } 
////                    else if(StartR ==  i+1 && StartC > j+1){ 
////                        StartR = i+1; 
////                        StartC = j+1; 
////                    } 
//                } 
//            } 
//            //right - left  
//            if(j - len + 1>= 0){ 
//                flag = 0; 
//                for(k = 0;k < len;k++){ 
//                    if(str[k] != Matrix[i][j-k]){ 
//                        flag = 1; 
//                        break; 
//                    } 
//                } 
//                if(flag == 0){ 
//                    if(StartR >  i){ 
//                        StartR = i+1; 
//                        StartC = j+1; 
//                    } 
////                    else if(StartR ==  i+1 && StartC > j+1){ 
////                        StartR = i+1; 
////                        StartC = j+1; 
////                    } 
//                } 
//            } 
//            //up - down  
//            if(i + len <= M){ 
//                flag = 0; 
//                for(k = 0;k < len;k++){ 
//                    if(str[k] != Matrix[i+k][j]){ 
//                        flag = 1; 
//                        break; 
//                    } 
//                } 
//                if(flag == 0){ 
//                    if(StartR >  i){ 
//                        StartR = i+1; 
//                        StartC = j+1; 
//                    } 
////                    else if(StartR ==  i+1 && StartC > j+1){ 
////                        StartR = i+1; 
////                        StartC = j+1; 
////                    } 
//                } 
//            } 
//            //down - up  
//            if(i - len + 1 >= 0){ 
//                flag = 0; 
//                for(k = 0;k < len;k++){ 
//                    if(str[k] != Matrix[i-k][j]){ 
//                        flag = 1; 
//                        break; 
//                    } 
//                } 
//                if(flag == 0){ 
//                    if(StartR >  i){ 
//                        StartR = i+1; 
//                        StartC = j+1; 
//                    } 
////                    else if(StartR ==  i+1 && StartC > j+1){ 
////                        StartR = i+1; 
////                        StartC = j+1; 
////                    } 
//                } 
//            } 
//            //right - up  
//            if(j + len <= N && i - len + 1 >= 0){ 
//                flag = 0; 
//                for(k = 0;k < len;k++){ 
//                    if(str[k] != Matrix[i-k][j+k]){ 
//                        flag = 1; 
//                        break; 
//                    } 
//                } 
//                if(flag == 0){ 
//                    if(StartR >  i){ 
//                        StartR = i+1; 
//                        StartC = j+1; 
//                    } 
////                    else if(StartR ==  i+1 && StartC > j+1){ 
////                        StartR = i+1; 
////                        StartC = j+1; 
////                    } 
//                } 
//            } 
//            //right - down  
//            if(j + len <= N && i + len <= M){ 
//                flag = 0; 
//                for(k = 0;k < len;k++){ 
//                    if(str[k] != Matrix[i+k][j+k]){ 
//                        flag = 1; 
//                        break; 
//                    } 
//                } 
//                if(flag == 0){ 
//                    if(StartR >  i){ 
//                        StartR = i+1; 
//                        StartC = j+1; 
//                    } 
////                    else if(StartR ==  i+1 && StartC > j+1){ 
////                        StartR = i+1; 
////                        StartC = j+1; 
////                    } 
//                } 
//            } 
//            //left - up  
//            if(j - len + 1 >= 0 && i - len + 1 >= 0){ 
//                flag = 0; 
//                for(k = 0;k < len;k++){ 
//                    if(str[k] != Matrix[i-k][j-k]){ 
//                        flag = 1; 
//                        break; 
//                    } 
//                } 
//                if(flag == 0){ 
//                    if(StartR >  i){ 
//                        StartR = i+1; 
//                        StartC = j+1; 
//                    } 
////                    else if(StartR ==  i+1 && StartC > j+1){ 
////                        StartR = i+1; 
////                        StartC = j+1; 
////                    } 
//                } 
//            } 
//            //left - down  
//            if(j - len + 1 >= 0 && i + len <= M){ 
//                flag = 0; 
//                for(k = 0;k < len;k++){ 
//                    if(str[k] != Matrix[i-k][j+k]){ 
//                        flag = 1; 
//                        break; 
//                    } 
//                } 
//                if(flag == 0){ 
//                    if(StartR >  i){ 
//                        StartR = i+1; 
//                        StartC = j+1; 
//                    } 
////                    else if(StartR ==  i+1 && StartC > j+1){ 
////                        StartR = i+1; 
////                        StartC = j+1; 
////                    } 
//                } 
//            } 
//        }//for j  
//    }//for i  
//    return 0; 
//} 
// 
//int main (){ 
//    int i,j,Case,k,M,N; 
//    //freopen("C:\\Users\\XIAOSI\\Desktop\\acm.txt","r",stdin);    
//    while(scanf("%d",&Case) != EOF){ 
//        while(Case--){ 
//            scanf("%d %d",&M,&N); 
//            //输入字符矩阵  
//            for(i = 0;i < M;i++){ 
//                scanf("%s",temp); 
//                for(j = 0;j < N;j++){ 
//                    Matrix[i][j] = temp[j]; 
//                    //转换为小写  
//                    if(Matrix[i][j] >= 'A' && Matrix[i][j] <= 'Z'){ 
//                        Matrix[i][j] = Matrix[i][j] - 'A' + 'a'; 
//                    } 
//                } 
//            } 
//            scanf("%d",&k); 
//            //待匹配串  
//            for(i = 0;i < k;i++){ 
//                scanf("%s",str); 
//                int len = strlen(str); 
//                //转换为小写  
//                for(j = 0;j < len;j++){ 
//                    if(str[j] >= 'A' && str[j] <= 'Z'){ 
//                        str[j] = str[j] - 'A' + 'a'; 
//                    } 
//                } 
//                //printf("%s",str);  
//                Match(M,N,StartR,StartC); 
//                printf("%d %d\n",StartR,StartC); 
//            } 
//            //每组测试之间有空行  
//            if(Case){ 
//                printf("\n"); 
//            } 
//        } 
//    } 
//    return 0; 
//} 



//
//#include<stdio.h>
//void test(int *a)
//{
//	*a = 20;
//	if(*a >  10)
//		*a = 10;
//}
//int main()
//{
//	int a , b;
//	a = 3 , b = 4;
//	test(&a);
//	printf("%d",a);
//}
