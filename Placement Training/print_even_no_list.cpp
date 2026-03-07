#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int k;

    while(cin >> k){
        arr.push_back(k);
    }
    cout << "The total even numbers are : ";
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] % 2 == 0){
            cout << arr[i] << " ";
        }
    }
    return 0;
}