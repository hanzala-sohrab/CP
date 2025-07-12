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
    ll t, n, q, i, j, k;
    I >> t;
    while (t--)
    {
        I >> n >> k;
        V<ll> a(n);
        q = 0;
        F(i, 0, n - 1)
        {
            I >> a[i];
            q += a[i];
        }

        ll M = *max_element(all(a));
        ll m = *min_element(all(a));

        ll cM = 0;
        F(i,0,n-1){
            if (a[i] == M) {
                ++cM;
            }
        }

        if (M - m - 1 > k or (M - m > k and cM > 1))
        {
            O << "Jerry\n";
        }
        else
        {
            O << (q & 1 ? "Tom" : "Jerry") << '\n';
        }
    }
    return 0;
}
