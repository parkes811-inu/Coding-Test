#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

int w, h;
int map[51][51];
bool visited[51][51] = {false, };
int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[8] = { -1, 1, 0, 0, 1, -1, -1, 1 };
vector<int> answer;
int cnt;

bool InRange(int x, int y) {
	return (x >= 0 && y >= 0 && x < h && y < w);
}


void DFS(int x, int y) {
	
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
	
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && !visited[nx][ny] && map[nx][ny] == 1) {
			DFS(nx, ny);
		}
	}
	return;
}

void init() {
	cnt = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

int main(void) {
	
	while (1) {
		// 1. w, h 입력받기
		cin >> w >> h;
		
		// 2. 종료 조건
		// 입력의 마지막 줄에는 0이 두 개 주어진다.
		// 여태까지 추가된 정답들 출력 후 종료!
		if (w == 0 && h == 0) {
			for (int i = 0; i < answer.size(); i++) {
				cout << answer[i] << '\n';
			}
			return 0;
		}

		// 3. map에 땅, 바다 추가
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		// 4. 탐색 수행
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && map[i][j] == 1) {
					DFS(i, j);
					cnt++;
				}
			}
		}

		// 5. 초기화 및 개수 추가
		answer.push_back(cnt);
		init();
	}

	return 0;
}