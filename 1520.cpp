#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int dp[501][501] = { -1, };
int arr[501][501] = { 0, };
int n, m;

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { 1,0,-1,0 };

int dfs(int y, int x)
{
	if (y == 0 && x == 0)
		return 1;

	if (dp[y][x] == -1)
	{
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++)
		{
			if (0 <= dx[i] + x && n > dx[i] + x && 0 <= dy[i] + y && m > dy[i] + y)
			{
				if (arr[y][x] < arr[y + dy[i]][x + dx[i]])
				{
					dp[y][x] += dfs(y + dy[i], x + dx[i]);
				}
			}
		}
	}
	
	return dp[y][x];
}

int main()
{
	
	cin >> m>>n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}



	cout <<dfs(m-1,n-1);

	return 0;
}