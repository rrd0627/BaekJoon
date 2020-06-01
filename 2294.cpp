#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	int n, k;

	int dp[10001] = { 0, };
	int arr[10001] = { 0, };
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i <=k; i++)
	{
		dp[i] = 100001;
		for (int j = 0; j < n; j++)
		{			
			if (i == arr[j])
			{
				dp[i] = 1;
				break;
			}
			else
			{
				if (i - arr[j] < 0)continue;

				dp[i] = min(dp[i], dp[i - arr[j]] + 1);
			}
		}
	}

	if (dp[k] == 100001)
		cout << -1;
	else
	{
		cout << dp[k];
	}


	return 0;
}