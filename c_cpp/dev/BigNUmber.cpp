#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
using namespace std;
const int maxn = 1000;
struct bign
{
	int len, s[maxn];
	bign()
	{
		memset(s,0,sizeof(s));
		len = 1;
	}
	//=号重载，将字符串转换为数字 
	bign operator=(const char *num)
	{
		len = strlen(num);
		for(int i = 0; i < len; i++)
		{
			s[i] = num[len-i-1] - '0';
		}
		return *this;
	}
	//=号重载，将数字转换为字符串 
	bign operator=(int num)
	{
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;				
	}
	
	
	//bign 初始化 
	bign (int num)
	{
		*this = num;
	}
	bign (const char *num)
	{
		*this = num;
	}
	
	
	//将初始化后的数转化为字符串
	string str() const
	{
		string res = "";
		for(int i = 0; i < len; i++)
		{
			res = (char)(s[i] + '0') + res;
		} 
		if(res == "")
			res = "0";	
		return res;
	}	 
	
	
	//+号重载
	bign operator+(const bign &b) const
	{
		bign c;
		c.len = 0;
		for(int i = 0, g = 0; g || i < max(len, b.len); i++) //g用于进位,
		//g || i < max(len, b.len) 作用是，例如 3+9 ，两个的长度都为1，但是两个相加有一个进位，那么循环还要进行一次，并把这个进位放到数组下一位 
		{
			int x = g;  //保存进位 
			if(i < len)
			{
				x += s[i];
			}
			if(i < b.len)
			{
				x += b.s[i];
			}
			c.s[c.len++] = x % 10;
			g = x / 10; //检测进位 
		}
		return c; 
	} 
	
	
	//+=重载
	bign operator+=(const bign& b)
	{
		*this = *this + b;
		return *this;	
	} 
	
	
	//<号重载
	bool operator<(const bign &b) const
	{
		if(len != b.len)
		{
			return len < b.len;
		}
		for(int i = len - 1; i >= 0; i--)
		{
			if(s[i] != b.s[i])
			{
				return s[i] < b.s[i];
			}
		}
		return false;
	} 
	//> , <= , >= , != , == 号重载
	bool operator>(const bign &b) const 
	{
		return b < *this;
	}
	bool operator<=(const bign &b) const 
	{
		return !(b < *this);
	} 
	bool operator>=(const bign &b) const 
	{
		return !(*this < b);
	}
	bool operator!=(const bign &b) const 
	{
		return b < *this || *this < b;
	}
	bool operator==(const bign &b) const 
	{
		return !(b < *this) && !(*this < b);
	}
};
//输入，输出运算符重载
	istream& operator>>(istream &in, bign &x)
	{
		string s;
		in >> s;
		x = s.c_str();
		return in;
	}
	ostream& operator<<(ostream &out, bign &x)
	{
		out << x.str();
		return out;	
	} 
int main()
{
	bign a, b, c, d, e, f;
	c = 0;
	while(cin >> b)
	{
		if(b == c)
			break;
		a += b;
	}
	cout << a << endl;
//	while(cin >> a >> b)
//	{
//		c = a + b;
//		cout << "a + b = " << c << endl;
//		c += a;
//		cout << "c += a ==> " << c << endl;
//		bool h = a < b;
//		cout << "a < b ==> " << h << endl;
//		h = a>b;
//		cout << "a > b ==> " << h << endl;
//		cin >> d;
//		h = a<=d;
//		cout << "a <= d ==> " << h << endl;
//		cout << "input the e:"<<endl;
//		cin >> e;
//		h = a>=e;
//		cout << "a >= e ==> " << h << endl;
//		cout << "input the f:" << endl;
//		cin >> f;
//		h = a==f;
//		cout << "a == f ==> " << h << endl;
//		h = a!=f;
//		cout << "a != f ==> " << h << endl; 
//	}
	return 0;
}
