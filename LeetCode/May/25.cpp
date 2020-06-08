class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n=A.size(),m=B.size(),i,j;
        if (n==1&&m==1)
            if (A[0]==B[0])
                return 1;
            else
                return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (i=1;i<=m;++i)
        {
            for (j=1;j<=n;++j)
            {
                if (A[j-1]==B[i-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                cout<<dp[i][j]<<' ';
            }
            cout<<'\n';
        }
        return dp[m][n];
    }
};
