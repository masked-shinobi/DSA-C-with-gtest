//
// Created by baska on 17-02-2026.
//
#include <iostream>
#include <vector>
#include "linear_search.h"

using namespace std;

int linear_search(int target, const vector<int>& arr){
    for(int i = 0; i < arr.size() - 1; i++){
        if(arr[i] == target){
            return i;
            // can be returned 1 for boolean only
        }
    }

    return -1;
}