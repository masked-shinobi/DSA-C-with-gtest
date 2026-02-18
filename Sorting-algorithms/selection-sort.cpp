//
// Created by baska on 18-02-2026.
//
#include <iostream>
#include <vector>
#include "selection-sort.h"

using namespace std;

vector<int> selection_sort(vector<int> arr){
    for (int i = 0; i < arr.size() - 1; i++){
        int min = i;
        for(int j = i + 1; j < arr.size(); j++){
            // if compare less
            // swap them
            if(arr[j] < arr[min]){
                // now replace
                min = j;
            }

        }
        //swap elements
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    return arr;
}