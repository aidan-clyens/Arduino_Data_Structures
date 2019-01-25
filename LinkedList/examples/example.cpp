#include <iostream>
#include "../src/LinkedList.h"

int main() {
    LinkedList<int> list;

    for (int i = 0; i < 10; i++) {
        list.push_back(i);
    }

    for (int i = 0; i < 10; i++) {
        list.push_front(2*i);
    }

    std::cout << "size = " << list.size() << std::endl;

    list.print();

    return 0;
}
