#include <bits/stdc++.h>
using namespace std;

int dx[2] = {1, -1};
int visited[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N{}, K{};
	cin >> N >> K;

	queue<int> q;
	q.emplace(N);
	visited[N] = 1;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		if (curr == K)
		{
			cout << visited[curr] - 1;
			break;
		}

		for (int i=0; i<3; ++i)
		{
			int next = (i != 2) ? curr + dx[i] : 2*curr;
			if (next < 0 || next > 100000 || visited[next] > 0)
				continue;

			q.emplace(next);
			visited[next] = visited[curr] + 1;
		}
	}
	return 0;
}