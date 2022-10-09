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
    ll i, n, d, j, cnt = 0;
    I >> n >> d;
    V<ll> p(n);
    F(i, 0, n - 1)
    {
        I >> p[i];
    }
    sort(all(p), greater<ll>());
    j = n - 1;
    ll reqd, left = n;
    F(i, 0, j)
    {
        reqd = (d / p[i]) + 1;
        --left;
        left -= reqd - 1;
        if (left < 0)
            break;
        j -= reqd - 1;
        if (p[i] * reqd > d)
            ++cnt;
    }
    O << cnt << '\n';
    return 0;
}
