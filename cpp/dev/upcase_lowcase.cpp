#include <stdio.h>
int main()
{
 	char a[6] = "BaSiC";
	char b[6] = "MinIX";
	int i;
	for (i = 0; i < 5; i++) {
		a[i] = a[i] & 0xDF;	// 11011111
		b[i] = b[i] | 0x20;	// 00100000
	}	
	printf("%s\n", a);
	printf("%s\n", b);
	return 0;
}
