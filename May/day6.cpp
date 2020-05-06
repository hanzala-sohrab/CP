class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> M;
        int i, n = nums.size();
        for (int j:nums) {
            ++M[j];
            if (M[j]>n/2)
                return j;
        }
        return 0;
    }
};
