#include <iostream>
#include "../src/QueueList.h"

int main() {
    QueueList<int> queue;

    queue.push(10);
    queue.push(9);
    queue.push(8);
    queue.push(2);
    queue.push(4);
    
    queue.pop();

    queue.print();

    return 0;
}
