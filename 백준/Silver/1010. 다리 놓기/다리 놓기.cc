#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
    int t, n, m;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        long long answer = 1;
        for (int i = 1; i <= n; ++i) {
            answer *= (m - i + 1);  // m에서 m-n까지의 수를 곱함
            answer /= i;  // i로 나눔
        }
        cout << answer << '\n';  // 각 결과 출력 후 줄바꿈
    }

    return 0;
}
