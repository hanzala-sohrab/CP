
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[][] caves = new int[n][2];

            for (int i = 0; i < n; ++i) {
                String[] inp = br.readLine().trim().split("\\s+");
                int k = Integer.parseInt(inp[0]);

                int need = 0;

                for (int j = 0; j < k; ++j) {
                    int el = Integer.parseInt(inp[j + 1]);
                    need = Math.max(need, el - j + 1);
                }

                caves[i] = new int[]{need, k};
            }

            Arrays.sort(caves, (a, b) -> Integer.compare(a[0], b[0]));

            int ans = 0;
            int gained = 0;

            for (int[] cave : caves) {
                ans = Math.max(ans, cave[0] - gained);
                gained += cave[1];
            }

            System.out.println(ans);
        }
    }
}
