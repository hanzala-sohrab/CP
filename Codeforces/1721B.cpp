#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, i, j, X1, Y1, X2, Y2, m, n, sx, sy, d;
    I >> t;
    while (t--)
    {
        I >> n >> m >> sx >> sy >> d;
        X1 = sx - d;
        Y1 = sy - d;
        X2 = sx + d;
        Y2 = sy + d;
        ll ans = min(sx - 1, m - sy) <= d and min(n - sx, sy - 1) <= d ? -1 : m + n - 2;
        O << ans << '\n';
    }
    return 0;
}
