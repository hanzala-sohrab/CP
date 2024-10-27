#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, q, i, j, k, l;
    I >> t;
    while (t--)
    {
        I >> n;
        q = 0;
        V<V<ll>> a(n, V<ll>(n));
        F(i, 0, n - 1)
        {
            F(j, 0, n - 1)
            {
                I >> a[i][j];
            }
        }
        F(k, 1 - n, n - 1)
        {
            if (k >= 0)
            {
                i = 0;
                j = i + k;
            }
            else
            {
                j = 0;
                i = j - k;
            }
            ll m = LONG_LONG_MAX;
            while (j < n and i < n)
            {
                m = min(m, a[i][j]);
                ++i;
                ++j;
            }
            q -= m >= 0 ? 0 : m;
        }
        O << q << '\n';
    }
    return 0;
}
