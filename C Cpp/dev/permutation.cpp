/*
*用1，2，3···9组成3个三位数abc，def和ghi，每个数字恰好使用一次，要求abc:def:ghi=1:2:3。输出所有解 
*/
#include<stdio.h>
int main()
{
	freopen("permutation.out","w",stdout);
	int a,b,c,d,e,f,g,h,i;
	for(a = 1 ; a <= 9 ; a++)
	{
		for(b = 1 ; b <= 9 ; b++)
		{
			if(b == a)
				continue;
			for(c = 1 ; c <= 9 ; c++)
			{
				if(c == b || c == a)
					continue;
				for(d = 1 ; d <= 9 ; d++)
				{
					if(d == c || d == b || d == a)
						continue;
					for(e = 1 ; e <= 9 ; e++)
					{
						if(e == d || e == c || e == b || e == a)
							continue;
						for(f = 1 ; f <= 9 ; f++)
						{
							if(f == e || f == d || f == c || f == b || f == a)
								continue;
							for(g = 1 ; g <= 9 ; g++)
							{
								if(g == f || g == e || g == d || g == c || g == b || g == a)
									continue;
								for(h = 1 ; h <= 9 ; h++)
								{
									if(h == g || h == f || h == e || f == d || f == c || f == b || f == a)
										continue;
									for(i = 1 ; i <= 9 ; i++)
									{
										if(i == h || i == g || i == f || i == e || i == d || i == c || i == b || i == a)
											continue;
										if(2 * (a * 100 + b * 10 + c) == (d * 100 + e * 10 + f) && 
											3 * (a * 100 + b * 10 + c) == (g * 100 + h * 10 + i))
											printf("%d %d %d \n",a * 100 + b * 10 + c,d * 100 + e * 10 + f,g * 100 + h * 10 + i);
									}
								}
							}
						}
					}
				}
			}
		}
	} 
	return 0;
}
