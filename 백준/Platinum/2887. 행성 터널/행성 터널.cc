#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct Edge
{
    int u{}, v{}, w{};
    Edge(int u, int v, int w) : u(u), v(v), w(w){}
    bool operator<(const Edge& other) { return w < other.w; }
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
            parent[x] = y;
            rank[y]++;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N{};
    cin >> N;
    vector<pii> xVec(N), yVec(N), zVec(N);
    for (int i=0; i<N; ++i)
    {
        int x{}, y{}, z{};
        cin >> x >> y >> z;
        xVec[i] = {x, i};
        yVec[i] = {y, i};
        zVec[i] = {z, i};
    }
    sort(xVec.begin(), xVec.end());
    sort(yVec.begin(), yVec.end());
    sort(zVec.begin(), zVec.end());

    vector<Edge> edges;
    edges.reserve(3*(N-1));
    for (int i=0; i<N-1; ++i)
    {
        edges.emplace_back(xVec[i].second, xVec[i+1].second, abs(xVec[i].first - xVec[i+1].first));
        edges.emplace_back(yVec[i].second, yVec[i+1].second, abs(yVec[i].first - yVec[i+1].first));
        edges.emplace_back(zVec[i].second, zVec[i+1].second, abs(zVec[i].first - zVec[i+1].first));
    }
    sort(edges.begin(), edges.end());

    UnionFind uf(N);
    long long mst_weight{};
    int mst_edgeCount{};
    for (const auto& [u, v, w] : edges)
    {
        if (uf.unite(u, v))
        {
            mst_weight += w;
            if (++mst_edgeCount == N-1) break;
        }
    }
    cout << mst_weight;

    return 0;
}