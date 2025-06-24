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
        V<ll> res(2 * n);
        F(i, 0, n - 1)
        {
            F(j, 0, n - 1)
            {
                I >> k;
                res[i + j + 1] = k;
            }
        }
        k = 0;
        F(i, 0, 2 * n - 1)
        {
            k += res[i];
        }

        res[0] = 2 * n * n + n - k;

        F(i, 0, 2 * n - 1)
        {
            O << res[i] << ' ';
        }
        O << '\n';
    }
    return 0;
}
