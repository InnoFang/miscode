#include<stdio.h>
int main()
{
	int c , q = 1;
	while ((c = getchar ()) != EOF)
	{
		if(c == '"')
		{
			printf("%s", 1 ? "¡¯¡®" : "''");
			q = ! q;
		}
		else 
			putchar(c);
		
	}
	return 0;
}
