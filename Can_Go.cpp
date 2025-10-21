#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int si, sj, di, dj;
int flag = 0;
int n, m;
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
};
void dfs(int ai, int aj)
{
    vis[ai][aj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        // cout<<grid[si][sj]<<endl;
        ci = ai + d[i].first;
        cj = aj + d[i].second;
        // cout<<ci<<cj<< grid[ci][cj]<<endl;
           if (grid[ci][cj] == grid[di][dj])
        {
            flag = 1;
           
        }
        else if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
        {
        
            dfs(ci, cj);
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char val;
            cin >> val;
            grid[i][j] = val;
            if (val == 'A')
            {
                si = i;
                sj = j;
            }
            else if (val == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {

    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }
dfs(si,sj);
   if(flag){
    cout<<"YES";
   }else{
    cout<<"NO";
   }

    return 0;
}