#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, m, q, p;
    I >> t;
    while (t--)
    {
        I >> n >> m >> p >> q;

        ll x = n / p;
        ll y = m - x * q;
        ll z = n - x * p;

        O << (z == 0 and y != 0 ? "NO" : "YES") << '\n';
    }
    return 0;
}
