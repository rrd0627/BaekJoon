#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;


int arr[2][100002];

int main()
{
	int n,m;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m;

		for (int j = 0; j < m; j++)
		{
			cin >> arr[0][j];
		}
		for (int j = 0; j < m; j++)
		{
			cin >> arr[1][j];
		}

		arr[0][1] += arr[1][0];
		arr[1][1] += arr[0][0];


		for (int i = 2; i < m; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (j == 0)
				{
					arr[j][i] += max(arr[j+1][i - 1], arr[j+1][i-2]);
				}
				else
				{
					arr[j][i] += max(arr[j - 1][i - 1], arr[j - 1][i - 2]);
				}
			}
		}

		cout << max(arr[0][m-1], arr[1][m-1])<<endl;
	}
	
	return 0;
}