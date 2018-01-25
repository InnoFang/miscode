#include<stdio.h>
#include<stack>
#include<string.h>
const int maxn = 130;

using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		stack<char> s;
		char str[maxn];
		gets(str);
		s.push('0');
		int ok = 1;
		for(int i = 0; i < strlen(str); i++)
		{
			if(str[i] == '(' || str[i] == '[')
			{
				s.push(str[i]);
			}
			else if(str[i] == ')')
			{
				if(s.top() == '(' )
				{
					s.pop();
				}
				else
				{
					ok = 0;
					break;
				}
			}
			else if(str[i] == ']')
			{
				if(s.top() == '[' )
				{
					s.pop();
				}
				else
				{
					ok = 0;
					break;
				}
			}
		}
		if(str[0] == '\n' || (s.size() == 1 && ok))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
//#include<stdio.h>
//#include<stack>
//#include<string.h>
//using namespace std;
//const int maxn = 130;
//char fun(char c)
//{
//	if(c == ')')
//		return '(';
//	if(c == ']')
//		return '[';
//	return 0;
//}
//int judge(char *str)
//{
//	stack<char> s;
//	s.push('0');
//	for(int i = 0; i < strlen(str); i++)
//	{
//		if(s.top() != fun(str[i]))
//			s.push(str[i]);
//		else
//			s.pop();
//	}
//	printf("%d\n",s.size());
//	return s.size() == 1;
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	getchar();
//	while(n--)
//	{
//		char str[maxn];
//		gets(str);
//		if(str[0] == '\n' || judge(str))
//		{
//			printf("Yes\n");
//		}
//		else
//		{
//			printf("No\n");
//		}
//	}
//	return 0;
//}

//#include <iostream>
//#include<deque>
//#include<algorithm>
//#include<cstdio>
//#include<stack>
//#include<string>
//using namespace std;
//char f(char c)
//{
//    if(c==')')return '(';
//    if(c==']')return '[';
//    return 0;
//}
//bool judge(const string& s)
//{
//    stack<char>st;
//    st.push('0');
//    for(int i=0;i<s.size();i++)
//    {
//        if(st.top()!=f(s[i]))
//        st.push(s[i]);
//        else st.pop();
//    }
//    printf("s.size() = %d\n",s.size());
//    return st.size()==1;
//}
//
//
//int main()
//{
//    int n;
//    cin>>n;
//    string s;
//    getchar();
//    while(n--)
//    {
//        getline(cin,s);
//        if(s.size()==0||judge(s))cout<<"Yes"<<endl;
//        else cout<<"No"<<endl;
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<stack>
//#include<string.h>
//using namespace std;
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	getchar();
//	while(n--)
//	{
//		
//		stack<char> s1;
//		stack<char> s2;
//		char c;
//		while(scanf("%c",&c) != EOF)
//		{
//			s1.push(c);
//			if(c == '\n')
//			{
//				break;
//			}
//		}
//		if(s1.size() == 1)
//		{
//			printf("Yes\n");
//		}
//		else
//		{
//			int flag = 0;
//			while(s1.size())
//			{
//				switch(s1.top())
//				{
//					case ')':
//					case ']':
//						s2.push(s1.top());
//						break;
//					case '(':
//						if(s2.top() != ')')
//						{
//							s2.pop();
//							flag = 1;
//							break;
//						}
//						s2.pop();
//						break;
//					case '[':
//						if(s2.top() != ']')
//						{
//							s2.pop();
//							flag = 1;
//							break;
//						}
//						s2.pop();
//						break;
//					default:
//						break;
//				}
//				if(flag)
//				{
//					break;
//				}
//				s1.pop();
//			}
//			if(s2.empty())
//			{
//				printf("Yes\n");
//			}
//			else
//			{
//				printf("No\n");
//			}
//		}
//	}
//}

//#include<stdio.h>
//#include<string.h>
//#include<stack>
//using namespace std;
//int main()
//{
//	int n, ok = 1;
//	scanf("%d",&n);
//	getchar();
//	while(n--)
//	{
//		char c;
//		while(scanf("%c",&c) != EOF)
//		{
//			stack<char> s;
//			switch(c)
//			{
//				case '(':
//				case '[':
//					s.push(c);
//					break;
//				case ')':
//					if(s.top() != '(')
//					{
//						s.pop();
//						break;
//					}
//					s.pop();
//					break;
//				case ']':
//					if(s.top() != '[')
//					{
//						s.pop();
//						break;
//					}
//					s.pop();
//					break;
//				case '\n':
//					s.push(c);
//					if(s.size() == 1)
//					{
//						printf("Yes\n");
//						ok = 0;
//					}
//					break;
//			}
//			if(s.empty())
//			{
//				printf("Yes\n");
//			}
//			else if(ok)
//			{
//				printf("No\n");
//			}
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//#include<stack>
//using namespace std;
//const int 
//int is_right(char str[])
//{
//	stack<char> s;
//	for(int i = 0; str[i] != '\0'; i++)
//	{
//		switch(str[i])
//		{
//			case '(':
//			case '[':
//				s.push(str[i]);
//				break;
//			case ')':
//				if(s.top() != '(')
//				{
//					s.pop();
//					return 0;
//				}
//				s.pop();
//				break;
//			case ']':
//				if(s.top() != '[')
//				{
//					s.pop();
//					return 0;
//				}
//				s.pop();
//				break;
//		}
//	}
//	if(s.empty())
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	getchar();
//	while(n--)
//	{
//		char c;
//		while(scanf("%c",&c) != EOF)
//		{
//			
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<stack>
//using namespace std;
//int main()
//{
//	int n;	
//	scanf("%d",&n);
//	getchar();
//	while(n--)
//	{
//		stack<char> s;
//		char c;
//		while(scanf("%c",&c) != EOF)
//		{
//			s.push(c);
//			if(s.top() == '\n')
//			{
//				s.pop();
//				break;
//			}			
//		}	
//		int brackets_right = 0, brackets_left = 0, parentheses_right = 0, parentheses_left = 0;
//		while(!s.empty())
//		{
//			if(s.top() == '(')
//			{
//				parentheses_left++;
//			}
//			else if(s.top() == ')')
//			{
//				parentheses_right++;
//			}
//			else if(s.top() == '[')
//			{
//				brackets_left++;
//			}
//			else if(s.top() == ']')
//			{
//				brackets_right++;
//			}
//			s.pop();
//		}	
//		if(parentheses_right == parentheses_left && brackets_right == brackets_left)
//		{
//			printf("Yes\n");
//		}
//		else
//		{
//			printf("No\n");
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//const int maxn = 130;
//char str[maxn];
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	while(n--)
//	{
//		scanf("%s",str);
//		int brackets_right = 0, brackets_left = 0, parentheses_right = 0, parentheses_left = 0;
//		for(int i = 0; i < strlen(str); i++)
//		{
////			printf("%c ",str[i]);
//			if(str[i] == '(')
//			{
//				parentheses_left++;
//			}
//			else if(str[i] == ')')
//			{
//				parentheses_right++;
//			}
//			else if(str[i] == '[')
//			{
//				brackets_left++;
//			}
//			else if(str[i] == ']')
//			{
//				brackets_right++;
//			}
//		}
////		printf("%d %d %d %d\n",brackets_right, brackets_left,parentheses_right,parentheses_left);
//		if(parentheses_right == parentheses_left && brackets_right == brackets_left)
//		{
//			printf("Yes\n");
//		}
//		else
//		{
//			printf("No\n");
//		}
//	}
//	return 0;
//}
