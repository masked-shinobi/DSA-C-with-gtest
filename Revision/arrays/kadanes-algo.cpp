#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int currentsum = 0;
    int maxsum = 0;
    for(int i = 0; i < arr.size();i++){
        currentsum += arr[i];
        maxsum = max(currentsum, maxsum);
        if(currentsum < 0){
            currentsum = 0;
        }
    }
    return 0;
}