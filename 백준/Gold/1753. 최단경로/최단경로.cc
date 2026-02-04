#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

void dijkstra(const vector<vector<pair<int, int>>>& maps, vector<int>& dist, int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.emplace(0, start);
	dist[start] = 0;

	while (!pq.empty())
	{
		auto [cost, currNode] = pq.top();
		pq.pop();

		if (dist[currNode] < cost) continue;

		for (int i=0; i<maps[currNode].size(); ++i)
		{
			auto [nextCost, nextNode] = maps[currNode][i];
			int newCost = cost + nextCost;
			if (newCost < dist[nextNode])
			{
				dist[nextNode] = newCost;
				pq.emplace(newCost, nextNode);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V{}, E{}, K{};
	cin >> V >> E >> K;

	vector<vector<pair<int, int>>> maps(V+1);
	vector<int> dist(V+1, INF);
	for (int i=0; i<E; ++i)
	{
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		maps[u].emplace_back(w, v);
	}
	dijkstra(maps, dist, K);

	for (int i=1; i<=V; ++i)
	{
		if (dist[i] == INF)
				cout << "INF";
		else
			cout << dist[i];
		cout << "\n";
	}

	return 0;
}