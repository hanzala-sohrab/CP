#include <bits/stdc++.h>
using namespace std;
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        long long int x, y, z, c, m;
        I >> x >> m;

        c = 0;

        m = min(m, 2 * x - 1);

        F(y, 1, m)
        {
            z = x ^ y;
            if (z and (x % z == 0 or y % z == 0))
                ++c;
        }

        O << c << '\n';
    }
    return 0;
}
