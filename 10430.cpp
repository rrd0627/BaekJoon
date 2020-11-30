#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	cout << (a + b) % c<<endl;
	cout << (a%c + b%c)%c << endl;
	cout << (a * b) % c << endl;
	cout << (a%c * b%c) % c;


	return 0;
}