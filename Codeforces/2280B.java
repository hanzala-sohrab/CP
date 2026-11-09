
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            System.out.printf("? %d %d\n", 1, n);
            int ones = Integer.parseInt(br.readLine());
            if (ones == n || ones == 0) {
                System.out.println("! NO");
                continue;
            }

            System.out.printf("? %d %d\n", 1, ones);
            int cnt = Integer.parseInt(br.readLine());
            if (cnt == ones) {
                System.out.println("! NO");
                continue;
            }
            System.out.println("! YES");
        }
        System.out.print(sb);
    }
}
