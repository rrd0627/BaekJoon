#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
using namespace std;

int dp[1001][1001] = { 0, };

int main()
{
	string str_a, str_b;

	cin >> str_a>>str_b;
	
	for (int i = 1; i <= str_a.length(); i++)
	{
		for (int j = 1; j <= str_b.length(); j++)
		{			
			dp[i][j] = max(max(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1] + (str_a[i-1]==str_b[j-1]));	
		}
	}

	int ret = dp[str_a.length()][str_b.length()];

	cout << ret<<endl;

	string str_ret="";

	int temp1, temp2;

	temp1 = str_a.length();
	temp2 = str_b.length();

	while(temp1 !=0 && temp2 !=0)
	{
		if (dp[temp1][temp2] == dp[temp1 - 1][temp2])
		{
			temp1--;
		}
		else if (dp[temp1][temp2] == dp[temp1][temp2 - 1])
		{
			temp2--;
		}
		else
		{
			str_ret.push_back(str_a[temp1 - 1]);
			temp1--;
			temp2--;
		}		
	}

	reverse(str_ret.begin(), str_ret.end());
	
	if(ret!=0)
		cout << str_ret<<endl;

	return 0;
}