class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> val(N+1,0);
        int m=0,i,l=trust.size(),ans=-1;
        for (i=0;i<l;++i)
            ++val[trust[i][1]];
        for (i=1;i<=N;++i)
            if (val[i]==N-1)
                ans=i;
        for (i=0;i<l;++i)
            if (trust[i][0]==ans)
                ans=-1;
        return ans;
    }
};
