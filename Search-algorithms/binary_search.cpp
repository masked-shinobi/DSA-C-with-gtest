////
//// Created by baska on 15-02-2026.
////
#include "binary_search.h"
#include <vector>

using namespace std;
// call function
int binary_search(int target, const vector<int>& arr){

    int low, high;
    low = 0;
    high = arr.size() - 1;

    while (low <= high){
        int mid = low + ( high - low )/ 2;

        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            low  = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return -1;
}
//
//int main() {
//    // input vector array
//    vector<int> arr;
//    int k;
//
//    while (cin >> k){
//        arr.push_back(k);
//    }
//
//    // call function
//    int answer = binary_search(3, arr);
//    // return
//    cout << "The element is found in the position :" << answer << endl;
//
//    return 0;
//}