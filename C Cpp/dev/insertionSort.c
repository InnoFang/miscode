/*≤Â»Î≈≈–Ú*/
#include<stdio.h>
void insertionSort(int arr[], int n)
{
	int i, j;
	for(i = 1; i < n; i++)
	{
		int temp = arr[i];
		for(j = i; j > 0 && temp < arr[j-1]; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

int main()
{
	int i;
	int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
	int length = sizeof(arr) / sizeof(int);
	insertionSort(arr, length);
	for(i = 0; i < length; i++)
		printf("%d ", arr[i]);
	return 0;
}
