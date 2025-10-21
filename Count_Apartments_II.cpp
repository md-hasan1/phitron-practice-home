#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int n, m;
vector<int> v;

vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int dfs(int ai, int aj) {
    vis[ai][aj] = true;
    int cnt = 1;
    for (int k = 0; k < 4; k++) {
        int ci = ai + d[k].first;
        int cj = aj + d[k].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#') {
            cnt += dfs(ci, cj); 
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;

  
    if (n == 0 || m == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j];
        }
    }

    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] != '#') {
                int roomSize = dfs(i, j);
                v.push_back(roomSize);
            }
        }
    }

   
    if (v.empty()) {
        cout << 0;
        return 0;
    }

    sort(v.begin(), v.end());
  for(auto it:v){
    cout<<it<< " ";
  }
    cout << endl;

    return 0;
}
