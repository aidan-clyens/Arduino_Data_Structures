#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "MaxHeap.h"

using namespace std;

bool heapify_test() {
	LinkedList<int> top_order;
	int size = 5 + (rand() % 50);
	int max_num = 0;

	MaxHeap<int> heap(size);

	for (int i = size; i > 0; --i) {
		int num = i;
		max_num = std::max(max_num, num);
		top_order.push_front(max_num);
		heap.push(num);
	}

	if (max_num == heap.top()) return true;
	else return false;
}

void testB() {
	MaxHeap<int> heap(20);
	heap.push(10);
	heap.push(15);
	heap.push(40);
	heap.push(5);
	heap.push(25);

	cout << "top = " << heap.top() << " expected top = 40" << endl;

	heap.pop();
	heap.pop();

	cout << "top = " << heap.top() << " expected top = 15" << endl;

	heap.push(12);

	cout << "top = " << heap.top() << " expected top = 15" << endl;

	heap.push(35);

	cout << "top = " << heap.top() << " expected top = 35" << endl;

	heap.push(45);
	heap.push(50);
	heap.push(3);
	heap.push(7);

	cout << "top = " << heap.top() << " expected top = 50" << endl;

	cout << "size = " << heap.size() << endl;
}

int main() {
	srand((int)time(0));

	cout << "Heapify tests:" << endl;
	for (int i = 0; i < 20; ++i) {
		if (heapify_test()) {
			cout << "pass" << endl;
		} else {
			cout << "fail" << endl;
		}
	}

	cout << "Test B" << endl;
	testB();

	return 0;
}
