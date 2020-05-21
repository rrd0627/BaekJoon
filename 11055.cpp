#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;

	cin >> N;

	int arr[1001];
	int dp[1001][2] = { 0, };

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	dp[0][0] = arr[0];
	dp[0][1] = arr[0];

	int maxtemp = 0;

	for (int i = 1; i < N; i++)
	{
		maxtemp = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > dp[j][1])
			{
				if (maxtemp < dp[j][0] + arr[i])
					maxtemp = dp[j][0] + arr[i];

				dp[i][1] = arr[i];
			}
			else
			{
				if (maxtemp < arr[i])
				{
					maxtemp = arr[i];
					dp[i][1] = arr[i];
				}
					
			}
		}
		dp[i][0] = maxtemp;
	}

	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		ret = max(ret, dp[i][0]);
	}

	cout << ret << endl;


	return 0;
}