#include <iostream>
#include <vector>

using namespace std;

class PalindromeSubsequence{
public:
    int palindromesubsequence(string s){
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for( int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        for( int len = 2; len <= n; len++){
            for( int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                dp[i][j] = 3;
            }
        }
        return dp[0][n-1];
    }
};