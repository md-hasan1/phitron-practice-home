#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool visited[1005][1005];
int rows, cols;

vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

bool isValid(int x, int y) {
    if (x < 0 || x >= rows || y < 0 || y >= cols) return false;
    if (grid[x][y] == '-') return false;
    return true;
}

bool bfs(int startX, int startY, int endX, int endY) {
    queue<pair<int,int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        if (curX == endX && curY == endY) return true;

        for (int k = 0; k < 4; k++) {
            int nextX = curX + directions[k].first;
            int nextY = curY + directions[k].second;
            if (isValid(nextX, nextY) && !visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                q.push({nextX, nextY});
            }
        }
    }
    return false;
}

int main() {
    cin >> rows >> cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    int startX, startY, endX, endY;
    cin >> startX >> startY;
    cin >> endX >> endY;

    if (grid[startX][startY] == '-' || grid[endX][endY] == '-') {
        cout << "NO\n";
        return 0;
    }

    if (bfs(startX, startY, endX, endY)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
