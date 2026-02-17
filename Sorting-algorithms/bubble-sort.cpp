//
// Created by baska on 17-02-2026.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "bubble-sort.h"

using namespace std;

vector<int> bubble_sort(vector<int> arr){
    int n = arr.size() ;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
//                int temp = arr[j+1];
//                arr[j+1] = arr[j];
//                arr[j] = temp;
                  swap(arr[j], arr[j+1]);
            }
//            cout<< arr[j];
        }
//        cout << endl;
    }
    return arr;
}

//
//int main(){
//    vector<int> arr = {8,5,5,9,2,7};
//    vector<int> ans = bubble_sort(arr);
//
//
//    for(int i = 0; i < ans.size(); i++){
//        cout << ans[i] <<endl;
//    }
//    return 0;
//}