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
	int b;
	scanf("%d", &a);
	b = a;
	while (a--)
	{
		printf("%d\n", b - a);
	}
	return 0;
}