#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N{}, M{};
int result{};

void bfs(vector<vector<int>> maps) 
{
    queue<pair<int, int>> q;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (maps[i][j] == 2) {
                q.emplace(i, j);
            }
        }
    }

    while (!q.empty())
    {
        auto [cu, cv] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int nu = cu + dx[k];
            int nv = cv + dy[k];

            if (nu < 0 || nv < 0 || nu >= N || nv >= M) continue;

            if (maps[nu][nv] == 0)
            {
                maps[nu][nv] = 2;
                q.emplace(nu, nv);
            }
        }
    }

    int currentSafe = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (maps[i][j] == 0) {
                currentSafe++;
            }
        }
    }

    result = max(result, currentSafe);
}

void makeWall(int currWall, int start, vector<vector<int>>& maps)
{
	if (currWall == 3)
	{
		bfs(maps);
		return;
	}

	for (int k=start; k<N*M; ++k)
	{
		int r = k/M;
		int c = k%M;

		if (maps[r][c] == 0)
		{
			maps[r][c] = 1;
			makeWall(currWall+1, k+1, maps);
			maps[r][c] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	vector<vector<int>> maps(N, vector<int>(M, 0));
	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<M; ++j)
		{
			cin >> maps[i][j];
		}
	}
	makeWall(0, 0, maps);
	cout << result;

	return 0;
}