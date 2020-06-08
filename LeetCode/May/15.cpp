class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int i,s=A[0],l=A.size(),m=INT_MIN,m1=INT_MIN,dp[l],cn=0;
        if (l==1)
            return A[0];
        dp[0]=A[0];
        if (A[0]<0)
            ++cn;
        A[0]*=-1;
        for (i=1;i<l;++i)
        {
            dp[i]=A[i]+max(0,dp[i-1]);
            m1=max(m1,dp[i]);
            if (A[i]<0)
                ++cn;
            s+=A[i];
            A[i]*=-1;
        }
        dp[0]=A[0];
        for (i=1;i<l;++i)
        {
            dp[i]=A[i]+max(0,dp[i-1]);
            m=max(m,dp[i]);
        }
        if (cn==l)
            return m1;
        return max(m1,s+m);
    }
};
