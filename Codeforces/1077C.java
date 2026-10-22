
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        String[] inp = br.readLine().split("\\s+");
        int[] a = new int[n];
        long sum = 0;
        Map<Long, Set<Integer>> map = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(inp[i]);
            sum += a[i];
            map.computeIfAbsent((long) a[i], key -> new HashSet<>()).add(i);
        }
        Set<Integer> res = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            int el = a[i];
            long r = sum - 2 * el;
            if (map.containsKey(r)) {
                for (int idx : map.get(r)) {
                    if (idx == i) {
                        continue;
                    }
                    res.add(idx + 1);
                }
            }
        }

        System.out.println(res.size());
        for (int idx : res) {
            System.out.print(idx + " ");
        }
        System.out.println();
    }
}
