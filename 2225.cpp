#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	long long dp[201][201] = { 0, };

	for (int i = 0; i <= n; i++)
	{
		dp[1][i] = 1;
	}
	
	for (int i = 2; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				dp[i][j] += dp[i - 1][l];
			}
			dp[i][j] %= 1000000000;
		}	
	}
	cout << dp[k][n];

	return 0;
}