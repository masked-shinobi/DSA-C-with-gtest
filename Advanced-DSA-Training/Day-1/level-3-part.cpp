#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // input
    int n;
    cin >> n;

    vector<int> arr;
    for(int i = 0 ; i < n; i++){
        cin >> arr.push_back(i);
    }

    int z;
    cin >> z;

    //sliding window
    int left = 0;
    int sum = 0;
    int shortest = INT_MAX;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        while(sum >= z){
            int currentLength = i - left + 1;

            shortest = min(shortest, currentLength);

            sum -= arr[left];
            left++;
        }
    }



    return 0;
}