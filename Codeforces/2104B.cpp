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
    ll t, n, q, i, j, k;
    I >> t;
    while (t--)
    {
        I >> n;
        V<ll> a(n), b(n), c(n);
        F(i, 0, n - 1)
        {
            I >> a[i];
        }

        b[0] = a[0];

        F(i, 1, n - 1)
        {
            b[i] = max(a[i], b[i - 1]);
        }

        c[n - 1] = a[n - 1];

        for (i = n - 2; i >= 0; --i)
        {
            c[i] = a[i] + c[i + 1];
        }

        for (i = n - 1; i >= 0; --i)
        {
            O << c[i] + b[i] - a[i] << ' ';
        }

        O << '\n';
    }
    return 0;
}
