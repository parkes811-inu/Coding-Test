#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <deque>

using namespace std;

int n, k, l;
int map[101][101];
int Time = 0;

struct Snake {
    deque<pair<int, int>> body;
    int dir;
} snake;

int dx[4] = { 0, 1, 0, -1 }; // 동남서북
int dy[4] = { 1, 0, -1, 0 };

bool move() {
    int nx = snake.body.front().first + dx[snake.dir];
    int ny = snake.body.front().second + dy[snake.dir];

    // 벽 또는 자신의 몸과 충돌 검사
    if (nx < 1 || nx > n || ny < 1 || ny > n || map[nx][ny] == 2) {
        return false;
    }

    // 사과가 있는 경우
    if (map[nx][ny] == 1) {
        map[nx][ny] = 0; // 사과 먹기
    }
    else { // 사과가 없는 경우
        auto tail = snake.body.back();
        snake.body.pop_back();
        map[tail.first][tail.second] = 0; // 꼬리 지우기
    }

    // 머리 이동
    snake.body.push_front({ nx, ny });
    map[nx][ny] = 2; // 몸통 표시
    return true;
}

int main(void) {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1; // 사과 위치 1로 표시
    }

    cin >> l;
    queue<pair<int, char>> dirChanges;
    for (int i = 0; i < l; i++) {
        int x; char c;
        cin >> x >> c;
        dirChanges.push({ x, c });
    }

    // 뱀 초기화
    snake.body.push_back({ 1, 1 });
    map[1][1] = 2; // 뱀의 몸통 위치
    snake.dir = 0;

    while (true) {
        Time++;
        if (!move()) {
            cout << Time << '\n';
            break;
        }
        if (!dirChanges.empty() && Time == dirChanges.front().first) {
            char c = dirChanges.front().second;
            dirChanges.pop();
            if (c == 'L')
                snake.dir = (snake.dir + 3) % 4; // 왼쪽으로 90도 회전
            else
                snake.dir = (snake.dir + 1) % 4; // 오른쪽으로 90도 회전
        }
    }
    return 0;
}
