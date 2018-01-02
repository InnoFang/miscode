#include<stdio.h>
#include<string.h>
int main()
{
	char s[20];
	while(scanf("%s",s) != EOF)
	{
		int pal_flag = 1,mir_flag = 1;
		int n = strlen(s);
		int i , j;
		for(i = 0,j = n - 1; i <= (n - 1) / 2 ; i++, j--)
		{
			if(s[i] != s[j])
			{
				pal_flag = 0;
			}
			if(!(((s[i] == '3') && ( s[j] == 'E')) ||
			((s[i] == 'E') && ( s[j] == '3')) || ((s[i] == 'J') && ( s[j] == 'L')) ||
			((s[i] == 'L') && ( s[j] == 'J')) || ((s[i] == 'S') && ( s[j] == '2')) ||
			((s[i] == '2') && ( s[j] == 'S')) || ((s[i] == 'Z') && ( s[j] == '5')) ||
			((s[i] == '5') && ( s[j] == 'Z')) || ((s[i] == 'O') && ( s[j] == 'O')) ||
			((s[i] == 'H') && ( s[j] == 'H')) || ((s[i] == 'I') && ( s[j] == 'I')) ||
			((s[i] == 'M') && ( s[j] == 'M')) || ((s[i] == 'T') && ( s[j] == 'T')) ||
			((s[i] == 'U') && ( s[j] == 'U')) || ((s[i] == 'V') && ( s[j] == 'V')) ||
			((s[i] == 'W') && ( s[j] == 'W')) || ((s[i] == 'X') && ( s[j] == 'X')) ||
			((s[i] == 'Y') && ( s[j] == 'Y')) || ((s[i] == '1') && ( s[j] == '1')) ||
			((s[i] == '8') && ( s[j] == '8')) || ((s[i] == 'A') && ( s[j] == 'A'))))
			 {
			 	mir_flag = 0;
			 }	 			 
			 if(pal_flag == 0 || mir_flag == 0){
			 	break;
			 }
			 	
		}
		if(pal_flag == 0 && mir_flag == 0)
		{
			printf("%s -- is not a palindrome.\n\n",s);
		}
		else if(pal_flag == 1 && mir_flag == 0)
		{
			printf("%s -- is a regular palindrome.\n\n",s);
		}
		else if(pal_flag == 0 && mir_flag == 1)
		{
			printf("%s -- is a mirrored string.\n\n",s);
		}
		else if(pal_flag == 1 && mir_flag == 1)
		{
			printf("%s -- is a mirrored palindrome.\n\n",s);
		}
	}
	return 0;
}
