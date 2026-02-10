#include <bits/stdc++.h>
using namespace std;

constexpr int MAXNODE = 200;
constexpr int INF = 1e9;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<pair<int, int>>> graph(n+1);
    for (const auto& f : fares)
    {
        graph[f[0]].emplace_back(f[2], f[1]);
        graph[f[1]].emplace_back(f[2], f[0]);
    }
    
    auto dijkstra = [&](int start) -> vector<int>{
        vector<int> dist(n+1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, start);
        dist[start] = 0;
        
        while (!pq.empty())
        {
            auto [cost, node] = pq.top();
            pq.pop();
            
            if (cost > dist[node]) continue;
            
            for (const auto& [nextCost, nextNode] : graph[node])
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
    
    vector<int> distS = dijkstra(s);
    vector<int> distA = dijkstra(a);  // A -> K (== K -> A)
    vector<int> distB = dijkstra(b);  // B -> K (== K -> B)
    
    int answer = INF;
    for (int k=1; k<=n; ++k)
    {
        if (distS[k] != INF && distA[k] != INF && distB[k] != INF)
        {
            answer = min(answer, distS[k] + distA[k] + distB[k]);
        }
    }
    
    return answer;
}