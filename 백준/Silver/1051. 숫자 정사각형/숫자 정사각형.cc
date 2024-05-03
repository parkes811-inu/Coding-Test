#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> board(N, vector<char>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    int max_size = 1; // 최소 크기는 1 (한 칸)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char start = board[i][j];
            // 가능한 최대 크기에서 1까지 반복
            for (int size = min(N - i, M - j); size > 0; --size) {
                if (i + size - 1 < N && j + size - 1 < M &&
                    board[i + size - 1][j] == start &&
                    board[i][j + size - 1] == start &&
                    board[i + size - 1][j + size - 1] == start) {
                    max_size = max(max_size, size);
                    break; // 현재 시작점에서 가능한 최대 크기 찾으면 다음 시작점으로
                }
            }
        }
    }

    cout << max_size * max_size << endl;
    return 0;
}
