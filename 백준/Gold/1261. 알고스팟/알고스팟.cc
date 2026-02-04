#include <bits/stdc++.h>
using namespace std;

int N{}, M{};
int maps[105][105];
int dist[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

const int INF = 1e9;

void bfs_0_1()
{
	deque<pair<int, int>> dq;

	for (int i=0; i<N; ++i)
	{
		fill(dist[i], dist[i]+M, -1);
	}
	dq.push_back({0, 0});
	dist[0][0] = 0;

	while (!dq.empty())
	{
		auto [y, x] = dq.front();
		dq.pop_front();

		if (y == N-1 && x == M-1)
		{
			cout << dist[y][x];
			return;
		}

		for (int i=0; i<4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || nx<0 || ny>=N || nx>=M) continue;

			if (dist[ny][nx] == -1)
			{
				if (maps[ny][nx] == 0)
				{
					dist[ny][nx] = dist[y][x];
					dq.push_front({ny, nx});
				}
				else
				{
					dist[ny][nx] = dist[y][x] + 1;
					dq.push_back({ny, nx});
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	for (int i=0; i<N; ++i)
	{
		string s{};
		cin >> s;
		for (int j=0; j<M; ++j)
		{
			maps[i][j] = s[j] - '0';
		}
	}
	bfs_0_1();
	
	return 0;
}