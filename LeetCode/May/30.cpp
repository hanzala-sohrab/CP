class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int i, l = points.size();
        long d = 0;
        vector<vector<int>> ans(K);
        vector<pair<long, vector<int>>> p(l);
        for (i = 0; i < l; ++i)
        {
            d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            p[i]={d, points[i]};
        }
        sort(p.begin(), p.end());
        for (i=0;i<K;++i)
            ans[i] = p[i].second;
        return ans;
    }
};
