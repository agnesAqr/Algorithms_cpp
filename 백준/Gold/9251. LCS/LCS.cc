#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1{}, s2{};
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s1[i-1] == s2[j-1])
            {
                grid[i][j] = grid[i - 1][j - 1] + 1;
            }
            else
            {
                grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
            }
        }
    }
    cout << grid[n][m];

    return 0;
}