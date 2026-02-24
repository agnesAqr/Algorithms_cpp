#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> parent;

public:
    UnionFind(int n) : parent(n+1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y) return;

        parent[x] = y;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int G{}, P{};
    cin >> G >> P;

    vector<int> planes(P, 0);
    for (int i=0; i<P; ++i)
    {
        cin >> planes[i];
    }
    
    UnionFind uf(G);
    int result{};
    for (int i=0; i<P; ++i)
    {
        int openGate = uf.find(planes[i]);
        if (openGate == 0)
            break;
        
        uf.unite(openGate, openGate-1);
        result++;
    }
    cout << result;

	return 0;
}