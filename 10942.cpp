#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;


int arr[2001] = { 0, };
int dp[2001][2001] = { 0, };
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for (int i = 1; i <= N; i++) 
	{
		dp[i][i] = 1;
	}

	for (int i = 1; i < N; i++)
	{
		dp[i][i+1] = arr[i]==arr[i+1];
	}

	for (int i = 2; i < N; i++) //사이 길이
	{
		for (int j = 1; j+i <= N; j++) //left
		{
			dp[j][j + i] = dp[j + 1][j + i - 1] && arr[j] == arr[j + i];
		}
	}

	int M;

	scanf("%d", &M);
	int left, right;

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &left,&right);
		printf("%d\n", dp[left][right]);
	}

	return 0;
}