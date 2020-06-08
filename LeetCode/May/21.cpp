class Solution {
public:
    int n,m,cnt=0;
    int mat[302][302],dp[302][302];
    int  dfs(int i,int j)
    {
        if(i>=n||j>=m)
            return 0;
        if(mat[i][j]==0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int p=dfs(i+1,j);
        int q=dfs(i,j+1);
        int r=dfs(i+1,j+1);
        return dp[i][j]=1+min(p,min(q,r));
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        for(int i=0;i<matrix.size();i++)
        {
            
            for(int j=0;j<matrix[i].size();j++)
            {
               mat[i][j]=matrix[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        n=matrix.size();
        m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                   ans+= dfs(i,j);
                }
            }
        }
        return ans;
    }
};
