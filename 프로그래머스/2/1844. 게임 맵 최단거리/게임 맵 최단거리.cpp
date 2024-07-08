#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int m, n;

int bfs(vector<vector<int>> &maps) {
    queue<pair<int, pair<int, int>>> q; // 이동 거리와 현재 좌표를 저장
    q.push({1, {0, 0}});
    maps[0][0] = 0;

    while (!q.empty()) {
        int distance = q.front().first;
        int curX = q.front().second.first;
        int curY = q.front().second.second;
        q.pop();

        if (curX == m - 1 && curY == n - 1)
            return distance;

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dir[i][0];
            int nextY = curY + dir[i][1];

            if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && maps[nextY][nextX] == 1) {
                q.push({distance + 1, {nextX, nextY}});
                maps[nextY][nextX] = 0;
            }
        }
    }

    return -1;
}

int solution(vector<vector<int>> maps) {
    n = maps.size();
    m = maps[0].size();

    return bfs(maps);
}