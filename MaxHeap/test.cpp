#include <iostream>
#include "MaxHeap.h"

using namespace std;

int main() {
  MaxHeap<int> heap;

  heap.push(4);
  heap.push(10);
  heap.push(8);
  heap.push(9);
  heap.push(15);
  heap.push(7);
  heap.push(2);
  heap.push(11);

  cout << "Order should be: 15\nTop = " << heap.top() << endl;
  heap.print_heap();

  heap.pop();

  cout << endl;

  return 0;
}
