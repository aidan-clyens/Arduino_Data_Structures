#include <iostream>
#include "../src/Vector.h"

int main() {
    vector<int> vec;
    
    for (int i = 0; i < 20; i++) {
        vec.push_back(i);
    }

    std::cout << "size = " << vec.size() << std::endl;
    std::cout << "capacity = " << vec.capacity() << std::endl;
    std::cout << "front = " << vec.front() << std::endl;
    std::cout << "back = " << vec.back() << std::endl;

    vec.print();

    return 0;
}
