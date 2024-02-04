#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, vector<vector<int>>& graph, vector<vector<bool>>& visited) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < graph.size() && ny >= 0 && ny < graph[0].size()) {
            if (graph[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny, graph, visited);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> graph(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            graph[y][x] = 1;
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j, graph, visited);
                    result++;
                }
            }
        }
        
        cout << result << '\n';
    }
    return 0;
}
