#include<iostream>
using namespace std;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		int **triangle = new int*[n + 1];
		for(int i = 0; i <= n; i++)
			triangle[i] = new int[i + 1];

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				if (j == 0 || j == i-1)
					triangle[i-1][j] = 1;
				else
					triangle[i-1][j] = triangle[i-2][j-1] + triangle[i-2][j];
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				printf("\t%d", triangle[i][j]);
			}
			putchar('\n');
		}
	}
}
