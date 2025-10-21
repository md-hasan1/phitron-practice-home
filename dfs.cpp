#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];

vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + d[i].first;
        cj = sj + d[i].second;
        cout<<ci<<" "<<cj<<endl;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int dot;
            cin >> grid[i][j];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //    for (int j = 0; j < m; j++)
    //    {

    //     cout<<grid[i][j];
    //    }
    //    cout<<endl;
    // }

    int si, sj;
    cin >> si >> sj;
    dfs(si, sj);

    return 0;
}