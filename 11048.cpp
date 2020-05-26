#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N, M;

	cin >> N >> M;

	int arr[1001] = { 0, };

	int temp;

	for (int i = 1; i <= N; i++)
	{	 
		for (int j = 1; j <= M; j++)
		{
			cin >> temp;

			arr[j] = max(arr[j - 1]+temp, temp + arr[j]);
		}
	}
	cout << arr[M];
	
	return 0;
}