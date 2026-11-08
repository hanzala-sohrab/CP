
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

            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            int maxXor = x + y;

            for (int bit = (1 << 30); bit >= 1; bit >>= 1) {
                if ((maxXor & bit) != 0 && x >= bit) {
                    x -= bit;
                }
            }

            sb.append(maxXor).append(" ").append(x).append("\n");
        }

        System.out.print(sb);
    }
}
