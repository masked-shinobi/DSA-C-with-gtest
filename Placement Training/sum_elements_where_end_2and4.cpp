#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> arr;
    int k;
    int count = 0;                        // flag variable

    while(cin >> k){
        arr.push_back(k);
    }

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] % 2 == 0){             // catch even number
                                         // catching unit digit
            int n = arr[i];              // declaring n temp
            n = abs(n % 10);          // dividing till we get the unit digit
            if(n == 2 || n == 4){
                count = count + arr[i];
            }
        }
    }

    cout << count << " ";

    return 0;
}

