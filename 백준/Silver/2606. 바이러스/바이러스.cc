#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int result;

void FindVirusComputer(int startComputer)
{
	visited[startComputer] = true;

	for (auto connectComputer : graph[startComputer])
	{
		if (!visited[connectComputer])
		{
			result++;
			FindVirusComputer(connectComputer);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int computerNum, pairNum;
	cin >> computerNum >> pairNum;
	graph.resize(computerNum+1);
	visited.assign(computerNum+1, false);
	for (int i=0; i<pairNum; ++i)
	{
		int c1, c2;
		cin >> c1 >> c2;
		graph[c1].push_back(c2);
		graph[c2].push_back(c1);
	}
	FindVirusComputer(1);
	cout << result;

	return 0;
}