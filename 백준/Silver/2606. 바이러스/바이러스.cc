#include <bits/stdc++.h>
using namespace std;

int parent[101];

int find(int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x!= y)
		parent[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	iota(parent+1, parent+n+1, 1);

	for (int i=0; i<m; ++i)
	{
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}

	int result = 0;
	int root1 = find(1);

	for (int i=2; i<=n; ++i)
	{
		if (find(i) == root1)
			result++;
	}

	cout << result;

	return 0;
}