#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int a, b;

	int dp[33][33];

	for (int i = 1; i <= 31; i++)
	{
		dp[i][1] = i;
		dp[i][i] = 1;
	}

	for (int i = 2; i <= 31; i++)
	{
		for (int j = 2; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout << dp[b][a] << endl;
	}
	return 0;
}