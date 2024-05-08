#include <iostream>
#include <algorithm>
using namespace std;

int n, t;
int dp[12];

int main(void) {

	cin >> t;

	dp[1] = 1; // 1
	dp[2] = 2; // 1 + 1, 2
	dp[3] = 4; // 1 + 1 + 1, 1 + 2, 2 + 1, 3 

	for (int i = 4; i <= 11; i++) {
		// dp 배열을 이용해 미리 개수를 구한다.
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0; 
}