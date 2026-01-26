#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(vector<vector<int>>& maps, pair<int, int> start)
{
	int n = maps.size();
	int m = maps[0].size();
	queue<pair<int, int>> q;
	q.push(start);
	maps[start.first][start.second] = 1;

	while(!q.empty())
	{
		auto [currU, currV] = q.front();
		q.pop();

		if (currU == n-1 && currV == m-1)
			break;

		for (int i=0; i<4; ++i)
		{
			int nextU = currU + dx[i];
			int nextV = currV + dy[i];

			if (nextU < 0 || nextV < 0 || nextU >= maps.size() || nextV >= maps[0].size()) continue;

			if (maps[nextU][nextV] != 1) continue;

			q.push({nextU, nextV});
			maps[nextU][nextV] = maps[currU][currV]+1;
		}
	}
	return maps[n-1][m-1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N{}, M{};
	cin >> N >> M;

	vector<vector<int>> maps(N, vector<int>(M, 0));
	for (int i=0; i<N; ++i)
	{
		string s;
		cin >> s;
		for (int j=0; j<M; ++j)
		{
			maps[i][j] = s[j] - '0';
		}
	}
	cout << bfs(maps, {0, 0});

	return 0;
}