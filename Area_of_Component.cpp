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

int bfs(int startX, int startY) {
    queue<pair<int,int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int size = 1; 

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (auto [dx, dy] : directions) {
            int nextX = curX + dx;
            int nextY = curY + dy;
            if (isValid(nextX, nextY) && !visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                q.push({nextX, nextY});
                size++;
            }
        }
    }
    return size;
}

int main() {
    cin >> rows >> cols;
    vector<int> components;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> grid[i][j];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                components.push_back(bfs(i, j));
            }
        }
    }

    if (components.empty()) {
        cout << -1 << "\n";
    } else {
        sort(components.begin(), components.end());
        cout << components[0] << "\n";   }

    return 0;
}
