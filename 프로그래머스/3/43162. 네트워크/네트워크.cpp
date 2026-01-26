#include <bits/stdc++.h>

using namespace std;

struct UnionFind
{
    vector<int> parent;
    vector<int> rank;
    
    UnionFind(int n) : parent(n+1), rank(n+1, 0)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else
            {
                parent[rootY] = rootX;
                if (rank[rootX] == rank[rootY])
                    rank[rootX]++;
            }
        }
    }
    
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};
  

int solution(int n, vector<vector<int>> computers)
{
    int answer{};
    
    UnionFind uf(n);
    for (int i=0; i<n; ++i)
    {
        for (int j=i+1; j<n; ++j)
        {
            if (i != j && computers[i][j] == 1)
                uf.unite(i, j);
        }
    }
    
    for (int i=0; i<n; ++i)
    {
        if (uf.parent[i] == i)
            answer++;
    }
    
    return answer;
}
