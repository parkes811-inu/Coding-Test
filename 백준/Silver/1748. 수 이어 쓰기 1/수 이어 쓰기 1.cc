#include<iostream>
#include<string>

using namespace std;

int n;
int cnt;
int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;


	if (n < 10) {
		cout << n;
		return 0;
	}

	for (int i = 1; i <= n; i *= 10) {
		cnt += n - i + 1;
	}

	cout << cnt;
	return 0;
}