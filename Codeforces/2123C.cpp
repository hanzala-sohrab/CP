#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define all(x) x.begin(), x.end()

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, i, j, k;
    I >> t;
    while (t--)
    {
        I >> n;
        V<ll> a(n), b(n), c(n);
        F(i, 0, n - 1)
        {
            I >> a[i];

            if (i == 0)
            {
                b[0] = a[0];
            }
            else
            {
                b[i] = min(b[i - 1], a[i]);
            }
        }

        c[n - 1] = a[n - 1];

        for (i = n - 2; i >= 0; --i)
            c[i] = max(c[i + 1], a[i]);

        F(i, 0, n - 1)
        {
            O << (a[i] == b[i] or a[i] == c[i] ? 1 : 0);
        }
        O << '\n';
    }
    return 0;
}
