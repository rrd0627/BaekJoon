#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>	

using namespace std;
int n;

int arr[1001] = { 0, };
int dp[1001] = { 0, };

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) //지금것
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++) //그전것
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		ret = max(ret, dp[i]);
	}

	cout << ret;


	return 0;
}