#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<string> grid(R);

    int startRow = -1;
    int startCol = -1;
    int endRow = -1;
    int endCol = -1;

    for(int i = 0; i < R; i++) {
        cin >> grid[i];

        for(int j = 0; j < C; j++) {
            if(grid[i][j] == 'S') {
                startRow = i;
                startCol = j;
            }
            else if(grid[i][j] == 'E') {
                endRow = i;
                endCol = j;
            }
        }
    }

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    vector<vector<int>> dist(R, vector<int>(C, -1));

    queue<pair<int,int>> q;

    q.push({startRow, startCol});
    visited[startRow][startCol] = true;
    dist[startRow][startCol] = 0;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if(newRow >= 0 && newRow < R &&
               newCol >= 0 && newCol < C &&
               grid[newRow][newCol] != '#' &&
               !visited[newRow][newCol]) {

                visited[newRow][newCol] = true;
                dist[newRow][newCol] = dist[row][col] + 1;

                q.push({newRow, newCol});
            }
        }
    }

    if(dist[endRow][endCol] == -1) {
        cout << "Steps: -1" << endl;
        cout << "Reachable: No";
    }
    else {
        cout << "Steps: " << dist[endRow][endCol] << endl;
        cout << "Reachable: Yes";
    }

    return 0;
}