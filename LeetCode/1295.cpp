class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int a=0,i,n=nums.size();
        for (i=0;i<n;++i)
            if (!(to_string(nums[i]).size()&1))
                ++a;
        return a;
    }
};
