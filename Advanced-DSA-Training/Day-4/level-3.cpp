#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void dequewindow(vector<int>& arr, int k){
    // logic building
    int length = arr.size();
    deque<int> dq;
// deque stores only indexes so make it clearly
    for (int i = 0; i < length; i++){
        // remove unwanted indices
        while(!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        // outside window remove it
        if(!dq.empty() && dq.front() <=i-k){
            dq.pop_front();
        }
        // add the current element
        dq.push_back(i);
        //valid window exists
        if(i >= k-1){
            cout << arr[dq.front()]<< " ";
        }
    }
}

int main() {
    // input
    vector<int> arr;
    int n;
    cin >> n;

    int k;
    cin >> k;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    dequewindow( arr, k);

    return 0;
}
