#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include <cstring>
using namespace std;

vector<int> graph[1001];
bool visit[1001];

void BFS(int start)
{
	queue<int>que;
	que.push(start);
	visit[start] = true;

	while (!que.empty())
	{
		int x = que.front();
		que.pop();

		printf("%d ", x);

		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];

			if (!visit[y])
			{
				que.push(y);
				visit[y] = true;
			}
		}
	}
}

void DFS(int v)
{
	if (visit[v] == true)
	{
		return;
	}

	visit[v] = true;
	printf("%d ", v);

	for (int i = 0; i < graph[v].size(); i++)
	{
		int y = graph[v][i];
		if (visit[y] == 0)
		{
			DFS(y);
		}
	}
}

int main(void)
{
	int n, m, start;

	scanf("%d %d %d", &n, &m, &start);

	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());
	DFS(start);
	memset(visit, false, sizeof(visit));
	printf("\n");
	BFS(start);
}