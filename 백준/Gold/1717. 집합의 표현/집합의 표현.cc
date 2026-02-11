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

	int n{}, m{};
	cin >> n >> m;

	UnionFind uf(n);

	for (int i=0; i<m; ++i)
	{
		int flag{}, a{}, b{};
		cin >> flag >> a >> b;

		if (flag == 0)
		{
			uf.unite(a, b);
		}
		else
		{
			cout << (uf.isConnected(a, b) ? "YES\n" : "NO\n");
		}
	}
}