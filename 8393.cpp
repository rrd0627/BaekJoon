#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int a;
	cin >> a;
	int ret = 0;
	while (a--)
	{
		ret += a+1;
	}
	cout << ret;
	return 0;
}