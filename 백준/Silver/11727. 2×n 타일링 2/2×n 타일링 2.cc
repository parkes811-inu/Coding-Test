#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define max 1001
int d[max];
int n;

int main(void) 
{
	d[0] = 1;
	d[1] = 1;
	
	cin >> n;	

	for (int i = 2; i <= n; i++)
   {
		d[i] = d[i - 1] + d[i - 2] * 2;
		d[i] %= 10007;
	}
	cout << d[n];

	return 0;
}