#include <iostream>
#include <vector>

using namespace std;

int n;
int a, b, c;

int main(void) {
	
	int n;
	int answer = -9999;

	cin >> n;
	
	for (int i = 0; i < n; i++) { 
		
		cin >> a >> b >> c; 

		// 같은 눈이 3개가 나온 경우
		if (a == b && b == c) {
			// 10,000원 + 같은눈 * 1000원
			if (10000 + a * 1000 > answer) {
				answer = 10000 + a * 1000;
			}
		}
		// 같은 눈이 2개가 나온 경우
		else if (a == b || b == c || a == c) {
			// 1000원 + 같은눈 * 100원
			if (a == b || a == c) {
				if (1000 + a * 100 > answer) {
					answer = 1000 + a * 100;
				}
			}
			else if (b == c) {
				if (1000 + b * 100 > answer) {
					answer = 1000 + b * 100;
				}
			}
		}
		// 모두 다른 눈이 나온 경우
		else if (a != b && b != c && a != c) {
			// a, b, c 중 가장 큰 눈 * 100
			int big = max(max(a, b), c);
			if (big * 100 > answer) {
				answer = big * 100;
			}
		}
	}

	cout << answer;


	return 0;
}