#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void DFS(int curr)
{
	visited[curr] = true;
	cout << curr << " ";
	
	for (int next : adj[curr])
	{
		if (!visited[next])
			DFS(next);
	}
}

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout << curr << " ";
		
		for (int next : adj[curr])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
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

	adj.resize(N+1);
	visited.assign(N+1, false);

	for (int i=0; i<M; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i=1; i<=N; ++i)
	{
		sort(adj[i].begin(), adj[i].end());
	}

	DFS(V);
	cout << "\n";
	visited.assign(N+1, false);
	BFS(V);

	return 0;
}