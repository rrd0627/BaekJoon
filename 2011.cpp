#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;
#define mod 1000000
int main()
{
	char code[5001];
	cin >> code;
	string codes;
	codes = code;
	int codesize = codes.size();

	int dp[5001] = { 0, };

	int ret;

	for (int i = 0; i < 5001; i++)
	{
		dp[i] = 0;
	}
	dp[0] = 1;
	dp[1] = 1;

	if (code[0] == '0')
	{
		printf("0");
		return 0;
	}

	for (int i = 2; i <= codesize; i++)
	{
		if (code[i-1] != '0')
			dp[i] = dp[i - 1];

		int num = 10 * (code[i - 2] - '0') + (code[i - 1] - '0');

		if (num <= 26 && num >= 10)
			dp[i] = (dp[i] + dp[i - 2]) % mod;		
	}
	ret = dp[codesize];

	printf("%d",ret);

	return 0;
}