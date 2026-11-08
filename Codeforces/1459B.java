
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            int m = n / 2;
            int ans;
            if (n % 2 == 0) {
                ans = (m + 1) * (m + 1);
            } else {
                ans = 2 * (m + 2) * (m + 1);
            }
            System.out.println(ans);
        }
    }
}
