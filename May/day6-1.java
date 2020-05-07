/*
    Time complexity : O(n)

    We iterate over nums once and make a constant time HashMap insertion on each iteration. Therefore, the algorithm runs in O(n) time.

    Space complexity : O(n)

    At most, the HashMap can contain n−⌊n / 2⌋ \lfloor \dfrac{n}{2} \rfloorn−⌊2n⌋ associations, so it occupies O(n)O(n)O(n) space. This is because an arbitrary array of length nnn can contain nnn distinct values, but nums is guaranteed to contain a majority element, which will occupy (at minimum) ⌊n2⌋+1\lfloor \dfrac{n}{2} \rfloor + 1⌊2n⌋+1 array indices. Therefore, n−(⌊n2⌋+1)n - (\lfloor \dfrac{n}{2} \rfloor + 1)n−(⌊2n⌋+1) indices can be occupied by distinct, non-majority elements (plus 1 for the majority element itself), leaving us with (at most) n−⌊n2⌋n - \lfloor \dfrac{n}{2} \rfloorn−⌊2n⌋ distinct elements.

*/
class Solution {
    private Map<Integer, Integer> countNums(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<Integer, Integer>();
        for (int num : nums) {
            if (!counts.containsKey(num)) {
                counts.put(num, 1);
            }
            else {
                counts.put(num, counts.get(num)+1);
            }
        }
        return counts;
    }

    public int majorityElement(int[] nums) {
        Map<Integer, Integer> counts = countNums(nums);

        Map.Entry<Integer, Integer> majorityEntry = null;
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            if (majorityEntry == null || entry.getValue() > majorityEntry.getValue()) {
                majorityEntry = entry;
            }
        }

        return majorityEntry.getKey();
    }
}
