import java.util.*;

public class Solution {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
			if (!sc.hasNextInt()) return;
			int t = sc.nextInt();

			while (t-- > 0) {
			    int n = sc.nextInt();
			    int[] p = new int[n];
			    int[] a = new int[n];

			    // Store original positions: pos[value] = original_index
			    int[] pos = new int[n + 1];
			    for (int i = 0; i < n; i++) {
			        p[i] = sc.nextInt();
			        pos[p[i]] = i;
			    }

			    for (int i = 0; i < n; i++) {
			        a[i] = sc.nextInt();
			    }

			    if (isPossible(n, a, pos)) {
			        System.out.println("YES");
			    } else {
			        System.out.println("NO");
			    }
			}
		}
    }

    private static boolean isPossible(int n, int[] a, int[] pos) {
        for (int i = 0; i < n - 1; i++) {
            // The relative order of elements from p must be preserved in a
            if (pos[a[i]] > pos[a[i + 1]]) {
                return false;
            }
        }
        return true;
    }
}
