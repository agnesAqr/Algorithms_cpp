class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i=1; i<=n; ++i)  // length of s
        {
            for (int j=0; j<i; ++j)  // index of s
            {
                if (dp[j] && dict.count(s.substr(j, i-j)) > 0)  // s[j:i]
                {
                    dp[i] = true;
                    break;
                }
            }
