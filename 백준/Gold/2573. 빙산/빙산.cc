#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int map[301][301];
bool visited[301][301];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool InRange(int x, int y) {
    return x >= 0 && y >= 0 && x < n&& y < m;
}

void DFS(int x, int y) {
    visited[x][y] = true;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (InRange(nx, ny) && !visited[nx][ny] && map[nx][ny] > 0) {
            DFS(nx, ny);
        }
    }
}

int countComponents() {
    int count = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && map[i][j] > 0) {
                DFS(i, j);
                count++;
            }
        }
    }
    return count;
}

void melt() {
    int temp[301][301] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] > 0) {
                int count = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (InRange(nx, ny) && map[nx][ny] == 0) {
                        count++;
                    }
                }
                temp[i][j] = max(0, map[i][j] - count);
            }
        }
    }
    memcpy(map, temp, sizeof(map));
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int years = 0;
    while (true) {
        if (countComponents() >= 2) {
            cout << years << endl;
            return 0;
        }
        melt();
        years++;
        if (countComponents() == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
}
