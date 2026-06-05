#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Neighbours in ascending order
    for (int i = 0; i < N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> dist(N, -1);
    vector<int> parent(N, -1);

    queue<int> q;

    dist[0] = 0;
    q.push(0);

    int reachable = 0;

    // BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        reachable++;

        for (int neighbour : graph[node]) {
            if (dist[neighbour] == -1) {
                dist[neighbour] = dist[node] + 1;
                parent[neighbour] = node;
                q.push(neighbour);
            }
        }
    }

    // Find farthest node
    int maxHops = -1;
    int farthestNode = -1;

    for (int i = 0; i < N; i++) {
        if (dist[i] != -1) {
            if (dist[i] > maxHops) {
                maxHops = dist[i];
                farthestNode = i;
            }
            else if (dist[i] == maxHops && i < farthestNode) {
                farthestNode = i;
            }
        }
    }

    // Rebuild path using stack
    stack<int> st;

    int current = farthestNode;
    while (current != -1) {
        st.push(current);
        current = parent[current];
    }

    cout << "Reachable: " << reachable << endl;
    cout << "Max Hops: " << maxHops << endl;
    cout << "Farthest Node: " << farthestNode << endl;

    cout << "Path: ";

    while (!st.empty()) {
        cout << st.top();
        st.pop();

        if (!st.empty()) {
            cout << " -> ";
        }
    }

    return 0;
}