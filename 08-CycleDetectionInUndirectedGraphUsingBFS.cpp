#include <bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<int> graph[]);
bool checkForCycle(int i, vector<int> graph[], vector<int> &vis);

int main() {
    int n, m;
    cin >> n >> m;

    // UNDIRECTED GRAPH
    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool ans = isCycle(n, graph);
    cout << boolalpha << ans;

    return 0;
}

bool isCycle(int V, vector<int> graph[]) {
    vector<int> vis(V + 1, 0);
    for (int i = 1; i <= V; i++)
        if (!vis[i]) 
            if (checkForCycle(i, graph, vis)) return true;

    return false;
}

bool checkForCycle(int i, vector<int> graph[], vector<int> &vis) {
    queue<pair<int, int>> q;

    vis[i] = 1;
    q.push({i, -1});
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it: graph[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push({it, node});
            }
            else if (it != parent)
                return true;
        }
    }
    return false;
}