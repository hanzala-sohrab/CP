
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
            while (t-- > 0) {
                int n = sc.nextInt();
                int[] a = new int[n];
                for (int i = 0; i < n; i++) {
                    a[i] = sc.nextInt();
                    if (i % 2 == 1) {
                        a[i] *= -1;
                    }
                }
                Map<Long, Boolean> map = new HashMap<>();
                long sum = 0;
                map.put(0L, true);
                boolean found = false;
                for (int i = 0; i < n; ++i) {
                    sum += a[i];
                    if (map.containsKey(sum)) {
                        found = true;
                        break;
                    }
                    map.put(sum, true);
                }
                System.out.println(found ? "YES" : "NO");
            }
        }
    }
}
