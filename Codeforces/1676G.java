
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

class Main {

    private static int[] explore(List<List<Integer>> adj, int u, boolean[] visited, int[][] counts, String colors) {
        visited[u] = true;
        int[] count = new int[2];
        if (colors.charAt(u) == 'B') {
            ++count[0];
        } else {
            ++count[1];
        }
        for (int v : adj.get(u)) {
            if (!visited[v]) {
                int[] temp = explore(adj, v, visited, counts, colors);
                count[0] += temp[0];
                count[1] += temp[1];
            }
        }
        counts[u] = count;
        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] inp = br.readLine().split("\\s+");
            int[] a = new int[n];
            for (int i = 1; i < n; ++i) {
                a[i] = Integer.parseInt(inp[i - 1]);
            }
            String colors = br.readLine();
            List<List<Integer>> adj = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                adj.add(new ArrayList<>());
            }
            for (int i = 1; i < n; ++i) {
                int parent = a[i] - 1;
                adj.get(parent).add(i);
            }

            boolean[] visited = new boolean[n];
            int[][] counts = new int[n][2];

            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    counts[i] = explore(adj, i, visited, counts, colors);
                }
            }

            int ans = 0;
            for (int i = 0; i < n; ++i) {
                if (counts[i][0] > 0 && counts[i][0] == counts[i][1]) {
                    ++ans;
                }
            }

            System.out.println(ans);
        }
    }
}
