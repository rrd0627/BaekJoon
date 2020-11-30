#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int a,b;
	cin >> a>>b;

	if (a >= 0)
	{
		if (b >= 0)
			cout << "1";
		else
			cout << "4";
	}
	else
	{
		if (b >= 0)
			cout << "2";
		else
			cout << "3";
	}
	
	return 0;
}