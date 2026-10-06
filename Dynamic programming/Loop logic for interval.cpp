#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
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
    
    for(int i = 0; i < n; i++){
        for( int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
