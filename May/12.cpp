class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=nums.size(),l=0,r=s-1,m;
        if (s==1)
            return nums[0];
        if (nums[r]!=nums[r-1])
            return nums[r];
        if (nums[0]!=nums[1])
            return nums[0];
        while (l<r)
        {
            m=(r+l)/2;
            if (m%2==0)
            {
                if (nums[m]==nums[m+1])
                    l=m+1;
                else if (m>0 && nums[m]==nums[m-1])
                    r=m-1;
                else if (m>0 && nums[m]!=nums[m-1] && m+1<s && nums[m]!=nums[m+1])
                    return nums[m];
            }
            else
            {
                if (nums[m]==nums[m-1])
                    l=m;
                else if (m+1<s && nums[m]==nums[m+1])
                    r=m;
                else if (m>0 && nums[m]!=nums[m-1] && m+1<s && nums[m]!=nums[m+1])
                    return nums[m];
            }
        }
        return 0;
    }
};
