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
    ll t, n, i, j, k;
    I >> t;
    while (t--)
    {
        I >> k >> n;
        V<ll> a(k);
        a[0] = 1;
        a[k - 1] = n;
        F(i, 1, k - 2)
        {
            j = a[i - 1] + i;
            if (n - j >= k - i - 1)
            {
                a[i] = j;
            }
            else
            {
                a[i] = n - k + i + 1;
            }
        }
        F(i, 0, k - 1)
            O << a[i] << ' ';
        O << '\n';
    }
    return 0;
}
