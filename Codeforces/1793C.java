import java.util.Scanner;
class Solution {
  public static void main(String[] args) {
    try (Scanner sc = new Scanner(System.in)) {
      int t = sc.nextInt();
      while (t-- > 0) {
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
          a[i] = sc.nextInt();
        }
        int l = 0;
        int r = n - 1;
        int m = 1;
        int M = n;
        boolean found = false;
        while (l + 1 < r) {
          if (a[l] != m && a[l] != M && a[r] != m && a[r] != M) {
            found = true;
            break;
          }
          if (a[l] == m) {
            ++l;
            ++m;
          } else if (a[l] == M) {
            ++l;
            --M;
          }

          if (a[r] == m) {
            --r;
            ++m;
          } else if (a[r] == M) {
            --r;
            --M;
          }
        }
        if (!found) {
          System.out.println(-1);
          continue;
        }
        System.out.println(l + 1 + " " + (r + 1));
      }
    }
  }
}
