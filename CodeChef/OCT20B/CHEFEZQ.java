import java.util.Scanner;

class CHEFEZQ {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0)
        {
            final int n, k;
            int i;
            long nod = 1, f = 0;
            n = sc.nextInt();
            k = sc.nextInt();
            long Q[] = new long[n];
            for (i = 0; i < n; ++i)
                Q[i] = sc.nextLong();
            for (i = 0; i < n; ++i)
                if (Q[i] < k)
                {
                    f = 0;
                    break;
                }
                else
                {
                    f = Q[i] - k;
                    Q[i] = k;
                    if (i + 1 < n)
                        Q[i + 1] += f;
                    ++nod;
                }
            nod += f / k;
            System.out.println(nod);
        }
        sc.close();
    }
}