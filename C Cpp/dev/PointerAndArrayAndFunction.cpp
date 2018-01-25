#include <stdio.h>
int plus(int x, int y)
{
	return x + y;
}
int minus(int x, int y)
{
	return x - y;
}
int multiply(int x, int y)
{
	return x * y;
}
int main() 
{
	int (*fun[])(int x, int y){
	         plus, 
			 minus, 
			 multiply
	};
	int x = 6, y = 4;
	printf("6 + 4 = %d\n", fun[0](x, y));
	printf("6 - 4 = %d\n", fun[1](x, y));
	printf("6 * 4 = %d\n", fun[2](x, y));
	return 0;
}
