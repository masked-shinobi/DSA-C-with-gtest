#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    cout << "Vertices: " << N << endl;
    cout << "Edges: " << M << endl;

    cout << "Degrees: ";
    int maxDegree = 0;

    for (int i = 0; i < N; i++) {
        int degree = adj[i].size();
        cout << degree;

        if (i < N - 1)
            cout << " ";

        if (degree > maxDegree)
            maxDegree = degree;
    }

    cout << endl;
    cout << "Max Degree: " << maxDegree << endl;

    return 0;
}