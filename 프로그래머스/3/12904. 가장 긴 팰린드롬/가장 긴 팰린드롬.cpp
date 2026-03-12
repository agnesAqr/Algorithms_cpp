#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int maxLength{};
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i=n-1; i>=0; --i)
    {
        for (int j=i; j<n; ++j)
        {
            if (i == j)
            {
                dp[i][j] = true;
                maxLength = max(1, maxLength);
                continue;
            }
            if (j-i == 1)
            {
                dp[i][j] = (s[i] == s[j]);
                if (dp[i][j])
                    maxLength = max(2, maxLength);
            }
            if (s[i] == s[j] && dp[i+1][j-1])
            {
                dp[i][j] = true;
                maxLength = max(j-i+1, maxLength);
            }
        }
    }
    return maxLength;
}