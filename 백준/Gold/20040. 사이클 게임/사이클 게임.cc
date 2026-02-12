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
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n);
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;

        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else if (rank[rootY] > rank[rootX])
        {
            parent[rootX] = rootY;
        }
        else
        {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{}, m{}, result{};
    cin >> n >> m;
    
    UnionFind uf(n);
    for (int i=1; i<=m; ++i)
    {
        int n1{}, n2{};
        cin >> n1 >> n2;

        if (!uf.unite(n1, n2))
        {
            result = i;
            break;
        }
    }
    cout << result;

    return 0;
}