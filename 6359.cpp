#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>	

using namespace std;
int n;

bool arr[101] = { false, };

int main()
{
	cin >> n;
	
	int k;
	int ret;
	for (int i = 0; i < n; i++)
	{
		cin >> k;

		for (int j = 0; j <= k; j++)
		{
			arr[j] = false;
		}

		for (int j = 1; j <= k; j++) //�����ϴ¼�
		{
			for (int l = j; l <= k; l+=j) //ó������ ������
			{
				arr[l] = !arr[l];
			}
		}
		
		ret = 0;
		for (int j = 0; j <= k; j++)
		{
			if (arr[j])ret++;
		}

		cout << ret << endl;

	}

	return 0;
}