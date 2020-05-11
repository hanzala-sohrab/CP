// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1))
            return 1;
        long l = 1, r = n, m;
        while (l <= r) {
            m = (r + l) / 2;
            bool a, b, c;
            a = isBadVersion(m);
            if (1 < m)
                b = isBadVersion(m - 1);
            if (m + 1 <= n)
                c = isBadVersion(m + 1);
            if (m > 1 && a && !b)
                return m;
            if (m + 1 <= n && !a && c)
                return m + 1;
            if (m + 1 <= n && a && c)
                r = m;
            if (1 < m && !a && !b)
                l = m;
        }
        return 1;
    }
};
