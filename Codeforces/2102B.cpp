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
    ll t, n, q, i, j, k;
    I >> t;
    while (t--)
    {
        I >> n;
        V<ll> a(n);
        F(i, 0, n - 1)
        {
            I >> j;
            a[i] = abs(j);
        }

        q = a[0];

        sort(all(a));

        if ((n % 2 == 1 and q == a[n / 2]) or (n % 2 == 0 and q == a[n / 2 - 1]))
        {
            O << "YES\n";
            continue;
        }

        j = lower_bound(all(a), q) - a.begin();

        O << (j <= n / 2 ? "YES" : "NO") << '\n';
    }
    return 0;
}
