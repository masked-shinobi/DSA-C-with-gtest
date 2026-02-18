#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> arr){

    for(int i = 0; i < arr.size() - 1; i++){
        for (int j = 0; j < arr.size() - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int num : arr){
        cout << num << " " ;
    }
    cout << endl;
}

void selectionSort(vector<int> arr){

    for(int i = 0; i < arr.size() - 1; i++){
        int min = i;
        for (int j = i+1; j < arr.size(); j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for (int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

void merge(vector<int>& arr, int left, int mid, int right){
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right){
        if (arr[i] < arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    while(i <= mid) temp.push_back(arr[i++]);
    while(j <=right )  temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++){
        arr[left + k] = temp[k];
    }
}

void merge_sort(vector<int>& arr, int left, int right){
    if (left >= right){
        return ;
    }
    int mid = left + (right - left) / 2;
    // arr, left, mid, right

    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);


}

void insertion_sort(vector<int> arr){

    for(int i = 1 ; i < arr.size(); i++){
        int current = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }

    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

//quick sort -- choose pivot one function

int partition(vector<int>& arr, int left, int right){
    // last element be pivot
    int pivot = arr[right];
    // let i be left - 1
    int i = left - 1;
    // for j left -> pivot
    for (int j = left; j < right; j++){
        //if j < pivot
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // i++ and also swap arr[i] , arr[j]
    //break loop swap now arr[i+1] , arr[right]
    swap(arr[i+1], arr[right]);

    return i + 1;
}

void quick_sort(vector<int>& arr, int left, int right){
    if(left >= right) return;

    int pi = partition(arr, left, right);

    quick_sort(arr, left, pi -1);
    quick_sort(arr, pi + 1, right);
}


int main() {

    vector<int> arr;

    int k;

    while(cin >> k){
        arr.push_back(k);
    }
    vector<int> array = arr;

    bubbleSort(arr);
    selectionSort(arr);
    insertion_sort(arr);
    merge_sort(arr, 0, arr.size() - 1);
    for (int num : arr){
        cout << num << " ";
    }
    cout << endl;

    quick_sort(array, 0, array.size() - 1);
    for (int num : array){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}