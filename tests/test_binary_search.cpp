#include <gtest/gtest.h>
#include <vector>
#include "binary_search.h"

TEST(BinarySearchTest, FindsElement) {
std::vector<int> arr = {1,2,3,4,5};
EXPECT_EQ(binary_search(3, arr), 2);
}

TEST(BinarySearchTest, NotFound) {
std::vector<int> arr = {1,2,3,4,5};
EXPECT_EQ(binary_search(9, arr), -1);
}

TEST(BinarySearchTest, FirstElement) {
std::vector<int> arr = {10,20,30};
EXPECT_EQ(binary_search(10, arr), 0);
}

TEST(BinarySearchTest, LastElement) {
std::vector<int> arr = {10,20,30};
EXPECT_EQ(binary_search(30, arr), 2);
}
