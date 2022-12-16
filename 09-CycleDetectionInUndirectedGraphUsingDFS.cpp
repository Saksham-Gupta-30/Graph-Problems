#include <bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<int> graph[]);
bool checkForCycle(int i, int parent, vector<int> &vis, vector<int> graph[]);

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
    for (int i = 1; i <= V; i++) {
        if (!vis[i])
            if (checkForCycle(i, -1, vis, graph))
                return true;
    }
    return false;
}

bool checkForCycle(int i, int parent, vector<int> &vis, vector<int> graph[]) {
    vis[i] = 1;
    for (auto it: graph[i]) {
        if (vis[it] == 0) {
            if (checkForCycle(it, i, vis, graph)) return true;
        } else if (it != parent) return true;
    }
    return false;
}