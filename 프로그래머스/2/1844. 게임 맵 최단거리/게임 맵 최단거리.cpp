#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(vector<vector<int>>& maps)
{
    int r = maps.size();
    int c = maps[0].size();
    
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    maps[0][0] = 1;
    
    while(!q.empty())
    {
        auto currWay = q.front();
        q.pop();
        
        int currRow = currWay.first;
        int currCol = currWay.second;
        if (currRow == r-1 && currCol == c-1)
            return maps[currRow][currCol];
        
        for (int i=0; i<4; ++i)
        {
            int nextRow = currRow + dx[i];
            int nextCol = currCol + dy[i];
        
            if (nextRow >= 0 && nextRow < r && nextCol >= 0 && nextCol < c && maps[nextRow][nextCol])
            {
                if (maps[nextRow][nextCol] != 1)
                    continue;
                
                maps[nextRow][nextCol] = maps[currRow][currCol] + 1;
                q.emplace(nextRow, nextCol);
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    return bfs(maps);
}