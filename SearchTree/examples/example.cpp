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

    std::cout << "size = " << tree.size() << std::endl;
    std::cout << "empty = " << tree.empty() << std::endl;
    std::cout << "height = " << tree.height() << std::endl;
    std::cout << "is_search_tree = " << tree.is_search_tree() << std::endl;

    return 0;
}
