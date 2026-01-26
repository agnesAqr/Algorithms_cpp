#include <bits/stdc++.h>
using namespace std;

bool visited[205];

void bfs(const vector<vector<int>>& computers, int startNode)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    
    while(!q.empty())
    {
        int currComputer = q.front();
        q.pop();
        
        for (int i=0; i<computers.size(); ++i)
        {
            if (currComputer == i || computers[currComputer][i] == 0 || visited[i]) continue;
            
            visited[i] = true;
            q.push(i);
        }
    }
}
    
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i=0; i<n; ++i)
    {
        if (!visited[i])
        {
            bfs(computers, i);
            answer++;
        }
    }
    return answer;
}