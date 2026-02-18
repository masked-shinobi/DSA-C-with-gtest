#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include "selection-sort.h"

using namespace std;

TEST(SelectionSortTest, SortedArray){
    vector<int> arr_un = {5,98,4,2,412,6};
    vector<int> arr_st = {2,4,5,6,98,412};
    EXPECT_EQ(selection_sort(arr_un), arr_st);
}
