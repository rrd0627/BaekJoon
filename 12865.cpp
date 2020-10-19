#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int dp[101][100001] = { 0, };

int main()
{
	int N, K, W, V;

	cin >> N >> K;


	int arrW[100001];
	int arrV[1001];

	for (int i = 1; i <= N; i++)
	{
		cin >> arrW[i] >> arrV[i];
	}


	dp[0][0] = 0;	

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if(j-arrW[i]>=0)
				dp[i][j] = max(dp[i-1][j - arrW[i]] + arrV[i], dp[i - 1][j]);
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];


	return 0;
}