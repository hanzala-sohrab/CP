class Solution {
public:
    bool found(vector<int>cp,vector<int>c) {
        for (int i=0;i<26;++i)
            if (cp[i]!=c[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int ls=s.size(),lp=p.size(),i;
        vector<int> a, cp(26,0), c(26,0);
        if (lp>ls)
            return a;
        for (i=0;i<lp;++i)
        {
            cp[p[i]-97]++;
            c[s[i]-97]++;
        }
        for (i=lp;i<ls;++i)
        {
            if (found(cp,c))
                a.push_back(i-lp);
            c[s[i]-97]++;
            c[s[i-lp]-97]--;
        }
        if (found(cp,c))
            a.push_back(ls-lp);
        return a;
    }
};
