class Solution {
public:
    vector<int> countBits(int num) {
        int i;
        vector<int>dp(num+1);
        dp[0]=0;
        if (num>0)
            dp[1]=1;
        if (num>1)
            dp[2]=1;
        for (i=3;i<=num;++i)
        {
            dp[i]=dp[i/2];
            if (i&1)
                ++dp[i];
        }
        return dp;
    }
};
