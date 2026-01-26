#include <string>
#include <vector>

using namespace std;

void dfs(int currComputer, int n, const vector<vector<int>>& computers, vector<bool>& visited)
{
    visited[currComputer] = true;
    
    for (int i=0; i<n; i++)
    {
        if (computers[currComputer][i]== 1 && !visited[i])
            dfs(i, n, computers, visited);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    for (int i=0; i<n; i++)
    {
        if (!visited[i])
        {
            answer++;
            dfs(i, n, computers, visited);
        }
    }
    return answer;
}
