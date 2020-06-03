#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	int n;

	int dp[31] = { 1, 0 , 3 };

	cin >> n;
	for (int i = 4; i <= n; i+=2)
	{
		dp[i] = dp[i - 2] * 3;

		for (int j = 4; j <= i; j+=2)
		{
			dp[i] += dp[i - j] * 2;
		}
	}
	cout << dp[n];

	return 0;
}