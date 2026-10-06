#include <iostream>
#include <vector>

using namespace std;

class palindromesubstring{
public:
    vector<vector<int>> dp;
    bool isPalindrome(string s, int i , int j){
        if( i >= j) return true;
// memoisation ---------------------------------------
        if(dp[i][j] != -1){
            return dp[i][j];
        }
// ---------------------------------------------------
        if(s[i] != s[j]){
            return dp[i][j] = false;
        }

        return dp[i][j] = isPalindrome(s, i+1, j-1);
    }

    int countSubstring(string s){
        int n = s.length();

        dp = vector<vector<int>>(n, vector<int>(n, -1));

        int count = 0;

        for( int i = 0; i < n; i++){
            for( int j = 0; j < n; j++){
                if(isPalindrome(s, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};