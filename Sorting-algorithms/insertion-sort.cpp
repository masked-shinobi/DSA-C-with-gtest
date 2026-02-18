#include <iostream>
#include <vector>
#include "insertion-sort.h"

using namespace std;

vector<int> insertion_sort(vector<int> arr){
    // loop the completely i - to length of array  (note : the i should start from 2nd element as j should keep the track of the sorted array )
    // set current value as i
    // use a while loop till condition true move till the left position
    // condition : j greater than 0 and jth index value greater the current value
    // push it to the right
    // then jth next value to be our value -- current value

    for(int i = 1; i < arr.size(); i++){
        int current_value = arr[i];
        int j = i - 1;
        while( j >= 0 && arr[j] > current_value){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current_value;
    }
    return arr;
}
