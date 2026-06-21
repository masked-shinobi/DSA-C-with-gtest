#include <iostream>
#include <vector>

using namespace std;

class Disjoinset{
public:
    int n;
    vector<int> par, rank;
    Disjoinset(int n){
        this->n = n;
        for(int i = 0; i < n; i++){
            par.push_back(i);
            rank.push_back(0;)
        }
    }

    void unionbyrank(int a, int b){
        int parA = find(a);
        int parB = find(b);
        if(parA == parB){
            return;
        }
        if(rank[parA] == rank[parB]){
            par[parB] == parA;
            rank[parA]++;
        }else if(rank[parA] > rank[parB]){
            par[parB] == parA;
        }else{
            par[parA] = parB;
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }
};



int main() {
    Disjoinset a(5);
    a.unionbyrank(2, 3);
    // function called
    // union (0,2)
    // find (2)
    return 0;
}