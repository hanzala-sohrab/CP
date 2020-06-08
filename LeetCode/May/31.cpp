class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size(), i, j;
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (i = 0; i <= n; ++i)
            dp[0][i] = i;
        for (i = 0; i <= m; ++i)
            dp[i][0] = i;
        for (i = 1; i <= m; ++i)
            for (j = 1; j <= n; ++j)
            {
                if (word1[j - 1] == word2[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        return dp[m][n];
    }
};
