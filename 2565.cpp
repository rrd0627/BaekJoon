#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>

using namespace std;

pair<int, int> pr[101];

int arr[101] = { 0, };

int dp[101] = { 0, };

int main()
{
	int ret = 0;
	int N,temp1,temp2;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> temp1 >> temp2;

		pr[i].first = temp1;
		pr[i].second = temp2;
	}
	
	sort(pr, pr +N);
	for (int i = 1; i < N; i++)
	{		
		for(int j=0;j<=i;j++)
		{
			if (pr[i].second > pr[j].second && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				ret = max(ret, dp[i]);
			}
		}
	}
	
	cout << N - (ret+1); // dp�� 1�� �ƴ϶� 0���� �ʱ�ȭ �Ǿ��⶧���� 1 ������

	return 0;
}