#include <iostream>
#include <vector>

using namespace std;

int n;
int score[101];

int main(void) {
	
	int n;
	int answer = 0;
	int check = 1;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		

		cin >> score[i];

		if (score[i] == 1) {
			answer = answer + check++;
		}
		if (score[i] == 0) {
			check = 1;
		}
	}
	cout << answer;

	return 0;
}