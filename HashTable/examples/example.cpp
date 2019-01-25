#include <iostream>
#include "../src/HashTable.h"

int main() {
    HashTable<int> table;

    table.insert(5);
    table.insert(1);
    table.insert(6);
    table.insert(10);
    table.insert(12);
    table.insert(20);
    table.insert(15);

    table.erase(12);
    table.erase(6);

    std::cout << "size = " << table.size() << std::endl;
    std::cout << "load_factor = " << table.load_factor() << std::endl;

    table.print();

    return 0;
}
