#include <gtest/gtest.h>
#include "../LinkedList.h"

class LinkedListTest : public testing::Test {
    public:
        LinkedListTest() {
        }

        virtual ~LinkedListTest() {
        }
};

TEST(LinkedListTest, Initialize) {
    LinkedList<int> list;
    ASSERT_EQ(0, list.size());
    ASSERT_EQ(1, list.empty());
}

TEST(LinkedListTest, PushBack) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    ASSERT_EQ(7, list.size());
    ASSERT_EQ(0, list.empty());
    ASSERT_EQ(1, list.front());
    ASSERT_EQ(7, list.back());
}

TEST(LinkedListTest, PushFront) {
    LinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(6);
    list.push_front(7);

    ASSERT_EQ(7, list.size());
    ASSERT_EQ(0, list.empty());
    ASSERT_EQ(7, list.front());
    ASSERT_EQ(1, list.back());
}

TEST(LinkedListTest, Clear) {
    LinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    list.clear();

    ASSERT_EQ(0, list.size());
    ASSERT_EQ(1, list.empty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
