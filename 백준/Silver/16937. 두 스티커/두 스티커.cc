#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Sticker {
    int width, height;
};

// 스티커를 회전시키는 함수
vector<pair<int, int>> getRotations(Sticker& sticker) {
    vector<pair<int, int>> rotations;
    // 원래 상태와 90도 회전 상태 추가
    rotations.push_back({ sticker.height, sticker.width });
    rotations.push_back({ sticker.width, sticker.height });
    return rotations;
}

// 모눈종이에 스티커 두 개를 붙일 수 있는 최대 넓이를 계산하는 함수
int getMaxArea(int H, int W, vector<Sticker>& stickers) {
    int maxArea = 0;

    // 모든 스티커 쌍에 대해 루프
    for (int i = 0; i < stickers.size(); i++) {
        for (int j = i + 1; j < stickers.size(); j++) {
            // 각 스티커에 대해 가능한 회전을 구함
            auto rotations1 = getRotations(stickers[i]);
            auto rotations2 = getRotations(stickers[j]);

            // 가능한 회전 조합에 대해 루프
            for (auto& r1 : rotations1) {
                for (auto& r2 : rotations2) {
                    // 각 회전 상태에서 두 스티커를 배치할 수 있는지 확인
                    if ((r1.first + r2.first <= H && max(r1.second, r2.second) <= W) ||
                        (r1.second + r2.second <= W && max(r1.first, r2.first) <= H)) {
                        maxArea = max(maxArea, r1.first * r1.second + r2.first * r2.second);
                    }
                }
            }
        }
    }

    return maxArea;
}

int main() {
    int H, W, N;
    cin >> H >> W;
    cin >> N;
    vector<Sticker> stickers(N);

    for (int i = 0; i < N; i++) {
        cin >> stickers[i].height >> stickers[i].width;
    }

    cout << getMaxArea(H, W, stickers) << endl;

    return 0;
}
