#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    Edge(int u, int v, int w) : u(u), v(v), w(w){};
    bool operator<(const Edge other) { return w < other.w; }
    int u, v, w;
};

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) : parent(n+1), rank(n+1)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        
        if (rank[x] > rank[y]) parent[y] = x;
        else if (rank[y] > rank[x]) parent[x] = y;
        else
        {
            parent[x] = y;
            rank[y]++;
        }
        return true;
    }
};

int solution(int n, vector<vector<int>> costs) {
    
    vector<Edge> edges;
    edges.reserve(costs.size());
    for (const auto& cost : costs)
    {
        edges.emplace_back(cost[0], cost[1], cost[2]);
    }
    sort(edges.begin(), edges.end());
    
    UnionFind uf(n+1);
    int mst_weight{}, mst_edgeCount{};
    for (const auto& [u, v, w] : edges)
    {   
        if (uf.unite(u, v))
        {
            mst_weight += w;
            mst_edgeCount++;
            
            if (mst_edgeCount == n-1) break;
        }
    }
    
    return mst_weight;
}