#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid);
int numIslands(vector<vector<char>> &grid);

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid
    {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << numIslands(grid) << endl;

    return 0;
}

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty()) {
        row = q.front().first;
        col = q.front().second;
        q.pop();

        for (int delrow = -1; delrow <= 1; delrow++) {
            for (int delcol = -1; delcol <= 1; delcol++) {
                if (abs(delcol) == abs(delrow))
                    continue;
                int nrow = row + delrow;
                int ncol = col + delcol;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '1') {
                count++;
                bfs(i, j, vis, grid);
            }
        }
    }
    return count;
}