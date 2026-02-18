#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    // need a temporary variable to store the result
    vector<int> temp;
    // create two pointer i j - one for left half and one for the right half
    int i = left;
    int j = mid + 1;
    // now compare the elements from both halves and store the smallest in the temp
    while(i <= mid && j <=right){
        //track both i and j by ++
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    // note :: keep the temp always sorted
    // after the main there may be left over elements ih the both halves so handle it
    while(i <= mid) temp.push_back(arr[i++]);
    while(j <= right) temp.push_back(arr[j++]);
    // now copy back to original array from temp
    for(int k = 0; k < temp.size(); k++){
        arr[left + k] = temp[k];
    }
}
void merge_sort(vector<int>& arr, int left, int right){
    // divide logic for merge sort
    // base case : if one or no element then its already sorted
    if (left >= right){
        return;
    }
    // find mid point
    int mid = left + (right - left) / 2;

    // arr, left, mid, right - a, b, c, d
    // find left sorted
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
    // find right sorted
    // merge two sorted array
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    // call merge sort
    merge_sort(arr, 0, arr.size() - 1);

    return 0;
}