#include <bits/stdc++.h>
using namespace std;

bool graph[1000][1000];
bool visited[1000];

void DFS(int nodeNum, int edgeNum, int startNode)
{
	if (visited[startNode-1])
		return;
	
	visited[startNode-1] = true;
	cout << startNode << " ";

	for(int i=0; i<nodeNum; ++i)
	{
		if (graph[startNode-1][i])
		{
			DFS(nodeNum, edgeNum, i+1);
		}
	}
}

void BFS(int nodeNum, int edgeNum, int startNode)
{
	queue<int> q;
	q.push(startNode);
	visited[startNode-1] = true;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout << curr << " ";
		
		for (int i=0; i<nodeNum; ++i)
		{
			if (curr-1 == i)
				continue;

			if (graph[curr-1][i] && !visited[i])
			{
				q.push(i+1);
				visited[i] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N{}, M{}, V{};
	cin >> N >> M >> V;
	for (int i=0; i<M; ++i)
	{
		int n1{}, n2{};
		cin >> n1 >> n2;
		graph[n1-1][n2-1] = 1;
		graph[n2-1][n1-1] = 1;
	}

	DFS(N, M, V);
	cout << "\n";
	memset(visited, 0, sizeof(visited));
	BFS(N, M, V);

	return 0;
}