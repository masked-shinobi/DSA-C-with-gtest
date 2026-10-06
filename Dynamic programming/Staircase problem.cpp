#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
    // staircase problem
class Staircaseproblem{
public:

    // basic recursion
    int staircase(int n){
        if(n == 1) return 1;
        if(n == 2) return 2;
        // recursion step
        return staircase(n-1) + staircase(n-2);
    }

    unordered_map<int, int> mp;

    //  memoization
    int stairmemo(int n){
        if(mp.find(n) != mp.end()){
            return mp[n];
        }

        if( n == 1 ) return 1;
        if( n == 2 ) return 2;
        // recursion
        int result = stairmemo(n-1) + stairmemo(n-2);
        mp[n] = result;
        return result;
    }

    // tabulation
    vector<int> ways;
    int tabulatestairs(int n){
        ways.resize(n);
        ways[1] = 1;
        ways[2] = 2;
        for( int i = 3; i < n; i++){
            ways[i] = ways[i-1] + ways[i-2];
        }
        // as we know the last value always contains the answer
        return ways[n];
    }
};

