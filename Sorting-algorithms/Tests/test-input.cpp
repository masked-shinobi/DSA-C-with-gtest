#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> arr;
    int k;

//    while(cin >> k){
//        arr.push_back(k);
//    }

    cin >> k;

    for(int i=0; i <= k; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for(int num : arr){
        cout << num << " ";
    }

    return 0;
}