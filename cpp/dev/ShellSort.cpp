#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstring>
using namespace std;

template <typename T>
void print(T arr[], int len) {
	for ( int i = 0; i < len; i++) 
		cout << arr[i] << " ";
	cout << endl;
}

template<typename T>
void shellSortDivBy3(T arr[], int len) {
	int div = 1;
	while (div < len / 3) div = div * 3 + 1;
	while (div >= 1) {
		for(int i = div; i < len; i++) {
			T temp = arr[i];
			int j;
			for(j = i; j >= div && temp < arr[j - div]; j -= div) {
				arr[j] = arr[j - div];
			}
			arr[j] = temp;
		}
		div /= 3;
	}
}

template<typename T>
void shellSortDivBy2(T arr[], int len) {
	for(int div = len >> 1; div >= 1; div = div >> 1) {
		for(int i = div; i < len; i++) {
			T temp = arr[i];
			int j;
			for(j = i; j >= div && temp < arr[j - div]; j -= div) {
			    arr[j] = arr[j - div];
			}
			arr[j] = temp;
		}
	}
	print(arr, len); 
} 

template<typename T>
void testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n) {
	clock_t startTime = clock();
	sort(arr, n);
	clock_t endTime = clock();
	cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	return ;
}
int main() {
	int arr[] = {7, 3, 4, 1, 6, 5, 2, 9, 8, 0, 27, 18, 16, 58, 31, 11, 12, 70, 97, 94, 33, 61, 72, 89, 50, 13, 41, 59, 76, 60};
	int arr1[] = {7, 3, 4, 1, 6, 5, 2, 9, 8, 0, 27, 18, 16, 58, 31, 11, 12, 70, 97, 94, 33, 61, 72, 89, 50, 13, 41, 59, 76, 60};
	int len = sizeof(arr) / sizeof(int);
	testSort("Shell Sort divide by 2", shellSortDivBy2, arr, len);
	testSort("Shell Sort divide by 3", shellSortDivBy3, arr, len);
	return 0;
}
