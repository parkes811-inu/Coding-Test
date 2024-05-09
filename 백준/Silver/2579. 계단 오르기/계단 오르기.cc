#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> stair(n + 1, 0);  // 계단 점수
    vector<int> dp(n + 1, 0);     // 최대 점수 저장

    for (int i = 1; i <= n; ++i) {
        cin >> stair[i];
    }

    // 초기화
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];


    // 점화식
    for (int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
    }

    cout << dp[n];
    return 0;
}
