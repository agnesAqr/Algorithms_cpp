constexpr int INF = 1e9;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for (const auto& time : times)
        {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            graph[u].emplace_back(w, v);
        }
        
        vector<int> dist(n+1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, k);
        dist[k] = 0;
        
        while (!pq.empty())
        {
            auto [currCost, currNode] = pq.top();
            pq.pop();

            if (dist[currNode] < currCost) continue;

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
        
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};