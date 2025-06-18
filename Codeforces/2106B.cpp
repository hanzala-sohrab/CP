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
    ll t, n, x, i, j;
    I >> t;
    while (t--)
    {
        I >> n >> x;

        j = 0;

        F(i, 0, n - 1)
        {
            if (i == x)
            {
                continue;
            }

            O << i << ' ';
            ++j;
        }

        if (j < n)
        {
            O << x;
        }

        O << '\n';
    }
    return 0;
}
