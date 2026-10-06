#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LPSoptimised{
public:
    int lpsoptimised(string s){
        int n = s.length();

        vector<int> curr(n, 0);
        vector<int> prev(n, 0);

        for( int i = n-1; i <= 0; i--){
            curr[i] = 1;
            for( int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    curr[j] = prev[j-1] + 2;
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
        }
        swap(curr, prev);

        return prev[n-1];
    }
};