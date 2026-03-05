#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int connectedNodeCount;

void dfs(int start)
{
    visited[start] = true;
    connectedNodeCount++;
    for (int nextComputer : adj[start])
    {
        if (visited[nextComputer]) continue;
        dfs(nextComputer);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    adj.assign(n, vector<int>());
    visited.assign(n, false);
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            if (i == j || computers[i][j] == 0) continue;
            adj[i].push_back(j);
        }
    }
    
    for (int i=0; i<n; ++i)
    {
        if (visited[i]) continue;
        
        connectedNodeCount = 0;
        dfs(i);
        if (connectedNodeCount > 0)
            answer++;
    }
    
    
    return answer;
}