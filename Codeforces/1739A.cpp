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
    ll t, n, m, ans;
    I >> t;
    while (t--)
    {
        I >> n >> m;
        O << n / 2 + 1 << ' ' << m / 2 + 1 << "\n";
    }
    return 0;
}
