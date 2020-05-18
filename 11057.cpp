#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;

	cin >> N;

	int dp[1001][10] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
			}
		}
	}

	int ret=0;

	for (int i = 0; i < 10; i++)
	{
		ret = (ret + dp[N][i]) % 10007;
	}

	cout << ret;


	return 0;
}