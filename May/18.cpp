class Solution {
public:
    bool found(int *c1,int *c2)
    {
        for (int i=0;i<26;++i)
            if (c1[i]!=c2[i])
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int i,l1=s1.size(),l2=s2.size();
        if (l1>l2)
            return false;
        int c1[26]={0},c2[26]={0};
        for (i=0;i<l1;++i)
        {
            c1[s1[i]-97]++;
            c2[s2[i]-97]++;
        }
        for (i=l1;i<l2;++i)
        {
            if (found(c1,c2))
                return true;
            c2[s2[i]-97]++;
            c2[s2[i-l1]-97]--;
        }
        if (found(c1,c2))
            return true;
        return false;
    }
};
