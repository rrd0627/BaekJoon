#include <string>
#include <vector>
#include<iostream>
using namespace std;



int main()
{
	int hour;
	int min;

	cin >> hour >> min;

	if (min >= 45)
	{
		cout << hour << " " << min-45;
	}
	else
	{
		if (hour == 0)
		{
			cout << "23" << " " << min + 15;
		}
		else
		{
			cout << hour - 1 << " " << min + 15;
		}		
	}

	

	return 0;
}