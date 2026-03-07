#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr;
    int k;
    int flag = 0;
    while(cin >> k){
        arr.push_back(k);
    }

    for(int i = 0; i < arr.size(); i++){
        flag = flag + arr[i];
    }

    cout << "Total Sum" <<flag<< endl;
    return 0;
}


