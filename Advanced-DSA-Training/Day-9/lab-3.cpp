#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> order;

void dfs(int u) {
    visited[u] = true;
    order.push_back(u);

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    adj.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Sort neighbors for ascending DFS order
    for (int i = 0; i < N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    int components = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }

    cout << "DFS Order: ";
    for (int x : order) {
        cout << x << " ";
    }

    cout << endl;
    cout << "Components: " << components << endl;

    return 0;
}