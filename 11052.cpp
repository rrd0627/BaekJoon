#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int dp[1001]; //i 개를 구매하는 최대 값
	int arr[1001];
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int max_temp;

	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		max_temp = 0;
		for (int j = 0; j < i; j++)
		{
			if(max_temp < arr[j] + dp[i - j - 1])
				max_temp = arr[j] + dp[i - j - 1];
		}
		dp[i] = max_temp;
	}

	cout << dp[n];

	return 0;
}