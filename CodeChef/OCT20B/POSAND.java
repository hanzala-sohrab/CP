import java.util.Scanner;

class POSAND {
    public static boolean isPowerOfTwo(int N) {
        if (N % 2 == 1)
            return false;
        int AND = N & (N - 1);
        if (AND == 0)
            return true;
        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0)
        {
            final int N = sc.nextInt();
            int i;
            if (N == 1)
            {
                System.out.println(1);
                continue;
            }
            if (isPowerOfTwo(N))
            {
                System.out.println(-1);
                continue;
            }
            // int foo[] = new int[N];
            // foo[0] = 2;
            // foo[1] = 3;
            // foo[2] = 1;
            System.out.print("2 3 1 ");
            for (i = 3; i < N; ++i)
            {
                if (isPowerOfTwo(i + 1))
                {
                    // foo[i] = i + 2;
                    // foo[i + 1] = i + 1;
                    // System.out.print(foo[i] + " " + foo[i + 1] + " ");
                    System.out.print(i + 2 + " " + (i + 1) + " ");
                    ++i;
                }
                else
                {
                    // foo[i] = i + 1;
                    // System.out.print(foo[i] + " ");
                    System.out.print(i + 1 + " ");
                }
            }
            System.out.println();
        }
        sc.close();
    }
}
