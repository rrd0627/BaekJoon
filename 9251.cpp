#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;


int dp[1001][1001];

int main()
{
	char s1[1001];
	char s2[1001];

	cin >> s1 >> s2;
	
	


	int temp = 0;
	for (int i = 0; i < strlen(s1); i++)
	{
		if (s1[i] == s2[0])
		{
			temp = i;
			while (temp< strlen(s1))
			{
				dp[temp++][0] = 1;
			}
			break;
		}		
	}

	for (int i = 0; i < strlen(s2); i++)
	{
		if (s1[0] == s2[i])
		{
			temp = i;
			while (temp < strlen(s2))
			{
				dp[0][temp++] = 1;
			}
			break;
		}
	}

	for (int i = 1; i < strlen(s1); i++)
	{
		for(int j= 1;j< strlen(s2);j++)
		{
			if (s1[i] == s2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}				
			else
			{
				dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
			}

		}
	}

	cout << dp[strlen(s1)-1][strlen(s2)-1];

	return 0;
}