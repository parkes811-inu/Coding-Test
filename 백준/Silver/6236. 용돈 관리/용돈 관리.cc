#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric> // accumulate 함수 사용

using namespace std;

int n, m;
vector<int> money;

bool canWithdraw(int K, int m) {
    int count = 1; // 인출 횟수
    int current_money = K; // 현재 가지고 있는 돈

    for (int i = 0; i < money.size(); i++) {
        if (current_money < money[i]) {
            count++;
            current_money = K;

            if (count > m) {
                return false; // 인출 횟수가 M을 초과하면 false 반환
            }

        }
        current_money -= money[i];
    }

    return true; // M번 이하로 인출해서 모든 지출을 커버할 수 있으면 true 반환
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;
        money.push_back(coin);
    }

    int start = *max_element(money.begin(), money.end());
    int end = accumulate(money.begin(), money.end(), 0);
    int answer = end;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (canWithdraw(mid, m)) {
            answer = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
