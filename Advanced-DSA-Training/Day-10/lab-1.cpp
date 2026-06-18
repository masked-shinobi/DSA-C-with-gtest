#include <bits/stdc++.h>
using namespace std;

int main() {
    int LIMIT, S, T;
    cin >> LIMIT >> S >> T;

    // dist[i] = steps to reach i, -1 = not visited
    vector<int> dist(LIMIT + 1, -1);

    queue<int> q;
    q.push(S);
    dist[S] = 0;  // start = 0 steps

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        // Try all 3 moves
        vector<int> nexts = {x + 1, x - 1, x * 2};

        for (int nx : nexts) {
            // Valid = inside [0, LIMIT] and not visited yet
            if (nx >= 0 && nx <= LIMIT && dist[nx] == -1) {
                dist[nx] = dist[x] + 1;
                q.push(nx);
            }
        }
    }

    if (dist[T] == -1) {
        cout << "Steps: -1" << endl;
        cout << "Reachable: No" << endl;
    } else {
        cout << "Steps: " << dist[T] << endl;
        cout << "Reachable: Yes" << endl;
    }

    return 0;
}
