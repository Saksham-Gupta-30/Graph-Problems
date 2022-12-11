#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int V, vector<int> graph[]);

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

    vector<int> bfs;
    bfs = BFS(n, graph);
    for (auto it: bfs) cout << it << " ";

    return 0;
}

vector<int> BFS(int V, vector<int> graph[]) {
    vector<int> bfs;
    vector<int> vis(V + 1, 0);

    for (int i = 1; i <= V; i++) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto it: graph[node]) {
                    if (!vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }

    return bfs;
}