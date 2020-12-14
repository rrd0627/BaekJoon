#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	string str_temp;

	int N , int_temp;

	int stack[10001];
	int stack_index=0;

	for(int i=0;i<=10000;i++)
	{
		stack[i] = 0;
	}

	cin>>N;

	for(int i=0;i<N;i++)
	{
		cin>>str_temp;

		if(str_temp == "push")
		{
			cin>>int_temp;

			stack[stack_index] = int_temp;

			stack_index++;
		}
		else if(str_temp == "top")
		{
			if(stack_index == 0)
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<stack[stack_index-1]<<endl;				
			}			
		}
		else if(str_temp=="size")
		{
			cout<<stack_index<<endl;
		}
		else if(str_temp=="pop")
		{
			if(stack_index == 0)
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<stack[stack_index-1]<<endl;	

				stack_index--;			
			}	
		}
		else if(str_temp=="empty")
		{
			if(stack_index==0)
			{
				cout<<1<<endl;
			}
			else
			{
				
				cout<<0<<endl;
			}			
		}
	}
	return 0;
}