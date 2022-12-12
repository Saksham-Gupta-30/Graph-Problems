#include <bits/stdc++.h>
using namespace std;

int findCircleNum(vector<vector<int>>& adj);
void dfs(int node, vector<int>& vis, vector<int> g[]);

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            adj[i][j] = x;
        }
    }

    int ans = findCircleNum(adj);

    cout << ans << endl;

    return 0;
}

void dfs(int node, vector<int>& vis, vector<int> g[]) {
    vis[node] = 1;
    for (auto it: g[node]) {
        if (!vis[it]) dfs(it, vis, g);
    }
}

int findCircleNum(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> g[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1 && i != j) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int count = 0;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            count++;
            dfs(i, vis, g);
        }
    }
    return count;
}