#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N,M,V;
int graph[1001][1001];
bool visit[1001];

void dfs(int index)
{
	if(visit[index])
	{
		return;
	}
	cout<<index<<' ';
	visit[index] = true;
	for(int i=0;i<=N;i++)
	{
		if(graph[index][i]==1)
		{
			dfs(i);
		}
	}	
}

void bfs(int index)
{
	int temp;
	queue<int> q;
    q.push(index);
    while(!q.empty()) {		
        temp = q.front();
		q.pop();
		if(visit[temp]==1)continue;
		visit[temp] = 1;
        cout << temp << ' ';
        for(int i=1; i<=N; i++) {
            if(visit[i] == 1 || graph[temp][i] == 0)
                continue;
            q.push(i);
        }
    }
}

int main()
{
	cin>>N>>M>>V;

	int front,back;

	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			graph[i][j] = 0;
		}
		visit[i] = false;
	}

	for(int i=0;i<M;i++)
	{
		cin>>front>>back;

		graph[front][back] = 1;
		graph[back][front] = 1;
	}

	dfs(V);

	cout<<endl;
	for(int i=0;i<=1000;i++)
	{
		visit[i] = false;
	}

	bfs(V);

	return 0;
}