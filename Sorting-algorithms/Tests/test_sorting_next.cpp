#include <iostream>
#include <vector>

using namespace std;

void bubblesort(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size() - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

    for(int num : arr){
        cout << num << " ";
    }
}

void selectionsort(vector<int> arr){
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }

    for(int num : arr){
        cout << num << " ";
    }
}

void insertionsort(vector<int> arr){
    int n = arr.size();

    for(int i = 1; i < n; i++){
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
}



int main() {

    vector<int> arr;
    int k = 6;

    for(int i = 0; i < k; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    bubblesort(arr);
    selectionsort(arr);
    insertionsort(arr);

    return 0;
}