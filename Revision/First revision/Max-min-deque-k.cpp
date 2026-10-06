#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

void maxdeque(vector<int> arr, vector<int>& maxcollector, int k){
    deque<int> dq;
    for(int i = 0; i < arr.size(); i++){
        // unwanted indices size lesser
        while(!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
        // elements outside window
        while(!dq.empty() && dq.front() <= i - k){
            dq.pop_front();
        }
        // add the current element
        dq.push_back(i);
        // if current window valid add to the collector
        if(i >= k -1){
            maxcollector.push_back(arr[dq.front()]);
        }
    }

}
void mindeque(vector<int> arr, vector<int>& mincollector, int k){
    deque<int> dq;
    for(int i = 0; i < arr.size(); i++){
        // min value
        while(!dq.empty() && dq.back() >= arr[i]){
            dq.pop_back();
        }
        // out of window
        while(!dq.empty() && dq.front() < i - k){
            dq.pop_front();
        }
        //add current element
        dq.push_back(i);
        //if valid window add up to the vector
        if(i >= k-1){
            mincollector.push_back(arr[dq.front()]);
        }
    }
}

int main() {
    // vector input taken
    vector<int> arr;
    int n;
    cin >>n;

    int k;
    cin >> k;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    //maximum
    vector<int> maxcollector;
    maxdeque(arr, maxcollector, k);
    cout << "Window Maxima:";
    for (int num : maxcollector){
        cout << num << " ";
    }
    cout << endl;
    //minimum
    vector<int> mincollector;
    mindeque(arr, mincollector, k);
    cout << "Window Minima:";
    for (int num : mincollector){
        cout << num << " ";
    }
    cout << endl;
    //max spread -- difference between the two indices
    int maxi = INT_MIN;
    for(int num : maxcollector){
        maxi = max(num, maxi);
    }
    int mini = INT_MAX;
    for(int num : mincollector){
        mini = min(num, mini);
    }
    cout << "Max Spread :" << maxi - mini;

    return 0;
}