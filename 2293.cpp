#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,k;

	int arr[101] = { 0, };
	int dp[10001] = { 0, }; // j 값 만든는 경우의수  아래의것을 다시 활용하기
	//int dp[101][10001]; // i개 사용했을때 j 값 만든는 경우의수

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];			
	}
	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j - arr[i] < 0)
				;
			else
			{
				dp[j] += dp[j - arr[i]];
			}			
		}
	}

	cout << dp[k];

	return 0;
}