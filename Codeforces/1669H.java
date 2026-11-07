
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();

            while (t-- > 0) {
                int n = sc.nextInt();
                int k = sc.nextInt();

                int[] a = new int[n];

                for (int i = 0; i < n; i++) {
                    a[i] = sc.nextInt();
                }

                int ans = 0;

                for (int bit = 30; bit >= 0; bit--) {
                    int unset = 0;

                    for (int num : a) {
                        if ((num & (1 << bit)) == 0) {
                            unset++;
                        }
                    }

                    if (unset <= k) {
                        ans |= (1 << bit);
                        k -= unset;
                    }
                }

                System.out.println(ans);
            }
        }
    }
}
