#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class mincosestaircase{
public:

    // tabulation
    int minstair(vector<int> costs){
        int n = costs.size();
        vector<int> mincost(n);

        mincost[0] = costs[0];
        mincost[1] = costs[1];

        for( int i = 2; i < n; i++){
            mincost[i] = min(costs[i-1], costs[i-2]) + costs[i];
        }
        return min(mincost[n-1], mincost[n-2]);
    }

    // optimised tabulation
    int minstair(vector<int> costs){
        int n = costs.size();
        vector<int> mincost(n);
        int prev1 = costs[1];
        int prev2 = costs[0];

        for( int i = 2; i < n; i++){
            mincost[i] = min(prev2, prev1) + costs[i];
            prev2 = prev1;
            prev1 = mincost[i];
        }
        return min(prev1 , prev2);
    }
};