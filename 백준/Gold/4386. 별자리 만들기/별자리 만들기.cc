#include <bits/stdc++.h>
using namespace std;
using pff = pair<float, float>;

struct Edge
{
    int u{}, v{};
    float w{};
    Edge(int u, int v, float w) : u(u), v(v), w(w){};
    bool operator<(const Edge& other) const { return w < other.w; }
};

class UnionFind
{
private:
    vector<int> parent, rank;
public:
    UnionFind(int n) : parent(n), rank(n, 0)
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
            parent[y] = x;
            rank[x]++;
        }
        return true;
    }
};

float CalculateCost(pff s1, pff s2)
{
    return hypot(s2.first - s1.first, s2.second - s1.second);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n{};
    cin >> n;

    vector<pff> stars(n);
    for (int i=0; i<n; ++i)
    {
        cin >> stars[i].first >> stars[i].second;
    }

    vector<Edge> edges;
    edges.reserve(n*(n-1)/2);
    for (int i=0; i<n; ++i)
    {
        for (int j=i+1; j<n; ++j)
        {
            if (j == i) continue;
            float dist = CalculateCost(stars[i], stars[j]);
            edges.emplace_back(i, j, dist);
        }
    }
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    float mst_weight{};
    int mst_edgeCount{};
    for (const auto& [u, v, w] : edges)
    {
        if (uf.unite(u, v))
        {
            mst_weight += w;
            if (++mst_edgeCount == n-1)
                break;
        }
    }
    printf("%.2f\n", mst_weight);
    
	return 0;
}