#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int dijkstra(int startCity, int targetCity, const vector<vector<pair<int, int>>>& graph, vector<int>& dist)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, startCity);
	dist[startCity] = 0;

	while (!pq.empty())
	{
		auto [currCost, currNode] = pq.top();
		pq.pop();
		if (currCost > dist[currNode]) continue;

		if (currNode == targetCity)
			return dist[currNode];
		
		for (auto [nextCost, nextNode] : graph[currNode])
		{
			int newCost = currCost + nextCost;
			if (newCost < dist[nextNode])
			{
				dist[nextNode] = newCost;
				pq.emplace(newCost, nextNode);
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N{}, M{};
	cin >> N >> M;

	vector<vector<pair<int, int>>> graph(N+1);
	vector<int> dist(N+1, INF);
	for (int i=0; i<M; ++i)
	{
		int from{}, to{}, cost{};
		cin >> from >> to >> cost;
		graph[from].emplace_back(cost, to);
	}
	int start{}, target{};
	cin >> start >> target;
	cout << dijkstra(start, target, graph, dist);
}