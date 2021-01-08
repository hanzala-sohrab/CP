class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), i, j, r, c, z = 0;
        vector<int> rows, cols;
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                if (matrix[i][j] == 0)
                    rows.push_back(i), cols.push_back(j);
        for (i = 0; i < rows.size(); ++i)
            for (j = 0; j < n; ++j)
                matrix[rows[i]][j] = 0;
        for (i = 0; i < cols.size(); ++i)
            for (j = 0; j < m; ++j)
                matrix[j][cols[i]] = 0;
    }
};
