#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> arr){
    for(int i = 0; i < arr.size() - 1; i++){
        int min = i;
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
    for(int num : arr){
        cout << num ;
    }
    cout << endl;
}

void insertion_sort(vector<int> arr){
    for(int i = 1; arr.size(); i++){
        int current = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    for(int num : arr){
        cout << num;
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    int k ;
    while (cin >> k){
        arr.push_back(k);
    }

    selection_sort(arr);
    insertion_sort(arr);

    return 0;
}