#include <bits/stdc++.h>
#include <ranges>
using namespace std;

constexpr int INF = 1e9;

int dijkstra(int N, int M, int start, int target, const vector<vector<pair<int, int>>>& maps)
{
	vector<int> dist(N+1, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.emplace(0, start);
	dist[start] = 0;

	while (!pq.empty())
	{
		auto [cost, node] = pq.top();
		pq.pop();
		if (dist[node] < cost) continue;

		for (auto [nextCost, nextNode] : maps[node])
		{
			int newCost = cost + nextCost;
			if (newCost < dist[nextNode])
			{
				pq.emplace(newCost, nextNode);
				dist[nextNode] = newCost;
			}
		}
	}
	return dist[target];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N{}, M{}, X{};
	cin >> N >> M >> X;

	vector<vector<pair<int, int>>> maps(N+1);
	vector<int> dist(N+1, INF);
	for (int i=0; i<M; ++i)
	{
		int start{}, end{}, cost{};
		cin >> start >> end >> cost;
		maps[start].emplace_back(cost, end);
	}
	
	vector<int> resultDist(N+1, 0);
	for (int i=1; i<=N; ++i)
	{
		resultDist[i] += dijkstra(N, M, i, X, maps);
	}
	for (int i=1; i<=N; ++i)
	{
		resultDist[i] += dijkstra(N, M, X, i, maps);
	}

	cout << *max_element(resultDist.begin(), resultDist.end());
	return 0;
}