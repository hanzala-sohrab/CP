class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int i,l=candies.size(),m=0;
        for (i=0;i<l;++i)
            m=max(m,candies[i]);
        vector<bool>v(l);
        for (i=0;i<l;++i)
            v[i]=candies[i]+extraCandies>=m;
        return v;
    }
};
