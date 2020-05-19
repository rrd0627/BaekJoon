#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;

	cin >> N;

	int dp[100001] = { 0, };

	for (int i = 2; i <= N; i++)
	{
		dp[i] = 99999999;
	}
	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j*j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j*j] +1);
		}
	}



	cout << dp[N];


	return 0;
}