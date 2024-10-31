#include <bits/stdc++.h>
using namespace std;
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t, i, n, r;
    I >> t;
    while (t--)
    {
        I >> n >> r;
        int a, b = 0, c = 0, d = 0;
        F(i, 0, n - 1)
        {
            I >> a;
            d += a;
            b += a / 2;
            c += a % 2;
        }
        int ans = d - 2 * (c - (r - b));
        O << min(ans, d) << '\n';
    }
    return 0;
}
