//
// Created by baska on 17-02-2026.
//
#include <gtest/gtest.h>
#include "linear_search.h"
#include <vector>

TEST(LinearSearchTest, FindsElement){
    std::vector<int> arr = {5,2,4,9,8,6};
    EXPECT_EQ(linear_search(8, arr), 4);
}

TEST(LinearSearchTest, NotFound){
    std::vector<int> arr = {5, 2,6,9,7,58,6,2,4};
    EXPECT_EQ(linear_search(8, arr), -1);
}

TEST(LinearSearchTest, FirstElement){
    std::vector<int> arr = {6,8,9,7,5,1,2};
    EXPECT_EQ(linear_search(6, arr), 0);
}