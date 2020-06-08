class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>>p(256,{0,0});
        int j,i,l=s.size();
        for (i=0;i<l;++i)
        {
            p[s[i]].first++;
            p[s[i]].second=s[i];
        }
        sort(p.begin(),p.end());
        string o;
        for (i=255;i>=0;--i)
        {
            if (p[i].first)
            {
                for (j=0;j<p[i].first;++j)
                    o+=p[i].second;
            }
        }
        return o;
    }
};
