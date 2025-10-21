#include <bits/stdc++.h>
using namespace std;

int rows, cols;
bool visited[1005][1005];
vector<pair<int,int>> moves = {{2,-1},{2,1},{1,-2},{1,2},{-1,-2},{-1,2},{-2,-1},{-2,1}};

int bfs(int startX, int startY, int endX, int endY) {
    memset(visited, false, sizeof(visited));
    queue<pair<int,int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    int steps = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [curX, curY] = q.front(); 
            q.pop();

            if (curX == endX && curY == endY) return steps;

            for (auto [dx, dy] : moves) {
                int nextX = curX + dx;
                int nextY = curY + dy;
                if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    q.push({nextX, nextY});
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> rows >> cols;
        int startX, startY, endX, endY;
        cin >> startX >> startY;
        cin >> endX >> endY;
        cout << bfs(startX, startY, endX, endY) << endl;
    }
}
