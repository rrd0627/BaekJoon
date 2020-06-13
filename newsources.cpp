#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int dp[1001] = { 0, };
int arr[1001] = { 0, };
int main()
{
	int n;
	 
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int ret = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				dp[i] = max(dp[j] + 1, dp[i]);

			}
		}
		ret = max(ret, dp[i]);
	}

	cout << ret+1;


	return 0;
}