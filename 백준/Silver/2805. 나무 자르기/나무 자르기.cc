#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int answer;
vector<int> tree;

long long check(int height) {
    long long sum = 0;

    for (int i = 0; i < tree.size(); i++) {
        if (tree[i] > height) {
            sum += tree[i] - height;
        }
    }

    return sum;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    tree.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    int start = 0;
    int end = *max_element(tree.begin(), tree.end());

    while (start <= end) {
        int mid = (start + end) / 2;

        long long result = check(mid);
        if (result >= m) {
            answer = mid; // 적어도 M 미터의 나무를 얻을 수 있는 절단기 높이 저장
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0; 
}
