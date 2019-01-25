#include <gtest/gtest.h>
#include "../Vector.h"

class VectorTest : public testing::Test {
    public:
        VectorTest() {}

        virtual ~VectorTest() {}
};

TEST(VectorTest, Initialize) {
    vector<int> vec;
    vector<int> vec2(32);

    ASSERT_EQ(0, vec.size());
    ASSERT_EQ(1, vec.empty());
    ASSERT_EQ(16, vec.capacity());
    
    ASSERT_EQ(0, vec2.size());
    ASSERT_EQ(1, vec2.empty());
    ASSERT_EQ(32, vec2.capacity());
}

TEST(VectorTest, PushBack) {
    vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);

    ASSERT_EQ(7, vec.size());
    ASSERT_EQ(0, vec.empty());
    ASSERT_EQ(16, vec.capacity());
    ASSERT_EQ(1, vec.front());
    ASSERT_EQ(7, vec.back());
    ASSERT_EQ(3, vec.at(2));
    ASSERT_EQ(3, vec[2]);
    ASSERT_EQ(5, vec.at(4));
    ASSERT_EQ(5, vec[4]);
}

TEST(VectorTest, PopBack) {
    vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();

    ASSERT_EQ(4, vec.size());
    ASSERT_EQ(0, vec.empty());
    ASSERT_EQ(16, vec.capacity());
    ASSERT_EQ(1, vec.front());
    ASSERT_EQ(4, vec.back());
}

TEST(VectorTest, IncreaseCapacity) {
    vector<int> vec;
    
    for (int i = 0; i < 20; i++) {
        vec.push_back(i);
    }

    ASSERT_EQ(20, vec.size());
    ASSERT_EQ(0, vec.empty());
    ASSERT_EQ(32, vec.capacity());
    ASSERT_EQ(0, vec.front());
    ASSERT_EQ(19, vec.back());
}

TEST(VectorTest, DecreaseCapacity) {
    vector<int> vec(32);
    
    for (int i = 0; i < 25; i++) {
        vec.push_back(i);
    }

    for (int i = 0; i < 18; i++) {
        vec.pop_back();
    }

    ASSERT_EQ(7, vec.size());
    ASSERT_EQ(0, vec.empty());
    ASSERT_EQ(16, vec.capacity());
    ASSERT_EQ(0, vec.front());
    ASSERT_EQ(6, vec.back());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
