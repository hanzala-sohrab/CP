
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String[] parts = br.readLine().trim().split("\\s+");

            int n = Integer.parseInt(parts[0]);
            int m = Integer.parseInt(parts[1]);

            parts = br.readLine().trim().split("\\s+");
            int[] k = new int[n];
            for (int i = 0; i < n; ++i) {
                k[i] = Integer.parseInt(parts[i]);
            }

            parts = br.readLine().trim().split("\\s+");
            int[] c = new int[m];
            for (int i = 0; i < m; ++i) {
                c[i] = Integer.parseInt(parts[i]);
            }

            Arrays.sort(k);

            int j = 0;
            long ans = 0;
            for (int i = n - 1; i >= 0; --i) {
                int a = k[i] - 1;
                if (j < m && c[j] <= c[a]) {
                    ans += c[j];
                    ++j;
                } else {
                    ans += c[a];
                }
            }

            System.out.println(ans);
        }
    }
}
