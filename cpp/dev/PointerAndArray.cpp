#include <stdio.h>

int main()
{
	int i;
	int nums[][3] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	int *p[3];
	int (*q)[3];
	q = nums;	// 数组指针指向二维数组 
	
	for(i = 0; i < 3; i++){// 将二维数组的值赋给指针数组 
		p[i] = nums[i];
	}
	
	/*
	char s[4][11] = {
	    "computer",
		"science",
		"and",
		"technology"
	};
	
	char *arr[4];
	int i;
	for(i =0; i < 4; i++) {
		arr[i] = s[i];
	}
	
	//char *arr[] ={
	//	"computer",
	//	"science",
	//	"and",
	//	"technology"	
	//};

	printf("%s\n", *(arr + 0));
	printf("%s\n", *(arr + 1));
	printf("%s\n", *(arr + 2));
	printf("%s\n", *(arr + 3));
	putchar('\n');
	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);
	printf("%s\n", arr[2]);
	printf("%s\n", arr[3]);
	putchar('\n');
	printf("%c\n", *arr[0]);
	printf("%c\n", *arr[1]);
	printf("%c\n", *arr[2]);
	printf("%c\n", *arr[3]);
	putchar('\n');
	printf("%c\n", *(*(arr + 0) + 2));
	printf("%c\n", *(*(arr + 1) + 2));
	printf("%c\n", *(*(arr + 2) + 2));
	printf("%c\n", *(*(arr + 3) + 2));
	*/
		

//	char (*p)[4];
//	char arr[4][4] = {"HaHa","XiXi","DuDu","TaTa"};
//	p = arr;
//		
	
	return 0;	
} 
