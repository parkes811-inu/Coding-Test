#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int n; // 탑의 수
stack<pair<int, int>> st; //높이,번호

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	st.push({ 100000001,0 });
	cin >> n;
	for (int i = 1; i <= n; i++) { // 높이는 1부터 시작
		int height;
		cin >> height;
		while (st.top().first < height) {
			st.pop();
		}
		cout << st.top().second << ' ';
		st.push({ height,i });
	}

	return 0;
}