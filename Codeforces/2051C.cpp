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
        int i, j, k, n, m;
        I >> n >> m >> k;
        V<int> a(m);
        V<bool> b(n, false);
        F(i, 0, m - 1)
        {
            I >> a[i];
            --a[i];
        }
        F(i, 0, k - 1)
        {
            I >> j;
            --j;
            b[j] = true;
        }

        F(i, 0, m - 1)
        {
            O << (k == n ? 1 : (k == n - 1 ? !b[a[i]] : 0));
        }

        O << '\n';
    }
    return 0;
}
