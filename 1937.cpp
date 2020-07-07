#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>	

using namespace std;
int n;
 
int dp[501][501] = { 0, };
int arr[501][501] = { 0, };

int func(int y,int x)
{
	if (dp[y][x]!=0)
		return dp[y][x];

	int ret = 1;

	if (arr[y + 1][x] > arr[y][x] && y+1 <= n)
		ret = max(ret, func(y + 1, x)+1); 
	if (arr[y - 1][x] > arr[y][x] && y -1 >= 0)
		ret = max(ret, func(y - 1, x) + 1);
	if (arr[y][x + 1] > arr[y][x] && x + 1 <= n)
		ret = max(ret, func(y, x + 1) + 1);
	if (arr[y][x - 1] > arr[y][x] && x - 1 >= 0)
		ret = max(ret, func(y, x - 1) + 1);
	
	dp[y][x] = ret;

	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ret = max(ret, func(i, j));
		}
	}
	
	cout << ret;
	

	return 0;
}