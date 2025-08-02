#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mmax(a, b, c) max(a, max(b, c))
#define mmin(a, b, c) min(a, min(b, c))
#define M 1000000007
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define umap unordered_map
#define mp make_pair
#define found(m, x) (m.find(x) != m.end())

bool isPowerOfTwo(ll x)
{
    return x && (!(x & (x - 1)));
}

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 6; i * i <= n; i += 6)
        if (n % (i - 1) == 0 || n % (i + 1) == 0)
            return false;
    return true;
}

// https://cp-algorithms.com/algebra/binary-exp.html#toc-tgt-3
ll binpow(ll a, ll b)
{
    a %= M;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

// https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
unsigned gcd(unsigned u, unsigned v)
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

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        int i, n, k, j;
        I >> n >> k;
        V<int> a(n);
        F(i, 0, n - 1)
        {
            I >> j;
            a[i] = j % k;
        }
        j = *min_element(all(a));
        if (j == 0 or k == 1)
        {
            O << "0\n";
            continue;
        }
        if (k == 2 or k == 3 or k == 5)
        {
            O << k - *max_element(all(a)) << '\n';
            continue;
        }
        int c1 = count(all(a), 1);
        int c2 = count(all(a), 2);
        int c3 = count(all(a), 3);
        if (c2)
        {
            O << (c2 > 1 ? 0 : 1);
        }
        else if (c3)
        {
            O << 1;
        }
        else
        {
            O << (i > 1 ? 2 : 3);
        }
        O << '\n';
    }
    return 0;
}
