class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> graph(n);
        vector<double> probability(n, 0.0);
        for (int i=0; i<edges.size(); ++i)
        {
            const auto& edge = edges[i];
            graph[edge[0]].emplace_back(succProb[i], edge[1]);
            graph[edge[1]].emplace_back(succProb[i], edge[0]);
        }

        auto dijkstra = [&](){
            priority_queue<pair<double, int>> pq;
            pq.emplace(1.0, start_node);
            probability[start_node] = 1.0;

            while (!pq.empty())
            {
                auto [prob, node] = pq.top();
                pq.pop();

                if (node == end_node) return prob;
                if (prob < probability[node]) continue;

                for (auto& [nextProb, nextNode] : graph[node])
                {
                    auto newProb = prob * nextProb;
                    if (newProb > probability[nextNode])
                    {
                        probability[nextNode] = newProb;
                        pq.emplace(newProb, nextNode);
                    }
                }
            }
            return 0.0;
        };

        dijkstra();
        return probability[end_node];
    }
};
