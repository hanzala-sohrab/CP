class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.length();
        int n=t.length();
        int s1=0;
        int t1=0;
        while(s1<m&&t1<n)
        {
            if(s[s1]==t[t1])
                s1++;
            t1++;
        }
        return s1==m;
    }
};