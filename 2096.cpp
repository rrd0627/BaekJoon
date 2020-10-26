#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>

using namespace std;

int dpmax[3] = { 0, };
int dpmin[3] = { 0, };

int maxarr[3];
int minarr[3];


int main()
{
	int N,temp;
	cin >> N;
	
	cin >> temp;
	dpmax[0] = temp;
	dpmin[0] = temp;
	cin >> temp;
	dpmax[1] = temp;
	dpmin[1] = temp;
	cin >> temp;
	dpmax[2] = temp;
	dpmin[2] = temp;

	for (int i = 1; i < N; i++)
	{
		cin >> temp;

		maxarr[0] = max(dpmax[0], dpmax[1])+temp;
		minarr[0] = min(dpmin[0], dpmin[1])+temp;

		cin >> temp;

		maxarr[1] = max(max(dpmax[0], dpmax[1]),dpmax[2]) + temp;
		minarr[1] = min(min(dpmin[0], dpmin[1]),dpmin[2]) + temp;

		cin >> temp;

		maxarr[2] = max(dpmax[1], dpmax[2]) + temp;
		minarr[2] = min(dpmin[1], dpmin[2]) + temp;

		dpmax[0] = maxarr[0];
		dpmin[0] = minarr[0];
		dpmax[1] = maxarr[1];
		dpmin[1] = minarr[1];
		dpmax[2] = maxarr[2];
		dpmin[2] = minarr[2];

	}	
	
	cout << max(max(dpmax[0], dpmax[1]), dpmax[2])<<" "<< min(min(dpmin[0], dpmin[1]), dpmin[2]);
	

	return 0;
}