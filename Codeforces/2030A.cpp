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
    ll t, n, i, j;
    I >> t;
    while (t--)
    {
        I >> n;
        V<ll> a(n);
        F(i, 0, n - 1)
        {
            I >> a[i];
        }
        i = *max_element(a.begin(), a.end());
        j = *min_element(a.begin(), a.end());
        O << (n - 1) * (i - j) << '\n';
    }
    return 0;
}
