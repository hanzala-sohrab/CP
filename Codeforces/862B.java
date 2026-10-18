
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        List<Set<Integer>> adj = new ArrayList<>();

        // Initialize adjacency lists
        for (int i = 0; i < n; ++i) {
            adj.add(new HashSet<>());
        }

        // Read n edges
        for (int i = 1; i < n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        Queue<Integer> q = new ArrayDeque<>();
        q.offer(0);
        int[] color = new int[n];
        boolean[] visited = new boolean[n];
        Arrays.fill(color, -1);
        color[0] = 0;
        visited[0] = true;

        long color0 = 1;
        long color1 = 0;

        while (!q.isEmpty()) {
            int node = q.poll();
            for (int nbr : adj.get(node)) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    color[nbr] = 1 - color[node];
                    if (color[nbr] == 0) {
                        color0++;
                    } else {
                        color1++;
                    }
                    q.offer(nbr);
                }
            }
        }

        long ans = color0 * color1 - (n - 1);
        System.out.println(ans);
    }
}
