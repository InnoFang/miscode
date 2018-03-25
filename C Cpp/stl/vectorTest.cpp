#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> arr;
	for (int i = 0; i < 10; i++) {
		arr.push_back(i);
	}
	for (vector<int>::iterator i = arr.begin(); i != arr.end(); i++) {
		cout << *i << endl;
	}
	
	cout << endl;
	
	arr.pop_back();
	arr.push_back(11);
	arr.erase(arr.begin());
	arr.insert(arr.begin() + 3, 111);
	for (vector<int>::reverse_iterator i = arr.rbegin(); i != arr.rend(); i++) {
		cout << *i << endl;
	} 
	
	cout << "size " << arr.size() << endl;
	cout << "max size " << arr.max_size() << endl;
	cout << "capacity " << arr.capacity() << endl;
	cout << "empty? " << arr.empty() << endl;
	return 0;
}
