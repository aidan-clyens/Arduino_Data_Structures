#include <iostream>
#include "../src/SearchTree.h"

int main() {
    SearchTree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(4);
    tree.insert(12);
    tree.insert(16);

    tree.print();

    return 0;
}
