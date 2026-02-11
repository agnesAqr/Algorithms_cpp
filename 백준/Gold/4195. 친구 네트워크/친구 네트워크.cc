#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> parent{};
    vector<int> rank{};
    vector<int> networkSize{};

public:
    UnionFind(int n)
    {
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n+1, 0);
        networkSize.resize(n, 1);
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }

    int unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return networkSize[rootX];

        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
            networkSize[rootX] += networkSize[rootY];
            return networkSize[rootX];
        }
        else
        {
            parent[rootX] = rootY;
            networkSize[rootY] += networkSize[rootX];

            if (rank[rootX] == rank[rootY])
                rank[rootY]++;
            
            return networkSize[rootY];
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

    int N{};
    cin >> N;

    
    for (int i=0; i<N; ++i)
    {
        int F{};
        cin >> F;
        UnionFind uf(F*2+5);
        unordered_map<string, int> names{};
        int idx = 0;

        for (int j=0; j<F; ++j)
        {
            string f1{}, f2{};
            cin >> f1 >> f2;

            if (names.find(f1) == names.end())
                names[f1] = idx++;
            if (names.find(f2) == names.end())
                names[f2] = idx++;

            cout << uf.unite(names[f1], names[f2]) << "\n";
        }
    }
    
	return 0;
}