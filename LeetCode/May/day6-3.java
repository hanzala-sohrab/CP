/*
 * Sorting
 * Time complexity - O(n lg n)
 * Space complexity - O(1) or O(n)
*/
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}
