#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int t,a,b;
	cin >> t;
	while (t--)
	{
		scanf("%d%d", &a,&b);
		printf("%d\n", a + b);
	}
	return 0;
}