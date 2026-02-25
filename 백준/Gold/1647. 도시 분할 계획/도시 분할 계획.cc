#include <bits/stdc++.h>
using namespace std;

struct Edge
{   
    int u{}, v{}, w{};
    Edge(int u, int v, int w) : u(u), v(v), w(w){};
    bool operator<(const Edge& other) { return w < other.w; }
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N{}, M{};
    cin >> N >> M;

    vector<Edge> edges;
    edges.reserve(M+1);
    for (int i=0; i<M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    sort(edges.begin(), edges.end());
    
    if (N == 2)
    {
        cout << 0;
        return 0;
    }

    UnionFind uf(N);
    int mst_weight{}, mst_edgeCount{};
    for (const auto& [u, v, w] : edges)
    {
        if (uf.unite(u, v))
        {
            mst_weight += w;
            mst_edgeCount++;
            if (mst_edgeCount == N-2)
            {
                cout << mst_weight;
                break;
            }
        }
    }
    
	return 0;
}