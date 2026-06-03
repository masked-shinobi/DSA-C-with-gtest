#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    int left = 0;
    int sum = 0;
    int shortestwindow = 999;
    vector<int> arr;
    //input
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int k;
    cin >> k;
    //sliding window
    for(int i = 0; i < n; i++){
        sum+=arr[i];
        while(sum >= k){
            int currentwindow = i - left + 1;
            shortestwindow = min(shortestwindow, currentwindow);

            sum-=arr[left];
            left++;
        }
    }
    cout << shortestwindow;
    return 0;
}
