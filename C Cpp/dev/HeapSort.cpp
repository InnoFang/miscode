#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
template<typename Item>
class Heap{
public:
	Heap(int capacity) {
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	~Heap() {
		delete[] data;
	}
	
//	int size(){	return count; }
	
//	bool isEmpty() { return count == 0; }
	
	void insert(Item item) {
		assert( count + 1 <= capacity );
		data[++count] = item;
		shiftUp(count);
	}
	
	Item extractMax() {
		assert( count > 0 );
		Item ret = data[1];
		swap(data[1], data[count--]);
		shiftDown(1);
		return ret;
	}
	
//	void print() {
//		for (int i = 1; i < count; i++) 
//			cout << data[i] << " ";
//		cout << endl;
//	}
private:
    Item *data;
    int count;
    int capacity;
    void shiftUp(int k) {
    	while (k > 1 && data[k / 2] < data[k]) {
    		swap(data[k / 2], data[k]);
    		k /= 2;
		}
	}
	
	void shiftDown(int k) {
		while ( 2 * k <= count ) {
			int j = 2 * k; // 在次轮循环中， data[k] 和 data[j] 交换位置 
			if ( j + 1 <= count && data[j + 1] > data[j])	
 	            j += 1;
			if ( data[k] >= data[j])
			   break;
 		    swap( data[k], data[j] );
 		    k = j;
		}
	}
};
int main()
{
	Heap<int> heap = Heap<int>(100);
	int arr[] = {56, 26, 54, 27, 88, 21, 12, 43, 59, 90, 53, 71};
	int len = sizeof(arr) / sizeof(int);	
	for (int i = 0; i < len; i++)	// insertion
		heap.insert(arr[i]);
	for (int i = len - 1; i >= 0; i--)	// extract max
	    arr[i] = heap.extractMax();
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
