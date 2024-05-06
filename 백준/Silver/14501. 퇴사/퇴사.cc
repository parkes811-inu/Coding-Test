#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>

#define max 16

using namespace std;

int n, result;
int t[max], p[max];

void reservation(int day, int sum)
{
	if (n + 1 == day)
	{
		if (result < sum)
		{
			result = sum;
		}
		return;
	}

	if (day > n)
	{
		return;
	}

	reservation(day + 1, sum);
	reservation(day + t[day], sum + p[day]);
}

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}

	reservation(1, 0);
	cout << result;
	return 0;
}