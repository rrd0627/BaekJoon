#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>	

using namespace std;
int n;

int arr[101][101] = { 0, };
 
long long dp[101][101] = { 0, };

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j] == 0 || i==n-1 && j==n-1)
				continue;

			dp[i + arr[i][j]][j] += dp[i][j];
			dp[i][j + arr[i][j]] += dp[i][j];
		}
	}

	cout << dp[n - 1][n - 1];

	return 0;
}