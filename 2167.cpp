#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N,M,K;
	cin >> N>>M;
	int arr[301][301] = { 0, };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> K;
	int dp[301][301] = { 0, };
	for (int i = 0; i < N; i++)
	{
		dp[i][0] = arr[i][0];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			dp[i][j] = dp[i][j - 1] + arr[i][j];
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dp[i][j] += dp[i - 1][j];
		}
	}
	int arrK[4] = { 0, };
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> arrK[j];
			arrK[j]--;
		}
		if (arrK[0] - 1 < 0 && arrK[1] - 1 < 0)
			cout << dp[arrK[2]][arrK[3]] << endl;
		else if(arrK[0] - 1 < 0)
		{
			cout << dp[arrK[2]][arrK[3]]  - dp[arrK[2]][arrK[1] - 1] << endl;
		}
		else if (arrK[1] - 1 < 0)
		{
			cout << dp[arrK[2]][arrK[3]] - dp[arrK[0] - 1][arrK[3]] << endl;
		}
		else
		{
			cout << dp[arrK[2]][arrK[3]] + dp[arrK[0]-1][arrK[1]-1] - dp[arrK[0] - 1][arrK[3]] - dp[arrK[2]][arrK[1] - 1] << endl;
		}
	}
	return 0;
}