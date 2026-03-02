//
// Created by baska on 28-02-2026.
//
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(){
    vector<int> arr;
    int k;

    while(cin >> k){
        arr.push_back(k);
    }

    for(int num : arr){
        cout << num;
    }


    return 0;
}

