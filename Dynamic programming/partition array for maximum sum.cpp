#include <iostream>
#include <vector>

using namespace std;

class DP {
public:
    int knapsack( vector<int> nums){
        int totalSum = 0;
        for( int num : nums){
            totalSum += num;
        }
        if (totalSum % 2 != 0){
            return false;
        }
        int target = totalSum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for ( int num : nums){
            for( int s = target - num; s >= 0; s--){
                if(dp[s]){
                    dp[s + num] = true;
                }
            }
        }
        return dp[target];
    }
};