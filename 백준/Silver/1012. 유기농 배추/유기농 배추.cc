#include<iostream>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std;

int n, m, c;
int map[51][51];
int check[51][51];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool DFS(int y, int x)
{
	if (check[y][x] == 1)
	{
		return false;
	}
	check[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n && map[next_y][next_x])
		{
			DFS(next_y, next_x);
		}
	}
	return true;
}

int main(void)
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d", &m, &n, &c);
		memset(check, 0, sizeof(check));
		memset(map, 0, sizeof(map));

		for (int i = 0; i < c; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}

		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 1 && check[i][j] == 0)
				{
					if (DFS(i, j) == 1)
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}

}
