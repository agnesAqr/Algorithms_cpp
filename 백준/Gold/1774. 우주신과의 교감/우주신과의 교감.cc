#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct Edge
{
    int u{}, v{};
    double w{};
    Edge(int u, int v, double w) : u(u), v(v), w(w){};
    bool operator<(const Edge& other) { return w < other.w; }
};

class UnionFind
{
private:
    vector<int> parent, rank;
public:
    UnionFind(int n) : parent(n+1), rank(n+1, 0)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite (int x, int y)
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
    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N{}, M{};
    cin >> N >> M;
    vector<pii> gods(N+1);
    for (int i=1; i<=N; ++i)
    {
        int x{}, y{};
        cin >> x >> y;
        gods[i] = {x, y};
    }

    UnionFind uf(N);
    for (int i=0; i<M; ++i)
    {
        int u{}, v{};
        cin >> u >> v;
        uf.unite(u, v);
    }

    vector<Edge> edges;
    edges.reserve(N);
    for (int i=1; i<=N; ++i)
    {
        for (int j=i+1; j<=N; ++j)
        {
            if (uf.isConnected(i, j)) continue;
            double cost = hypot(gods[i].first - gods[j].first, gods[i].second-gods[j].second);
            edges.emplace_back(i, j, cost);
        }
    }
    sort(edges.begin(), edges.end());
    
    double mst_weight{};
    for (const auto&[u, v, w] : edges)
    {
        if (uf.unite(u, v))
        {
            mst_weight += w;
        }
    }
    cout << fixed << setprecision(2) << mst_weight;
	return 0;
}