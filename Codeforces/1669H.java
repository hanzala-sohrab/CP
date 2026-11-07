
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            if (!sc.hasNextInt()) {
                return;
            }
            int t = sc.nextInt();

            while (t-- > 0) {
                int n = sc.nextInt();
                int k = sc.nextInt();
                List<BitSet> bitSets = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    long el = sc.nextLong();
                    bitSets.add(BitSet.valueOf(new long[]{el}));
                }

                for (int i = 30; i >= 0; --i) {
                    int unset = 0;
                    for (BitSet bs : bitSets) {
                        if (!bs.get(i)) {
                            ++unset;
                        }
                    }

                    if (unset <= k) {
                        for (BitSet bs : bitSets) {
                            if (!bs.get(i) && k > 0) {
                                bs.set(i);
                                --k;
                            }
                        }
                    }
                }

                List<Long> b = new ArrayList<>(n);
                for (BitSet bs : bitSets) {
                    long val = bs.isEmpty() ? 0 : bs.toLongArray()[0];
                    b.add(val);
                }

                long and = b.get(0);
                for (int i = 1; i < n; ++i) {
                    long el = b.get(i);
                    and &= el;
                }

                System.out.println(and);
            }
        }
    }
}
