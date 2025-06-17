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
    ll t, n, i, j;
    I >> t;
    while (t--)
    {
        I >> n;
        set<ll> a;
        F(i, 0, n - 1)
        {
            I >> j;

            a.insert(j);
        }

        V<ll> b(all(a));

        ll ans = 1;

        ll m = b.size();

        i = 0;
        j = 1;

        while (i < m and j < m)
        {
            if (b[i] + 1 < b[j])
            {
                ++ans;
                i = j;
            }
            ++j;
        }

        O << ans << '\n';
    }
    return 0;
}
