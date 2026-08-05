import java.util.Arrays;
import java.util.Scanner;

class Solution {
  public static void main(String[] args) {
    try (Scanner sc = new Scanner(System.in)) {
      int t = sc.nextInt();
      while (t-- > 0) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
          a[i] = sc.nextInt();
        }
        int[] b = new int[m];
        for (int i = 0; i < m; ++i) {
          b[i] = sc.nextInt();
        }
        if (n < 2 * m) {
          System.out.println("no");
          continue;
        }
        Arrays.sort(a);
        Arrays.sort(b);
        boolean possible = true;
        for (int i = 0; i < m; ++i) {
          if (!(a[i] <= b[i] && b[i] <= a[n - m + i])) {
            possible = false;
            break;
          }
        }
        System.out.println(possible ? "yes" : "no");
      }
    }
  }
}
