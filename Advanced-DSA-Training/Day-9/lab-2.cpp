#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int S;
    cin >> S;

    for (int i = 0; i < N; i++)
        sort(adj[i].begin(), adj[i].end());

    vector<int> dist(N, -1);
    vector<int> order;

    queue<int> q;

    dist[S] = 0;
    q.push(S);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        order.push_back(u);

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << "BFS Order: ";
    for (int x : order)
        cout << x << " ";

    cout << "\nDistances: ";
    for (int d : dist)
        cout << d << " ";
}