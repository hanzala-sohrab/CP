#include <bits/stdc++.h>
using namespace std;
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define all(x) x.begin(), x.end()

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        int i, b, m, n;
        I >> n >> m;
        V<int> a(n);
        F(i, 0, n - 1)
        {
            I >> a[i];
        }
        I >> b;

        a[0] = min(a[0], b - a[0]);

        F(i, 1, n - 1)
        {
            int j = min(a[i], b - a[i]);
            int k = max(a[i], b - a[i]);
            if (j >= a[i - 1])
                a[i] = j;
            else if (k < a[i - 1])
                break;
            else
                a[i] = k;
        }

        O << (i == n and is_sorted(all(a)) ? "yes" : "no") << '\n';
    }
    return 0;
}
