class Solution {
public:
    string removeKdigits(string num, int k) {       
        int i,j,l=num.size(),l1=l;
        if (l==1)
            if (k==0)
                return num;
            else
                return "0";
        if (k==l)
            return "0";
        string s=num,s1=s;
        sort(s1.begin(),s1.end());
        if (s1==s)
            return s.substr(0,l-k);
        for (i=0;i<k;++i,--l1)
        {
            for (j=0;j<l1-1;++j)
            {
                if (s[j]>s[j+1])
                {
                    s=s.substr(0,j)+s.substr(j+1);
                    break;
                }
            }
        }
        s1=s;
        sort(s1.begin(),s1.end());
        if (s1==s)
            s=s.substr(0,l-k);
        if (s[0]=='0')
        {
            for (i=0,l=s.size();i<l;++i)
            {
                if (s[i]!='0')
                    break;
            }
            s=s.substr(i);
        }
        if (s.size()==0)
            s="0";
        return s;
    }
};
