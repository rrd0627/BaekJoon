#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;

int arr[501][2];

int dp[501][501];

int DpFunc(int first,int second)
{
	if (first == second)
		return 0;

	if (dp[first][second] != -1)
	{
		return dp[first][second];
	}

	int ret = 0x7fffffff;

	if (second - first <= 1)
	{
		ret = arr[first][0] * arr[first][1] * arr[second][1];
		dp[first][second] = ret;
		return ret;
	}



	for (int i = first; i < second; i++)
	{
		ret = min(ret,DpFunc(first, i) + DpFunc(i+1,second) + arr[first][0]*arr[i][1]*arr[second][1]);
	}


	dp[first][second] = ret;
	return ret;
}


int main()
{
	int count;

	cin >> count;
	
	for (int i = 0; i < count; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
		{
			dp[i][j] = -1;
		}
	}

	cout << DpFunc(0, count-1);

	return 0;
}