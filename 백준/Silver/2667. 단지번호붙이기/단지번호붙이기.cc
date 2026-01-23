#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<int> FindHomeGroup(vector<vector<int>>& grid)
{
	int n = grid.size();
	int currGroupName = 1;
	vector<int> result;

	for (int r=0; r<n; ++r)
	{
		for (int c=0; c<n; ++c)
		{
			if (grid[r][c] != 1)
				continue;
			
			queue<pair<int, int>> q{};
			q.emplace(r, c);
			currGroupName++;
			grid[r][c] = currGroupName;
			int count = 1;

			while(!q.empty())
			{
				auto currHomeCoordinate = q.front();
				int currRow = currHomeCoordinate.first;
				int currCol = currHomeCoordinate.second;
				q.pop();

				for (int i=0; i<4; ++i)
				{
					int nextRow = currRow + dx[i];
					int nextCol = currCol + dy[i];

					if (nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= n)
						continue;
					
					if (grid[nextRow][nextCol] == 1)
					{
						q.emplace(nextRow, nextCol);
						grid[nextRow][nextCol] = currGroupName;
						count++;
					}
				}
			}
			result.push_back(count);	
		}
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N{};
	cin >> N;
	
	vector<vector<int>> grid(N, vector<int>(N, 0));
	for (int i=0; i<N; ++i)
	{
		string row;
		cin >> row;
		for (int j=0; j<N; ++j)
		{
			grid[i][j] = row[j] - '0';
		}
	}
	auto groupVector = FindHomeGroup(grid);
	cout << groupVector.size() << "\n";

	sort(groupVector.begin(), groupVector.end());
	for (int homeNum : groupVector)
		cout << homeNum << "\n";

	return 0;
}