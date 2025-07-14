#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

bool checkIsPerfectSquare(ll n)
{
    ll sq = sqrt(n);

    return n == sq * sq;
}

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, q, i, j, k;
    I >> t;
    while (t--)
    {
        I >> n;
        q = (n * n + n) / 2;

        if (checkIsPerfectSquare(q))
        {
            O << "-1\n";
            continue;
        }

        V<ll> a(n + 1, 0);

        F(i, 1, n)
        {
            a[i] = i;
        }

        q = 0;
        F(i, 1, n - 1)
        {
            q += a[i];
            if (checkIsPerfectSquare(q))
            {
                j = a[i + 1];
                a[i + 1] = a[i];
                a[i] = j;

                q += j;
                ++i;
            }
        }

        F(i, 1, n)
        {
            O << a[i] << ' ';
        }

        O << '\n';
    }
    return 0;
}
