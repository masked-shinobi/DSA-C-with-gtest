#include <iostream>
#include <string.h>

using namespace std;

int main() {
    //declaration
    string big;
    string small;
    //input
    cin >> big;
    cin >> small;
    // windowsize
    int windowsize = small.size();

    bool match = false;
    //sliding window algo
    if(big.size() > windowsize){
        // get the valid window size

        for (int i = 0; i <= big.size() - small.size(); i++){
            bool currentwindow = true;
            for (int j = 0; j < small.size(); j++){
                if(big[i+j] != small[j]){
                    currentwindow = false;
                    break;
                }

            }
            if(currentwindow){
                match = true;
                break;
            }
        }

    }else{
        cout << "big window size is less than pattern window";
    }

    return 0;
}