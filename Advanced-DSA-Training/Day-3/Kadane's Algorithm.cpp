#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    vector<int> arr;
    int a;
    cin >> a;

    for(int i = 0; i < a; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // kadanes logic
    int currentsum = 0;
    int maxsum = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        currentsum += arr[i];
        maxsum = max(currentsum, maxsum);
        if(currentsum < 0){
            currentsum = 0;
        }
    }
    cout << maxsum;
    return 0;
}