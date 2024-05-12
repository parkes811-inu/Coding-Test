#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int t, n, m;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        long long answer = 1;
        for (int i = 1; i <= n; i++) {
		        // 조합의 수를 구하는 공식
            answer *= (m - i + 1);  // m에서 m-n까지의 수를 곱함
            answer /= i;  // i로 나눔
        }
        cout << answer << '\n';
    }

    return 0;
}
