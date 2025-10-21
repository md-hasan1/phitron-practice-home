#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool visited[1005][1005];
pair<int,int> parent[1005][1005];
int rows, cols;

vector<pair<int,int>> directions = {{0,1},{0,-1},{-1,0},{1,0}};

bool isValid(int x, int y) {
    if (x < 0 || x >= rows || y < 0 || y >= cols) return false;
    if (grid[x][y] == '#') return false;
    if (visited[x][y]) return false;
    return true;
}

pair<int,int> bfs(int startX, int startY) {
    queue<pair<int,int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    parent[startX][startY] = {-1, -1};

    while (!q.empty()) {
        auto [curX, curY] = q.front();
        q.pop();

        if (grid[curX][curY] == 'D') return {curX, curY};

        for (auto [dx, dy] : directions) {
            int nextX = curX + dx;
            int nextY = curY + dy;
            if (isValid(nextX, nextY)) {
                visited[nextX][nextY] = true;
                q.push({nextX, nextY});
                parent[nextX][nextY] = {curX, curY};
            }
        }
    }
    return {-1, -1};
}

int main() {
    cin >> rows >> cols;
    int startX, startY;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'R') {
                startX = i;
                startY = j;
            }
        }
    }

    pair<int,int> endPos = bfs(startX, startY);

    if (endPos.first != -1) {
        int curX = endPos.first, curY = endPos.second;
        while (parent[curX][curY].first != -1) {
            auto [px, py] = parent[curX][curY];
            if (grid[px][py] != 'R') grid[px][py] = 'X';
            curX = px;
            curY = py;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << grid[i][j];
        cout << "\n";
    }

    return 0;
}
