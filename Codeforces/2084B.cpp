#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(), x.end()

// https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
unsigned gcd(unsigned ll u, unsigned ll v)
{
    auto shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do
    {
        v >>= __builtin_ctz(v);
        if (u > v)
            std::swap(u, v);
    } while ((v -= u));
    return u << shift;
}

ll findGCD(V<ll> &arr)
{
    ll i, res = arr[0];
    F(i, 1, arr.size() - 1)
    {
        res = gcd(arr[i], res);

        // If res becomes 1 at any iteration then it remains 1
        // So no need to check further
        if (res == 1)
            return 1;
    }
    return res;
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
        V<ll> a(n);
        F(i, 0, n - 1)
        {
            I >> a[i];
        }

        sort(all(a));

        ll m = a[0];

        if (a[1] == m)
        {
            O << "yes\n";
            continue;
        }

        q = 0;

        V<ll> b;

        F(i, 1, n - 1)
        {
            if (a[i] % m == 0)
            {
                ++q;
                b.pb(a[i]);
            }
        }

        O << (q > 0 and findGCD(b) == m ? "yes" : "no") << '\n';
    }
    return 0;
}
