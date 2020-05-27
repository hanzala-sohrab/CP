class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int i, n = nums.size(), m = 0, e = 0, s = 0;
        unordered_map<int, int> M;
        // int M[100000] = {-1};
        for (i = 0; i < n; ++i)
            nums[i] = nums[i] ? 1 : -1;
        for (i = 0; i < n; ++i) {
            s += nums[i];
            if (s == 0) {
                m = i + 1;
                e = i;
            }
            // if (M[s + n] != -1) {
            //     if (m < i - M[s + n]) {
            //         m = i - M[s + n];
            //         e = i;
            //     }
            // }
            // else
            //     M[s + n] = i;
            if (M.find(s + n) != M.end()) {
                if (m < i - M[s + n]) {
                    m = i - M[s + n];
                    e = i;
                }
            }
            else
                M[s + n] = i;
        }
        return m;
    }
};
