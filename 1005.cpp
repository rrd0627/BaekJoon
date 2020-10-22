#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>

using namespace std;

int CurToNext[1001][1001];
int CurToBefore[1001][1001];

int main()
{
	int T, N, K;
	cin >> T;
	
	int dp[1001];
	int arrW[1001];

	int input_temp1;
	int input_temp2;

	int W;

	queue<int> q;

	bool visited[1001];

	int cur;

	int next;

	int CurToNextIndex[1001];
	int CurToBeforeIndex[1001];

	bool IsReady;

	while (T--)
	{
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
		{
			cin >> dp[i];
			arrW[i] = 0;
			visited[i] = false;
			CurToNextIndex[i] = 0;
			CurToBeforeIndex[i] = 0;
			for (int j = 0; j <= N; j++)
			{
				CurToNext[i][j] = 0;
				CurToBefore[i][j] = 0;
			}
		}
		for (int i = 0; i < K; i++)
		{
			cin>> input_temp1;
			cin>> input_temp2;
			CurToNext[input_temp1][CurToNextIndex[input_temp1]++] = input_temp2;
			CurToBefore[input_temp2][CurToBeforeIndex[input_temp2]++] = input_temp1;
		}

		for (int i = 1; i <= N; i++)
		{
			if (CurToBefore[i][0] == 0) //처음 것임
			{
				q.push(i);
			}
		}


		while (!q.empty())
		{
			cur = q.front();
			q.pop();

			if (visited[cur])
				continue;

			IsReady = true;

			for (int i = 0; i <= N; i++)
			{
				if (CurToBefore[cur][i] != 0)
				{
					if (!visited[CurToBefore[cur][i]])//전 아이들이 도착안했으면
					{
						IsReady = false;
						break;
					}
				}
				else
					break;
			}

			if (!IsReady)
				continue;


			visited[cur] = true;

			dp[cur] += arrW[cur]; //내 값

			for (int i = 0; i < N; i++)
			{
				if (CurToNext[cur][i] != 0)
				{
					next = CurToNext[cur][i];

					arrW[next] = max(arrW[next], dp[cur]);

					q.push(next);
				}
				else
				{
					break;
				}
			}
		}

		cin >> W;
		cout << dp[W]<<endl;
	}

	return 0;
}