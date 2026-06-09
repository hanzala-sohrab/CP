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
        }
        int q = sc.nextInt();
        int[][] queries = new int[q][2];
        for (int i = 0; i < q; ++i) {
          int l = sc.nextInt();
          int r = sc.nextInt();
          queries[i] = new int[]{l - 1, r - 1};
        }

        int[] prevDiff = new int[n];
        prevDiff[0] = -1;
        for (int i = 1; i < n; ++i) {
          if (a[i] != a[i - 1]) {
            prevDiff[i] = i - 1;
          } else {
            prevDiff[i] = prevDiff[i - 1];
          }
        }

        int[][] ans = new int[q][2];
        int i = 0;
        for (int[] query: queries) {
          int l = query[0];
          int r = query[1];
          if (prevDiff[r] < l || prevDiff[r] > r) {
            ans[i] = new int[]{-1, -1};
            ++i;
            continue;
          }
          ans[i] = new int[]{prevDiff[r] + 1, r + 1};
          ++i;
        }

        for (int[] b: ans) {
          System.out.println(b[0] + " " + b[1]);
        }
      }
    }
  }
}
