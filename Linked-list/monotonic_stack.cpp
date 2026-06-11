#include <vector>
using namespace std;
// monotonic stack brute force logic i wrote in exam check me whether i was right because i had issue there
vector<int> dailytemp(vector<int> arr){
    // to return the next highest temperature in the vector
    vector<int> temp;
    for(int j = 0; j < arr.size(); j++){
        bool added = false;   // <---- this is where the mistake was done
        for(int i = j; i < arr.size(); i++){

            if(arr[j] < arr[i] && added == false){
                temp.push_back(arr[i]);
                added = true;
            }
        }
    }
    return temp;
}