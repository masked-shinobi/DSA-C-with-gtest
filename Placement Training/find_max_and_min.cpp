#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int k;

    while(cin >> k){
        arr.push_back(k);
    }

    int max = 0;
    int min = 0;

    for(int i = 0; i < arr.size(); i++){
        if (arr[min] > arr[i]){
            min = i;
        }
        if ( arr[max] < arr[i]){
            max = i;
        }
    }

    cout << arr[max] << " is the maximum" << endl;
    cout << arr[min] << " is the minimum" << endl;

    return 0;
}