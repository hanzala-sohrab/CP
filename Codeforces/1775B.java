
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            if (!sc.hasNextInt()) {
                return;
            }
            int t = sc.nextInt();

            while (t-- > 0) {
                Map<Integer, Integer> map = new HashMap<>();
                int n = sc.nextInt();
                List<List<Integer>> nums = new ArrayList<>(n);
                for (int i = 0; i < n; i++) {
                    int c = sc.nextInt();
                    List<Integer> positions = new ArrayList<>(c);
                    for (int j = 0; j < c; ++j) {
                        int k = sc.nextInt();
                        map.put(k, map.getOrDefault(k, 0) + 1);
                        positions.add(k);
                    }
                    nums.add(positions);
                }
                boolean possible = false;
                for (List<Integer> list : nums) {
                    possible = true;
                    for (int i : list) {
                        if (map.get(i) < 2) {
                            possible = false;
                            break;
                        }
                    }

					if (possible) {
						break;
					}
                }

                System.out.println(possible ? "yes" : "no");
            }
        }
    }
}
