#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int dp[1001][1001];

int main()
{
	int n,k;
	
	cin >> n >> k;

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;
		}
	}

	cout << dp[n][k] % 10007;

	return 0;
}