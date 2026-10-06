#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LCS{
public:
    // brute force
  int lcs(string a, string b){
    int m = a.length();
    int n = b.length();

    vector<vector<int>> table(m, vector<int>(n, 0));

    // bases cases
    for( int j = 0; j < n; j++){
        table[0][j] = 0;
    }

    for( int i = 0; i < m; i++){
        table[i][0] = 0;
    }

    for( int i = 0; i < m; i++){
        for( int j = 0; j < n; j++){
            if(a[i] == b[j]){
                table[i][j] = table[i-1][j-1];
            }
            else if(a[i] != b[i]){
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    return table[m][n];
  }
};