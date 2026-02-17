#include <gtest/gtest.h>
#include <vector>
#include "bubble-sort.h"

TEST(BubbleSortTest, SortedArray){
    std::vector<int> arr_un = {7,5,4,6,9};
    std::vector<int> arr_st = {4,5,6,7,9};
    EXPECT_EQ(bubble_sort(arr_un), arr_st);
}
