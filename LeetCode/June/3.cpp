struct C {
    int a, b, d;
};
class Solution {
public:
    static bool foo(C x, C y) {
        return x.d < y.d;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int i, l = costs.size(), s = 0, s1 = 0, a = 0, b = 0;
        vector<C> c(l);
        for (i = 0; i < l; ++i)
        {
            c[i].a = costs[i][0];
            c[i].b = costs[i][1];
            c[i].d = c[i].a - c[i].b;
        }
        sort(c.begin(), c.end(), foo);
        for (i = 0; i < l / 2; ++i)
            s += c[i].a;
        for (i = l / 2; i < l; ++i)
            s += c[i].b;
        return s;
    }
};
