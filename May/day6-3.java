/*
    Time complexity : O(nlgn)

    Sorting the array costs O(nlgn) time in Python and Java, so it dominates the overall runtime.

    Space complexity : O(1) or O(n)

    We sorted nums in place here - if that is not allowed, then we must spend linear additional space on a copy of nums and sort the copy instead.
*/
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}
