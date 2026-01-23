class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int numIslands(vector<vector<char>>& grid) {
        int result{};

        for (int i=0; i<grid.size(); ++i)
        {
            for (int j=0; j<grid[0].size(); ++j)
            {
                if (grid[i][j] != '1')
                    continue;

                queue<pair<int, int>> q{};
                q.emplace(i, j);
                grid[i][j] = '0';

                while (!q.empty())
                {
                    auto currLandCoordinate = q.front();
                    q.pop();
                    
                    int currRow = currLandCoordinate.first;
                    int currCol = currLandCoordinate.second;
                    
                    for (int k=0; k<4; ++k)
                    {
                        int nextRow = currRow + dx[k];
                        int nextCol = currCol + dy[k];
                        if (nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size())
                            continue;
                        if (grid[nextRow][nextCol] == '1')
                        {
                            q.emplace(nextRow, nextCol);
                            grid[nextRow][nextCol] = '0';
                        }
                            
                    }
                }
                result++;
            }
        }
        return result;
    }
};