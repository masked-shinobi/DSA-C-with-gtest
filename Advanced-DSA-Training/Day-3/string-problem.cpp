#include <iostream>
#include <vector>

using namespace std;

int main() {

    //declaration
    string big;
    string small;
    //input
    cin >> big;
    cin >> small;

    //algorithm
    // keep left and right pointer
    // move right when both letter are found
    int smallpointer = 0;
    bool stringpresence = false;
    for(int i = 0; i < big.size(); i++){
        if(big[i] == small[smallpointer]){
            smallpointer++;
        }
        if(smallpointer == small.size()){
            stringpresence = true;
        }
    }

    cout << stringpresence;
    return 0;
}