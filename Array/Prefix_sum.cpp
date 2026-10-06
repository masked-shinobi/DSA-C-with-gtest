#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // Base case: sum = 0 occurs once

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            if (prefixCount.count(prefixSum - k)) {
                count += prefixCount[prefixSum - k];
            }

            // Record this prefix sum
            prefixCount[prefixSum]++;
        }

        return count;
    }
};