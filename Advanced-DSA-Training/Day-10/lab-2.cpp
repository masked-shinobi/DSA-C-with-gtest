#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, sr, sc, tr, tc;
    cin >> N >> sr >> sc >> tr >> tc;

    // dist[r][c] = steps to reach (r,c), -1 = not visited
    vector<vector<int>> dist(N, vector<int>(N, -1));

    // All 8 knight moves
    int dr[] = {-2, -2, -1, -1, +2, +2, +1, +1};
    int dc[] = {-1, +1, -2, +2, -1, +1, -2, +2};

    queue<pair<int,int>> q;
    q.push({sr, sc});
    dist[sr][sc] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Valid = inside board and not visited
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    cout << "Moves: " << dist[tr][tc] << endl;
    return 0;
}
