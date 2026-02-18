#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "insertion-sort.h"

using namespace std;

TEST(InsertionSortTest, SortedArray){
    vector<int> arr_un = {5,6,7,9,5,1};
    vector<int> arr_st = {1,5,5,6,7,9};
    EXPECT_EQ(insertion_sort(arr_un), arr_st);
}