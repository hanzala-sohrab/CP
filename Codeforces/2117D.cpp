#include <bits/stdc++.h>
using namespace std;
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        int i, n;
        I >> n;
        V<int> a(n);
        F(i, 0, n - 1)
        {
            I >> a[i];
        }

        int x = (2 * a[0] - a[1]) / (n + 1);
        int z = a[1] - a[0];
        int y = x + z;

        if (x * (n + 1) != (2 * a[0] - a[1]) or x < 0 or y < 0)
        {
            O << "NO\n";
            continue;
        }

        F(i, 1, n - 1)
        {
            if ((a[i] - a[0]) % i != 0 or (a[i] - a[0]) / i != z)
                break;
        }

        O << (i == n ? "YES\n" : "NO\n");
    }
    return 0;
}
