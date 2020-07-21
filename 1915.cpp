#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>	
#include<math.h>
using namespace std;
int n,m;

char arr[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };

int main()
{
	cin >> n>>m;
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = arr[i][j]-'0';
			if (arr[i][j] == '1')ret = 1;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (arr[i][j] == '1')
			{
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1],dp[i-1][j-1])) + 1;
				if (ret < dp[i][j])
					ret = dp[i][j];
			}				
		}
	}
	ret = ret * ret;

	cout << ret << endl;

	return 0;
}