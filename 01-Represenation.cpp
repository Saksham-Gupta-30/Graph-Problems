#include <bits/stdc++.h>
using namespace std;

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

    // DIRECTED GRAPH
    // vector<pair<int, int>> graph[n + 1];
    // for (int i = 0; i < m; i++) {
    //     int u, v, wt;
    //     cin >> u >> v >> wt;
    //     graph[u].push_back({v, wt});
    // }
    
    return 0;
}