#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;

	cin >> N;

	long long dp[91] = { 0,};
	
	dp[1] = 1;	

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N];
	

	return 0;
}