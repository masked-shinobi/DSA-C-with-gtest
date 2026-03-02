#include <iostream>
#include <vector>

using namespace std;
// --------------------------------------------------------
void bubble_sort(vector<int> arr){
    for (int i = 0; i < arr.size() - 1; i++){
        for(int j = 0; j < arr.size() - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

    for(int num : arr){
        cout << num;
    }
    cout<<endl;
}
// ---------------------------------------------------------
void selection_sort(vector<int> arr){
    for (int i = 0; i < arr.size(); i++){
        int min = i;
        for(int j = i + 1; j < arr.size(); j++){
            if ( arr[min] > arr[j]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }

    for(int num : arr){
        cout << num;
    }
    cout << endl;
}

void insertion_sort(vector<int> arr){

    for(int i = 1; i < arr.size(); i++){
        int currentValue = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > currentValue){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = currentValue;
    }

    for(int num : arr){
        cout << num;
    }
    cout << endl;
}

void merge(vector<int>& arr, int left, int mid, int right){
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    while(i <= mid) temp.push_back(arr[i++]);
    while(j <= right) temp.push_back(arr[j++]);

    for(int k =0 ; k < temp.size(); k++){
        arr[left + k] = temp[k];
    }
}

void merge_sort(vector<int>& arr, int left, int right){
    if( left >= right){
        return;
    }

    int mid = left + (right - left) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int partition(vector<int>& arr, int left, int right){
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right ; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);

    return i + 1;
}

void quick_sort(vector<int>& arr, int left, int right){
    if(left >= right){
        return;
    }
    int pi = partition(arr, left, right);

    quick_sort(arr, left, pi - 1);
    quick_sort(arr, pi + 1, right);
}

int main(){
    vector<int> arr;
    int k;

    while(cin >> k){
        arr.push_back(k);
    }
    // array copy
    vector<int> arra = arr;
    // function calling
    // ----------------------------------------------
    bubble_sort(arr);
    // ----------------------------------------------
    selection_sort(arr);
    // ----------------------------------------------
    insertion_sort(arr);
    //-----------------------------------------------
    merge_sort(arr, 0, arr.size() - 1);

    for(int num : arr){
        cout << num;
    }
    cout << endl;
    // -----------------------------------------------
    quick_sort(arra, 0, arra.size() - 1);
    for(int num : arra){
        cout << num;
    }
    cout << endl;
    // ------------------------------------------------
    return 0;
}
