#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N{}, M{}, X{};
	cin >> N >> M >> X;

	vector<vector<pair<int, int>>> adj(N + 1);  // come (X -> Home)
    vector<vector<pair<int, int>>> rev_adj(N + 1);  // go (Home -> X)
	for (int i=0; i<M; ++i)
	{
		int start{}, end{}, cost{};
		cin >> start >> end >> cost;
		adj[start].emplace_back(cost, end);
        rev_adj[end].emplace_back(cost, start);
	}

	auto dijkstra = [&](int start, const vector<vector<pair<int,int>>>& graph)
	{
        vector<int> dist(N+1, INF);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty())
		{
            auto [cost, node] = pq.top();
			pq.pop();

            if (dist[node] < cost) continue;

            for (auto [nextCost, nextNode] : graph[node])
			{
				int newCost = cost + nextCost;
                if (newCost < dist[nextNode])
				{
                    dist[nextNode] = newCost;
                    pq.emplace(newCost, nextNode);
                }
            }
        }
        return dist;
    };
	
	auto come_dist = dijkstra(X, adj);
	auto go_dist = dijkstra(X, rev_adj);

	int result{};
	for (int i=1; i<=N; ++i)
		result = max(result, come_dist[i] + go_dist[i]);

	cout << result;
	return 0;
}