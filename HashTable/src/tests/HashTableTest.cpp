#include <gtest/gtest.h>
#include "../HashTable.h"

class HashTableTest : public testing::Test {
    public:
        HashTableTest() {
        }

        virtual ~HashTableTest() {
        }
};

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
