            rank[y]++;
        else if (rank[y] > rank[x]) parent[x] = y;
        else
        {
            parent[x] = y;
        if (x == y) return false;

        if (rank[x] > rank[y]) parent[y] = x;
    bool unite(int x, int y)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
public:
    UnionFind(int n) : parent(n+1), rank(n+1, 0)
    {
{
private:
    vector<int> parent;
    vector<int> rank;
        }
        return true;
