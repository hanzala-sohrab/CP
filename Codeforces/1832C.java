import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
class Solution {
  public static void main(String[] args) {
    try (Scanner sc = new Scanner(System.in)) {
      int t = sc.nextInt();
      while (t-- > 0) {
        int n = sc.nextInt();
        int res = 2;
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
          a[i] = sc.nextInt();
        }
        List<Integer> list = new ArrayList<>();
        list.add(a[0]);
        for (int i = 1; i < n; ++i) {
          if (a[i] != a[i - 1]) {
            list.add(a[i]);
          }
        }
        n = list.size();
        if (n == 1) {
          System.out.println(1);
          continue;
        }
        int[] b = list.stream().mapToInt(Integer::intValue).toArray();
        for (int i = 1; i < n - 1; ++i) {
          if (b[i - 1] < b[i] && b[i] > b[i + 1]) {
            ++res;
          } else if (b[i - 1] > b[i] && b[i] < b[i + 1]) {
            ++res;
          }
        }
        System.out.println(res);
      }
    }
  }
}
