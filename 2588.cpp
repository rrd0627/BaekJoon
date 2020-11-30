#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int a, b;

	int first, second, third;

	cin >> a >> b;

	first = b / 100;

	second = (b - 100 * first) / 10;

	third = b - first * 100 - second * 10;

	cout << a * third<<endl;
	cout << a * second << endl;
	cout << a * first << endl;
	cout << a * b;
	return 0;
}