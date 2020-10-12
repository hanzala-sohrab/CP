import java.util.Arrays;
import java.util.Scanner;

class REPLESX {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0)
        {
            final int N, p, k;
            final long X;
            N = sc.nextInt();
            X = sc.nextLong();
            p = sc.nextInt();
            k = sc.nextInt();

            long A[] = new long[N], t = (long)(1e9 + 7), ans = -1;
            int i, j = 0;

            boolean found_X = false;

            for (i = 0; i < N; ++i)
            {
                A[i] = sc.nextInt();
                if (A[i] == X)
                    found_X = true;
            }

            Arrays.sort(A);
            
            if (!found_X)
            {
                A[k - 1] = X;
                Arrays.sort(A);
                j = 1;
            }
            
            if (X == A[p - 1])
                ans = j;
            else
            {
                for (i = 0; i < N; ++i)
                    if (X == A[i])
                        t = Math.min(Math.abs(p - i - 1), t);
                if ((X <= A[p - 1] && p <= k) || (X >= A[p - 1] && p >= k))
                    ans = t + j;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}