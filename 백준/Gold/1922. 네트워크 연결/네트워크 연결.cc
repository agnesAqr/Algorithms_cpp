#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N{}, M{};
    cin >> N >> M;
    vector<vector<pii>> adj_edges(N+1);
    for (int i=0; i<M; ++i)
    {
        int u{}, v{}, w{};
        cin >> u >> v >> w;
        adj_edges[u].emplace_back(w, v);
        adj_edges[v].emplace_back(w, u);
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<bool> visited(N+1, false);
    pq.emplace(0, 1);

    int mst_weight{}, mst_edge{};

    while (!pq.empty())
    {
        auto [w, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;

        visited[node] = true;
        mst_weight += w;
        mst_edge++;

        for (const auto& [nw, nextNode] : adj_edges[node])
        {
            if (!visited[nextNode])
                pq.emplace(nw, nextNode);
        }
    }
    cout << mst_weight;
    
	return 0;
}