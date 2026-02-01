#include <bits/stdc++.h>
using namespace std;

int M{}, N{};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[101][101];
int currSectionWidth = 0;

void dfs(int x, int y)
{
	visited[y][x] = true;
	currSectionWidth++;

	for (int z=0; z<4; ++z)
	{
		int nx = x + dx[z];
		int ny = y + dy[z];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;

		if (!visited[ny][nx])
			dfs(nx, ny);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K{};
	cin >> M >> N >> K; // M(y), N(x)

	for (int i=0; i<K; ++i)
	{
		int lx{}, ly{}, rx{}, ry{};
		cin >> lx >> ly >> rx >> ry;

		for (int r=ly; r<ry; ++r)
		{
			for (int c=lx; c<rx; ++c)
			{
				if (!visited[r][c])
					visited[r][c] = true;
			}
		}
	}

	vector<int> sections{};

	for (int r=0; r<M; ++r)
	{
		for (int c=0; c<N; ++c)
		{
			if (!visited[r][c])
			{
				currSectionWidth = 0;
				dfs(c, r);
				sections.emplace_back(currSectionWidth);
			}
		}
	}

	cout << sections.size() << "\n";
	sort(sections.begin(), sections.end());
	for (int s : sections)
		cout << s << " ";

	return 0;
}