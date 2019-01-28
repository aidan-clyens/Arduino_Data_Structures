#include <gtest/gtest.h>
#include "../SearchTree.h"

class SearchTreeTest : public testing::Test {
    public:
        SearchTreeTest() {
        }

        virtual ~SearchTreeTest() {
        }
};

TEST(SearchTreeTest, Initialize) {
    SearchTree<int> tree;

    ASSERT_EQ(-1, tree.height());
    ASSERT_EQ(1, tree.empty());
    ASSERT_EQ(0, tree.size());
    ASSERT_EQ(1, tree.is_search_tree());
}

TEST(SearchTreeTest, Insert) {
    SearchTree<int> tree;

    tree.insert(5);
    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(6);

    ASSERT_EQ(3, tree.height());
    ASSERT_EQ(0, tree.empty());
    ASSERT_EQ(5, tree.size());
    ASSERT_EQ(5, tree.top());
    ASSERT_EQ(1, tree.is_search_tree());
}

TEST(SearchTreeTest, InsertDuplicate) {
    SearchTree<int> tree;

    tree.insert(1);
    tree.insert(1);
    tree.insert(1);
    tree.insert(1);
    tree.insert(1);

    ASSERT_EQ(0, tree.height());
    ASSERT_EQ(0, tree.empty());
    ASSERT_EQ(1, tree.size());
    ASSERT_EQ(1, tree.top());
    ASSERT_EQ(1, tree.is_search_tree());

}

TEST(SearchTreeTest, InsertAllRightSide) {
    SearchTree<int> tree;
    int size = 20;

    for (int i = 0; i < size; i++) {
        tree.insert(i);
    }

    ASSERT_EQ(size-1, tree.height());
    ASSERT_EQ(0, tree.empty());
    ASSERT_EQ(size, tree.size());
    ASSERT_EQ(0, tree.top());
    ASSERT_EQ(1, tree.is_search_tree());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
