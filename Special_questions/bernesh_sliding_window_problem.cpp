// longest substring problem

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {
    int maxlength = 0;
    unordered_map<char, int> hashmap;
    int left = 0;

    string arr;
    cin >> arr;

    int length = arr.size();

    for(int i = 0; i < length; i++){
        hashmap[arr[i]]++;

        while(hashmap[arr[i]] > 1){


            hashmap[arr[left]]--;
            left++;
        }
        int current = i - left + 1;
        maxlength = max(current, maxlength);
    }
    cout << maxlength;
    return 0;
}
