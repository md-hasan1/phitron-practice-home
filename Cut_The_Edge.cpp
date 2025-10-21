#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> depth;
vector<pair<int,int>> cuts;
vector<int> parent;
vector<bool> visited;

void dfs(int node, int par, int d) {
    depth[node] = d;
    parent[node] = par;
    visited[node] = true;
    for (int child : adj[node]) {
        if (child != par && !visited[child]) {
            dfs(child, node, d + 1);
        }
    }
}

void dfsUpdate(int node, int par, int d) {
    depth[node] = d;
    for (int child : adj[node]) {
        if (child != par) {
            dfsUpdate(child, node, d + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    adj.resize(n + 1);
    depth.resize(n + 1, -1);
    parent.resize(n + 1, -1);
    visited.resize(n + 1, false);

    vector<tuple<int,int,int>> edges;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v, i});
    }

    int q;
    cin >> q;
    cuts.resize(q);

    set<pair<int,int>> cutEdges;

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cuts[i] = {u, v};
        if (u > v) swap(u, v);
        cutEdges.insert({u, v});
    }

    // Remove all cut edges
    for (auto &[u, v, idx] : edges) {
        int a = u, b = v;
        if (a > b) swap(a, b);
        if (cutEdges.count({a, b})) {
            adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
            adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
        }
    }

    // DFS for all components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, 0, 0);
        }
    }

    // Process cuts in reverse order
    reverse(cuts.begin(), cuts.end());

    for (auto &[u, v] : cuts) {
        adj[u].push_back(v);
        adj[v].push_back(u);

        // Decide which subtree to update
        if (depth[u] > depth[v]) {
            dfsUpdate(u, v, depth[v] + 1);
        } else {
            dfsUpdate(v, u, depth[u] + 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << depth[i] * 2 << " ";
    }
}
