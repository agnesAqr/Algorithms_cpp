#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int RipeTomatoes(queue<pair<int, int>>& q, vector<vector<int>>& tomatoBox, int& unripeCount)
{
	int row = tomatoBox.size();
	int col = tomatoBox[0].size();
	int days = 0;

	while (!q.empty())
	{
		auto [currU, currV] = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int nextU = currU + dx[k];
			int nextV = currV + dy[k];

			if (nextU < 0 || nextV < 0 || nextU >= row || nextV >= col)
				continue;

			if (tomatoBox[nextU][nextV] == 0)
			{
				unripeCount--;
				tomatoBox[nextU][nextV] = tomatoBox[currU][currV] + 1;
				q.push({nextU, nextV});
				days = tomatoBox[nextU][nextV];
			}
		}
	}
	return (unripeCount == 0 ? days-1 : -1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M{}, N{};
	cin >> M >> N;

	vector<vector<int>> tomatoBox(N, vector<int>(M, 0));
	
	queue<pair<int, int>> q;
	int unripeCount = 0;
	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<M; ++j)
		{
			cin >> tomatoBox[i][j];

			if (tomatoBox[i][j] == 1)
				q.push({i, j});
			else if (tomatoBox[i][j] == 0)
				unripeCount++;
		}
	}
	if (unripeCount == 0)
	{
		cout << 0;
		return 0;
	}

	cout << RipeTomatoes(q, tomatoBox, unripeCount);
	return 0;
}