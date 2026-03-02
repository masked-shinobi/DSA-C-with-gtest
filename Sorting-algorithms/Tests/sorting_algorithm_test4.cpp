#include <iostream>
#include <vector>

using namespace std;

void bubblesort(vector<int> arr){

    for(int i = 0; i < arr.size() - 1; i++){
        for(int j = 0; j < arr.size() - i -1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

    for(int num : arr){
        cout << num;
    }
    cout << endl;
}

void insertionsort(vector<int> arr){
    for(int i = 1; i < arr.size(); i++){
        int current = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }

    for(int num : arr){
        cout<< num;
    }
    cout << endl;
}

void selectionsort(vector<int> arr){

    for(int i = 0; i < arr.size() - 1; i++){
        int min = i;
        for (int j = i + 1; j < arr.size(); j++){
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

void merge(vector<int> arr, int left, int mid, int right){
    vector<int> temp;

    int i = left;
    int j = mid +1;

    while(arr[i] <= mid && arr[j] <= right){
        if(arr[i] < arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    while(arr[i] <= mid) temp.push_back(arr[i++]);
    while(arr[j <= right]) temp.push_back((arr[j++]));

    for(int k = 0; k < temp.size() - 1; k ++){
        arr[left + k] = temp[k];
    }
}

void mergesort(vector<int>& arr, int left, int right){
    if(left >= right){
        return;
    }

    int mid = left + (right - left) / 2;

    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int partition(vector<int> arr, int left, int right){
    int pivot = arr[right];
    int i = left + 1;

    for(int j = 0; j < right; j++){
        if(arr[i] > pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);

    return i + 1;
}

void quicksort(vector<int> arr, int left, int right){
    if(left >= right){
        return;
    }

    int pi = partition(arr, left, right);

    quicksort(arr, left, pi - 1);
    quicksort(arr, pi + 1, right);
}

int main() {

    return 0;
}