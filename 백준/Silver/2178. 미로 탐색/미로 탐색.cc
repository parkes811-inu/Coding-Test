#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int dist[101][101];
bool visited[101][101] = { false, };
char map[101][101];
int n, m;
queue<pair<int, int>> q;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool InRange(int x, int y) {
    return(x > 0 && y > 0 && x <= n && y <= m);
}

void bfs(int x, int y) {

    q.push({ x, y });
    dist[x][y] = 1;
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (InRange(nx, ny) && visited[nx][ny] == false && map[nx][ny] == '1') {
                q.push({ nx, ny });
                visited[nx][ny] = true;
                dist[nx][ny] = dist[cx][cy] + 1;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    
    bfs(1, 1);

    cout << dist[n][m];
    return 0;
}
