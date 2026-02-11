#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> parent{};
    vector<int> rank{};

public:
    UnionFind(int n)
    {
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n+1, 0);
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else
        {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
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

    UnionFind uf(N);
    for (int i=1; i<=N; ++i)
    {
        for (int j=1; j<=N; ++j)
        {
            int isConnected{};
            cin >> isConnected;
            if (isConnected == 1)
                uf.unite(i, j);
        }
    }
    
    if (M == 0)
    {
        cout << "YES";
        return 0;
    }
    
    int firstCity{};
    cin >> firstCity;
    int root = uf.find(firstCity);

    bool possible = true;
    for (int i=1; i<M; ++i)
    {
        int nextCity;
        cin >> nextCity;
        if (root != uf.find(nextCity))
            possible = false;
    }
    cout << (possible ? "YES" : "NO");

	return 0;
}