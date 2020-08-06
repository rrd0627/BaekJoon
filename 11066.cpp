#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>	
#include<math.h>
using namespace std;
//dp[i][j]   i 부터 j 까지 그 합이 가장 작은 값
int dp[501][501];
int cost[501];
int sum[501];
int t, k, i;

int main() {
	cin >> t;
	while (t--) {
		cin >> k;
		for (i = 1; i <= k; ++i) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}

		for (int d = 1; d < k; ++d) {
			for (int tx = 1; tx + d <= k; ++tx) {
				int ty = tx + d;
				dp[tx][ty] = 99999999;

				for (int mid = tx; mid < ty; ++mid)
					dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
			}
		}

		cout << dp[1][k]<<endl;
	}
	return 0;
}
