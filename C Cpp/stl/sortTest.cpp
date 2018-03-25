#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cmp(string s, string c) {
	return s > c;
}

int main() {
	vector<string> arr;
	arr.push_back("123");
	arr.push_back("112");
	arr.push_back("012");
	arr.push_back("12345");
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	sort(arr.rbegin(), arr.rend());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
    cout << endl;
    
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	sort(arr.begin(), arr.end(), greater<string>());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
    cout << endl;	
	
	sort(arr.begin(), arr.end(), less<string>());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
