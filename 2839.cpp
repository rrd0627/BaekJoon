#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;

	cin >> N;

	int dp[5001] = { 999999,};

	for (int i = 0; i < 5001; i++)
	{
		dp[i] = 999999;
	}


	dp[3] = 1;
	dp[5] = 1;

	for (int i = 6; i <= N; i++)
	{
		if (dp[i - 3] == 999999 && dp[i - 5] == 999999)
			continue;
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);

	}

	if (dp[N] == 999999)
	{
		cout << -1;
	}
	else
	{

		cout << dp[N];
	}

	return 0;
}