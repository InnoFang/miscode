#include <iostream>
#include <string>

using namespace std;

int main() {
	string str1 = "123", str2 = "456";
	cout << str1 + str2 << endl;
	cout << (str1 > str2) << endl;
	cout << (str1 == str2) << endl;
	cout << (str1 < str2) << endl;
	getline(cin, str1);
	cout << str1 << endl;
	return 0;
}
