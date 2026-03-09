#include <bits/stdc++.h>
using namespace std;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int totalLand{};

void dfs(int r, int c, int group, vector<vector<int>>& land)
{
    land[r][c] = group;
    totalLand++;
    
    for (int i=0; i<4; ++i)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (nr < 0 || nc < 0 || nr >= land.size() || nc >= land[0].size() || land[nr][nc] != 1) continue;
        
        dfs(nr, nc, group, land);
    }
}

int solution(vector<vector<int>> land) {
    int currGroup = 2;
    int n = land.size();
    int m = land[0].size();
    vector<int> groupLand(n*m);
    
    for (int i = 0; i<n; ++i)
    {
        for (int j=0; j<m; ++j)
        {
            if (land[i][j] == 1)
            {
                dfs(i, j, currGroup, land);
                groupLand[currGroup] = totalLand;
                currGroup++;
                totalLand = 0;
            }
        }
    }
    
    int total{};
    for (int col=0; col<m; ++col)
    {
        vector<int> groups;
        groups.reserve(n);
        for (int row=0; row<n; ++row)
        {
            int groupIdx = land[row][col];
            if ((find(groups.begin(), groups.end(), groupIdx) == groups.end()) && groupIdx > 1)
            {
                groups.push_back(groupIdx);
            }
        }
        int currTotal{};
        for (int i=0; i<groups.size(); ++i)
        {
            currTotal += groupLand[groups[i]];
        }
        total = max(total, currTotal);
        groups.clear();
    }
    
    return total;
}