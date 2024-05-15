#include <iostream>
#include <vector>

using namespace std;

int t;
vector<int> answer;

int main() {
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long start = 1, end = 2147483647;
        long long result = 0;

        while (start <= end) {
            long long mid = (start + end) / 2;
            long long sum = (mid * (mid + 1)) / 2; // 등차수열의 합

            if (sum <= n) {
                result = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        answer.push_back(result);
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
    return 0;
}
