#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,k;

	int arr[101] = { 0, };
	int dp[10001] = { 0, }; // j �� ����� ����Ǽ�  �Ʒ��ǰ��� �ٽ� Ȱ���ϱ�
	//int dp[101][10001]; // i�� ��������� j �� ����� ����Ǽ�

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