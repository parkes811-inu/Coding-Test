#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
queue<int> q;
vector<int> node[101];
bool visited[101] = { false, };
int dist[101];
int answer[101];

void BFS(int start) {
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		
		int cur = q.front();
		q.pop();

		for (int i = 0; i < node[cur].size(); i++) {
			int next = node[cur][i];

			if (!visited[next]) {
				dist[next] = dist[cur] + 1;
				visited[next] = true;
				q.push(next);
			}
		
		}
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		dist[i] = 0;
		visited[i] = false;
	}
}

int main(void) {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		node[x].push_back(y);
		node[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		BFS(i);

		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			sum = sum + dist[j];
		}
		answer[i] = sum;
		init();
	}

	int minimum = 987654321;
	int answerNode = 0;
	for (int i = 1; i <= n; i++) {
		if (minimum > answer[i]) {
			minimum = answer[i];
			answerNode = i;
		}
	}
	cout << answerNode;
	return 0;

}