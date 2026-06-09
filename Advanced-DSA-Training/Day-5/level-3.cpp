#include <deque>
#include <iostream>

using namespace std;

int palindromecheck(deque<char> dq, int& mismatchpairs){
    while (dq.size() > 1){
        if(dq.front() != dq.back()){
            mismatchpairs++;
        }
        dq.pop_back();
        dq.pop_front();
    }
    return mismatchpairs;
}

int main() {
    string s;
    cin >> s;
    deque<char> dq;

    for(char c : s){
        dq.push_back(c);
    }
    bool ispalindrome = false;
    int mismatchpairs = 0;
    palindromecheck(dq, mismatchpairs);

    if(mismatchpairs == 0){
        ispalindrome = true;
    }

    cout << "Palindrome:" << ispalindrome << endl;
    cout << "Mismatched Pairs: " << mismatchpairs;

    return 0;
}