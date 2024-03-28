#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cnt;

int map[101][101];
bool visited[101][101] = { false, };
queue<pair<int, int>> q;

int step[101][101];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool InRange(int x, int y) {
	return (x > 0 && y > 0 && x <= n && y <= m);
}

void bfs() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny)) {
				if (map[nx][ny] == 1) {
					if (step[nx][ny] > step[x][y] + 1) {
						step[nx][ny] = step[x][y] + 1;
						q.push({ nx, ny });
					}
				}
				else if (map[nx][ny] == 0) {
					if (step[nx][ny] > step[x][y]) {
						step[nx][ny] = step[x][y];
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}


int main(void) {
	
	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			step[i][j] = 987654;
			map[i][j] = c - '0';
		}
	}

	q.push({ 1, 1 });
	step[1][1] = cnt;
	bfs();

	cout << step[n][m];
	return 0;
}
