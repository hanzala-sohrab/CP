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
        int[] prevDiff = new int[n];
        prevDiff[0] = -1;
        for (int i = 1; i < n; ++i) {
          if (a[i] != a[i - 1]) {
            prevDiff[i] = i - 1;
          } else {
            prevDiff[i] = prevDiff[i - 1];
          }
        }
        
        int q = sc.nextInt();
        for (int k = 0; k < q; ++k) {
          int l = sc.nextInt() - 1;
          int r = sc.nextInt() - 1;
          int i = -1;
          int j = -1;
          if (l <= prevDiff[r] && prevDiff[r] <= r) {
            i = prevDiff[r] + 1;
            j = r + 1;
          }
          System.out.println(i + " " + j);
        }
      }
    }
  }
}
