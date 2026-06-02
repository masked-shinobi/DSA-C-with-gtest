#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> bubblesort(vector<int> arr){
    for(int i = 0; i < arr.size() - 1; i++){
        for(int j = 0; j < arr.size() - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    return arr;
}

vector<int> selectionsort(vector<int> arr){
    for(int i = 0; i < arr.size()-1; i++){
        int min = i;
        for(int j = i+1; j < arr.size(); j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    return arr;
}

vector<int> insertionsort(vector<int> arr){
    for(int i = 1; i < arr.size(); i++){
        int current = arr[i];
        int j = i - 1;
        while(j >= 0 && j < current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[i+1] = current;
    }
    return arr;
}


int main() {

    vector<int> arr;
    int k;
    while (cin >> k){
        arr.push_back(k);
    }
    // bubble sort call
    vector<int> bubble;
    bubble = bubblesort(arr);
    for (int num : bubble){
        cout << num << " ";
    }
    cout << endl;

    // selection sort
    vector<int> selection;
    selection = selectionsort(arr);
    for (int num : selection){
        cout << num << " ";
    }
    cout << endl;

    //insertion sort
    vector<int> insertion(arr);
    insertion = insertionsort(arr);
    for(int num : insertion){
        cout << num << " ";
    }
    cout << endl;
    // merge sort

    // quick sort


    return 0;
}
