#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int dijkstra(int N, int K, const vector<vector<pair<int, int>>>& graph, vector<int>& dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;
    
    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();
        
        if (dist[node] < cost) continue;
        
        for (auto [nextCost, nextNode] : graph[node])
        {
            int newCost = cost + nextCost;
            if (dist[nextNode] <= newCost) continue;
            
            pq.emplace(newCost, nextNode);
            dist[nextNode] = newCost;
        }
    }
    
    return count_if(dist.begin()+1, dist.begin()+N+1,
                   [K](int d){ return d <= K; });
}

int solution(int N, vector<vector<int>> road, int K) {
    vector<vector<pair<int, int>>> graph(N+1);
    for (const auto& r : road)
    {
        graph[r[0]].emplace_back(r[2], r[1]);
        graph[r[1]].emplace_back(r[2], r[0]);
    }
    vector<int> dist(N+1, INF);
    return dijkstra(N, K, graph, dist);
}