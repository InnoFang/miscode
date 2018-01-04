#include<stdio.h>
int main()
{
	const char *s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	int i , c ;
	while ((c = getchar ()) != EOF)
	{
		for(i = 1 ; s[i] && s[i] != c ;i++);//ø’”Ôæ‰ 
		if(s[i])
			putchar(s[i-1]);
		else
			putchar(c);
	} 
	return 0;
}
