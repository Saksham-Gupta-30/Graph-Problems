#include <bits/stdc++.h>
using namespace std;

vector<int> DFS(int V, vector<int> graph[]);
void dfsOnGraph(int node, vector<int> &vis, vector<int> graph[], vector<int> &dfs);

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

    vector<int> dfs;
    dfs = DFS(n, graph);
    for (auto it: dfs) cout << it << " ";

    return 0;
}

vector<int> DFS(int V, vector<int> graph[]) {
    vector<int> dfs;
    vector<int> vis(V + 1, 0);
    for (int i = 1; i <= V; i++) {
        if (!vis[i]) {
            dfsOnGraph(i, vis, graph, dfs);
        }
    }
    return dfs;
}

void dfsOnGraph(int node, vector<int> &vis, vector<int> graph[], vector<int> &dfs) {
    dfs.push_back(node);
    vis[node] = 1;
    for (auto it: graph[node]) {
        if (!vis[it]) {
            dfsOnGraph(it, vis, graph, dfs);
        }
    }
}