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
        V<ll> a(n);
        F(i, 0, n - 1)
        {
            I >> a[i];
        }

        q = LONG_LONG_MAX;

        i = 0;
        j = 1;

        while (i < n and j < n)
        {
            if (a[i] != a[j])
            {
                i = j - 1;
                q = min(q, min(a[i], a[j]) * (n - 1));
                ++i;
                ++j;
            }
            else
            {
                k = i * a[i] + (n - 1 - j) * a[j];
                q = min(q, k);
                ++j;
            }
        }

        O << q << '\n';
    }
    return 0;
}
