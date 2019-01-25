#include <iostream>
#include "../src/MaxHeap.h"

int main() {
    MaxHeap<int> heap;

    heap.push(5);
    heap.push(4);
    heap.push(8);
    heap.push(2);

    std::cout << "size = " << heap.size() << std::endl;
    std::cout << "top = " << heap.top() << std::endl;
    std::cout << "is max heap: " << heap.is_max_heap(0) << std::endl;

    heap.print();

    return 0;
}
