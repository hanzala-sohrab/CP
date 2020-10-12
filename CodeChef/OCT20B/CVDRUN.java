// import java.io.InputStreamReader;
// import java.io.BufferedReader;
// import java.io.IOException;
import java.util.Scanner;

class CVDRUN {
    public static void main(String[] args) {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // int t = Integer.parseInt(br.readLine());
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0)
        {
            int N, K, X, Y, f = 0, curr;
            N = sc.nextInt();
            K = sc.nextInt();
            X = sc.nextInt();
            Y = sc.nextInt();
            curr = X;
            if (Y == X)
            {
                System.out.println("YES");
                continue;
            }
            while (true)
            {
                if (f == 2)
                    break;
                if (Y == (curr + K) % N)
                    break;
                if (curr == X)
                    ++f;
                curr = (curr + K) % N;
            }
            if (f == 2)
                System.out.println("NO");
            else
                System.out.println("YES");
        }
        sc.close();
    }
}