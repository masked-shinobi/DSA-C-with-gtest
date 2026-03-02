#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> arr){
    for(int i = 0; i < arr.size() - 1; i++){
        int min = i;
        for(int j = i+1; j < arr.size() - i - 1; j++){
            if(arr[j] > arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void insertion_sort(vector<int> arr){
    for(int i = 1; i < arr.size(); i++){
        int current = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[i+1] = current;
    }
}

void merge_sort(vector<int> arr){

}