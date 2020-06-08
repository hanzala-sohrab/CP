class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        vector<vector<int>> c = coordinates;
        if (n==2)
            return true;
        for (int i=0;i<n-1;++i)
            if ((c[i][1]-c[0][1])*(c[1][0]-c[0][0])!=(c[1][1]-c[0][1])*(c[i][0]-c[0][0]))
                return false;
        return true;
    }
};
