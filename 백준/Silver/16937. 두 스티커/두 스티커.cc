#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h, w, n, r, c;

vector<pair<int, int>> sticker;
int answer;


vector<pair<int, int>>rotate(pair<int, int> sticker) {
	
	vector<pair<int, int>> rotation;

	rotation.push_back({ sticker.first, sticker.second });
	rotation.push_back({ sticker.second, sticker.first });

	return rotation;
}

int getMaxArea() {
	
	int maxArea = 0;

	for (int i = 0; i < sticker.size(); i++) {
		for (int j = i + 1; j < sticker.size(); j++) {
			
			vector<pair<int, int>> first = rotate(sticker[i]);
			vector<pair<int, int>> second = rotate(sticker[j]);

			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					// 가로 방향으로 두 스티커를 배치할 수 있는 경우
					if (first[i].first + second[j].first <= w && max(first[i].second, second[j].second) <= h) {
						maxArea = max(maxArea, first[i].first * first[i].second + second[j].first * second[j].second);
					}
					// 세로 방향으로 두 스티커를 배치할 수 있는 경우
					if (max(first[i].first, second[j].first) <= w && first[i].second + second[j].second <= h) {
						maxArea = max(maxArea, first[i].first * first[i].second + second[j].first * second[j].second);
					}
				}
			}
		}
	}

	return maxArea;
}


int main(void) {
	
	cin >> h >> w;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> r >> c;
		sticker.push_back({ r, c });
	}

	cout << getMaxArea();

	return 0;
}
