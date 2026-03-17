#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u{}, v{}, w{};
    Edge(int u, int v, int w) : u(u), v(v), w(w){};
    bool operator< (const Edge& other) const { return w < other.w; }
};

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V{}, E{};
    cin >> V >> E;
    vector<Edge> edges;
    edges.reserve(E);
    for (int i=0; i<E; ++i)
    {
        int a{}, b{}, c{};
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
    sort(edges.begin(), edges.end());

    UnionFind uf(V);
    int mst_weight{}, mst_edge{};
    for (const Edge& e : edges)
    {
        if (uf.unite(e.u, e.v))
        {
            mst_weight += e.w;
            mst_edge++;
            if (mst_edge == V-1) break;
        }
    }
    cout << mst_weight;

    return 0;
}