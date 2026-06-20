#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int primMST(int v, vector<vector<pair<int, int>>> adj){
    vector<bool> inMST(v, false);
    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,0});
    int mstCost = 0;
    while(pq.size() > 0){
        auto p = pq.top();
        int wt = p.first;
        int u = p.second;
        pq.pop();
        if(!inMST[u]){
            inMST[u] = true;
            mstCost += wt;
            for(int i = 0; i < adj[u].size()){
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                pq.push({w, v});
            }
        }
    }
    return mstCost;
}

int main(){
    int v = 4;
    vector<vector<pair<int, int>>> adj(v);

    adj[0].push_back({1, 10});
    adj[0].push_back({1, 10});

    cout << "MST cost used to build" << primMST(v, adj);
    return 0;
}