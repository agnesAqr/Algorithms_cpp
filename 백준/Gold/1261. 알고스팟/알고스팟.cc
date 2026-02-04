#include <bits/stdc++.h>
using namespace std;

int N{}, M{};
int maps[105][105];
int dist[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

const int INF = 1e9;

int dijkstra()
{
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	
	for (int i=0; i<N; ++i)
		fill(dist[i], dist[i]+M , INF);
	
	pq.emplace(0, 0, 0);
	dist[0][0] = 0;

	while(!pq.empty())
	{
		auto [cost, row, col] = pq.top();
		pq.pop();

		if (dist[row][col] < cost) continue;

		for (int i=0; i<4; ++i)
		{
			int nr = row + dy[i];
			int nc = col + dx[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;

			int nextCost = cost + maps[nr][nc];
			if (nextCost < dist[nr][nc])
			{
				dist[nr][nc] = nextCost;
				pq.emplace(nextCost, nr, nc);
			}
		}
	}
	return dist[N-1][M-1];
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
	cout << dijkstra();
	
	return 0;
}